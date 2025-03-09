#ifndef UNTITLED4_PHILOSOPHER_H
#define UNTITLED4_PHILOSOPHER_H
#include "./Fork.h"
#include <iostream>

using namespace std;

class Philosopher {
private:
    int id;
    Fork& leftFork;
    Fork& rightFork;

public:
    Philosopher(int id, Fork &leftFork, Fork &rightFork): id(id), leftFork(leftFork), rightFork(rightFork){};
    void think();
    void eat();
    void exist();

};

#endif //UNTITLED4_PHILOSOPHER_H
