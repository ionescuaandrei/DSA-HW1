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

    string checkDeleteText(Operation op) {
        for (int i=0;i<op.text.length();++i) {
            if ((int)op.text[i] <48 || (int)op.text[i]>57) {return "WORDS";}
        }
        return "DIGITS";
    }


    void insert_(string &s, Operation op, Stack<Operation> &undoStack) {
        s.insert(op.position, op.text);
        undoStack.push(op);
    }
    void delete_ (string &s, Operation op, Stack<Operation> &undoStack) {

        if (checkDeleteText(op) == "DIGITS") {

            Operation temporary;
            for (int i=op.position;i<atoi(op.text.c_str())+op.position;++i) temporary.text = temporary.text + s[i];
            s.erase(op.position, atoi(op.text.c_str()));
            op.text = temporary.text;
            undoStack.push(op);
        }
        else {
            s.erase(op.position, op.text.length());
            undoStack.push(op);
        }
    }

    void undo(string &s, Stack<Operation> &undoStack, Stack<Operation> &redoStack) {
        Operation top = undoStack.peek();
        if (top.type == 1) {
            delete_(s, top, redoStack);
            undoStack.pop();
        }
        else if (top.type == 0) {
            insert_(s, top, redoStack);
            undoStack.pop();
        }
        else cout << "ERORR - UNDO IS NOT ON TYPE 1 OR 2 / THE STACK IS EMPTY";
    }

    void redo( string &s, Stack<Operation> &undoStack, Stack<Operation> &redoStack) {
        Operation top = redoStack.peek();
        if (top.type == 1) {
            insert_(s, top, undoStack);
            redoStack.pop();
        }
        else if (top.type == 0) {
            delete_(s, top, undoStack);
            redoStack.pop();
        }
        else cout << "ERROR - REDO IS NOT ON TYPE 1 OR 2 // THE STACK IS EMPTY";
    }




    Functionalities() {

    };


};

