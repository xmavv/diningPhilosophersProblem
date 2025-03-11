#ifndef UNTITLED4_PHILOSOPHER_H
#define UNTITLED4_PHILOSOPHER_H
#include "./Fork.h"
#include <iostream>
#include <vector>

using namespace std;

class Philosopher {
private:
    int id;
    Fork& leftFork;
    Fork& rightFork;
    string currentState;
    static mutex mPrint;

public:
    Philosopher(int id, Fork &leftFork, Fork &rightFork);
    void think();
    void eat();
    void pickUpForks();
    void putDownForks();
    void exist();
    void printState(string state);
};

#endif //UNTITLED4_PHILOSOPHER_H
