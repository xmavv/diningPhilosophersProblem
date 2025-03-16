#ifndef SRC_PHILOSOPHER_H_
#define SRC_PHILOSOPHER_H_
#include "Fork.h"
#include "State.h"
#include <vector>
#include <iostream>
#include <string>

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

#endif //SRC_PHILOSOPHER_H_
