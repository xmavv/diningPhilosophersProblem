#ifndef SRC_STATE_H_
#define SRC_STATE_H_
#include <stdio.h>
#include <iostream>

enum class State: int {
    EAT = 1,
    THINK = 0,
    EXIST = 2,
    PICK_UP_FORK = 5,
    PUT_DOWN_FORK = 7,
};

#endif //SRC_STATE_H_
