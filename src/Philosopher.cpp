#include "Philosopher.h"
#include <stdlib.h>
#include <thread>
#include <string>

void printDinner();

//needs to be like this because the address (reference) cannot be assign after constructor runs, reference cannot be null
Philosopher::Philosopher(int id, Fork& leftFork, Fork& rightFork)
        : id(id),
          leftFork(id % 2 == 0 ? leftFork : rightFork),
          rightFork(id % 2 == 1 ? leftFork : rightFork),
          currentState(2) {}

void Philosopher::think() {
    printState(0);
    this_thread::sleep_for(chrono::seconds(rand() % 5 + 1));
}

void Philosopher::eat() {
    printState(1);
    this_thread::sleep_for(chrono::seconds(rand() % 5 + 1));
}

void Philosopher::pickUpForks() {
    leftFork.mFork.lock();
    rightFork.mFork.lock();

    printState(5);
    this_thread::sleep_for(chrono::seconds(rand() % 1 + 1));
}

void Philosopher::putDownForks() {
    leftFork.mFork.unlock();
    rightFork.mFork.unlock();

    printState(7);
    this_thread::sleep_for(chrono::seconds(rand() % 1 + 1));
}

void Philosopher::exist() {
    while (true) {
        think();
        pickUpForks();
        eat();
        putDownForks();
    }
}

void Philosopher::printState(int state) {


    mPrint.lock();

    currentState = state;
    printDinner();

    mPrint.unlock();
}

int Philosopher::getId() {
    return id;
}

int Philosopher::getCurrentState() {
    return currentState;
}

string Philosopher::castCurrentState() {
    if(currentState == static_cast<int>(State::EAT)) return "eating";
    if(currentState == static_cast<int>(State::THINK)) return "thinking";
    if(currentState == static_cast<int>(State::EXIST)) return "existing";
    if(currentState == static_cast<int>(State::PICK_UP_FORK)) return "picking up forks";
    if(currentState == static_cast<int>(State::PUT_DOWN_FORK)) return "putting down forks";
}