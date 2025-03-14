#ifndef UNTITLED4_PHILOSOPHER_H
#define UNTITLED4_PHILOSOPHER_H
#include "./Fork.h"
#include "./State.h"
#include <iostream>
#include <vector>

using namespace std;

class Philosopher {
private:
    int id;
    Fork& leftFork;
    Fork& rightFork;
    int currentState;
    static mutex mPrint;

public:
    Philosopher(int id, Fork &leftFork, Fork &rightFork);
    void think();
    void eat();
    void pickUpForks();
    void putDownForks();
    void exist();
    void printState(int state);

    int getId();
    int getCurrentState();
    string castCurrentState();
};

#endif //UNTITLED4_PHILOSOPHER_H
