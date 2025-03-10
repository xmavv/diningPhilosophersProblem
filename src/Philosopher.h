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
    vector<string> states;

public:
    Philosopher(int id, Fork &leftFork, Fork &rightFork, vector<string> states);
    void think();
    void eat();
    void exist();
};

#endif //UNTITLED4_PHILOSOPHER_H
