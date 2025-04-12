#include "../ds/mystack.h"
#include "../ex1/Operation.h"


using namespace std;

class Functionalities {
private:
    Operation operation;


   bool isCharRemoved(string s) {
     for (int i=0;i<s.length();++i) {
         if ((int)s[i] <49 || (int)s[i]>57) {return false;}
     }
       return true;
   }


public:



    int query_reader(const string& s) {  // this functions returns the query type
        if (s == "INSERT") return 1;
        if (s == "DELETE") return 0;
        if (s == "UNDO") return 3;
        if (s == "REDO") return 4;
        return -1;
    }


    void insert_(string &s, Operation op, Stack<Operation> &undoStack) {
        s.insert(op.position, op.text);
        undoStack.push(op);
    }
    void delete_ (string &s, Operation op, Stack<Operation> &undoStack) {
        if (isCharRemoved(op.text)) {  // verify if the op.text is a number/digit
            string temporary;
            for (int i=op.position; i<op.position+atoi(op.text.c_str());++i) {
               temporary += s[i];  // putting in a variable the string that is to be deleted (for undostack)
            }
            s.erase(op.position, atoi(op.text.c_str()));
            op.text = temporary;
            undoStack.push(op);
        }
        else cout << "Usage: OPERATION INDEX NUMBER_OF_CHARS" << endl;
    }

    void undo(string &s, Stack<Operation> &undoStack, Stack<Operation> &redoStack) {
        Operation temporary = undoStack.peek();
        if (temporary.type == 1) {
            itoa(temporary.text.length(), temporary.text.data(), 10);
             delete_(s, temporary, undoStack);
        }
        else if (temporary.type == 0){
            insert_(s, temporary, undoStack);
        }
        redoStack.push(temporary);
        undoStack.pop();
    }

    void redo( string &s, Stack<Operation> &undoStack, Stack<Operation> &redoStack) {
        Operation temporary = redoStack.peek();

        if (temporary.type == 1) {
                   insert_(s, temporary, undoStack);
        }
        else if (temporary.type == 0) {
            temporary.text = itoa(temporary.text.length(), temporary.text.data(), 10);
            delete_(s, temporary, undoStack);
        }
        undoStack.push(temporary);
        redoStack.pop();
    }




    Functionalities() {

    };


};

