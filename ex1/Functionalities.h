#include "../ds/mystack.h"
#include "../ex1/Operation.h"


using namespace std;

class Functionalities {
private:
    Operation operation;




public:

    void insert_(string &s, Operation op) {
        s.insert(op.position, op.text);
    }



    Functionalities() {

    };


};

