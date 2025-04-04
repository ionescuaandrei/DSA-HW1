#include <iostream>
#include "Operation.h"
//#include "../ds/mystack.h"
#include "Functionalities.h"
#include <cstring>
using namespace std;

int query_reader(const string& s) {  // this functions returns the query type
    if (s == "INSERT") return 1;
    if (s == "DELETE") return 0;
    if (s == "UNDO") return 3;
    if (s == "REDO") return 4;
    return -1;
}

void tokenize_string(string s, Operation &op) { // this functions tokenize the strings, splitting by words and storing each in an attribute

    char *copy = s.data();
    char *p = strtok(copy, " ");
    op.type = query_reader(p);
   p = strtok(nullptr, " ");
    op.position = atoi(p);
    p = strtok(nullptr, " ");
   op.text = p;
}


int main() {

    Operation test;
    Functionalities functionality;
    string s;
    string query;
    getline(cin, query);


    tokenize_string(query, test);


    functionality.insert_(s, test);

    cout << s;











       return 0;
}