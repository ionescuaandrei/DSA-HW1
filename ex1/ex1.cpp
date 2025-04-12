#include <iostream>
#include "Operation.h"
//#include "../ds/mystack.h"
#include "Functionalities.h"
#include <cstring>
using namespace std;
Stack<Operation> undoStack;
Stack<Operation> redoStack;
/*int query_reader(const string& s) {  // this functions returns the query type
    if (s == "INSERT") return 1;
    if (s == "DELETE") return 0;
    if (s == "UNDO") return 3;
    if (s == "REDO") return 4;
    return -1;
}*/

int tokenize_string(string s, Operation &op) { // this functions tokenize the strings, splitting by words and storing each in an attribute
    Functionalities temp;
    int cnt =0;

    char *copy = s.data();
    char *p = strtok(copy, " ");
    if (p == nullptr) {
        return -1;
    }
    op.type = temp.query_reader(p);
   p = strtok(nullptr, " ");
    if (p == nullptr) {
        return -2;
    }
    op.position = atoi(p);
    p = strtok(nullptr, " ");
    if (p == nullptr) {
        return -1;
    }
   op.text = p;
    return 1;
}

void check(string &s, Operation op) {
    Functionalities temporary;
    if (op.type == 1) {
        temporary.insert_(s, op, undoStack);
    }
    else if (op.type == 0) {
        temporary.delete_(s, op, undoStack);
    }

}


int main() {

    Operation test;
    Functionalities functionality;
    string s;
    string query;

    while (true) {

    //   if (!undoStack.isEmpty()) cout << "UNDOSTACK: "<< undoStack.peek().type << " " << undoStack.peek().position << " " << undoStack.peek().text << endl;
     //   if (!redoStack.isEmpty())   cout << "REDOSTACK: " << redoStack.peek().type << " " << redoStack.peek().position << " " << redoStack.peek().text << endl;
        getline(cin, query);
        if (query == "exit") return 0;
       if ( tokenize_string(query, test)  == -1 ) {
           cout << "Invalid input" << endl;
           return 0;
       }
        if (tokenize_string(query, test) == -2) {
            if (test.type == 3) {
               functionality.undo(s, undoStack, redoStack);
             //   cout <<"DID UNDO";
                cout << s << endl;
            }
            else if (test.type == 4) {
               functionality.redo(s, undoStack, redoStack);
              //  cout << "DID REDO";
                cout << s << endl;
            }
            else {
                cout << "INVALID OPERATION - IF 1 OPERATION, IT MUST BE UNDO/REDO" << endl;
                return 0;
            }
        }
        else {
            check(s, test);
            cout << s << endl;
        }
    }


  /*  getline(cin, query);
    tokenize_string(query, test);
    check(s, test);

    cout << s << endl;

    getline(cin, query);
    tokenize_string(query, test);
    check(s, test);
    cout << s << endl;

   functionality.undo(s, undoStack, redoStack);
    cout << s << endl;

    functionality.redo(s, redoStack, undoStack);
    cout << s << endl;
*/






       return 0;
}