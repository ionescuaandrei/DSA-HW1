#include <string>

#ifndef OPERATION_H
#define OPERATION_H

struct Operation {
    int type;  // 0 for DELETE, 1 for INSERT
    int position;
    std::string text ;
};

#endif