#include "./Philosopher.h"
#include <thread>

void printDinner();

//needs to be like this because the address (reference) cannot be assign after constructor runs, reference cannot be null
Philosopher::Philosopher(int id, Fork& leftFork, Fork& rightFork)
        : id(id),
          leftFork(id % 2 == 0 ? leftFork : rightFork),
          rightFork(id % 2 == 1 ? leftFork : rightFork),
          currentState(2) {}

void Philosopher::think() {
    printState(0);
    this_thread::sleep_for(chrono::seconds(2));
}

void Philosopher::eat() {
    //TODO
    //parzystosc i nieparzystosc

    printState(1);
    this_thread::sleep_for(chrono::seconds(2));
}

void Philosopher::pickUpForks() {
    leftFork.mFork.lock();
    rightFork.mFork.lock();

    printState(5);
    this_thread::sleep_for(chrono::seconds(2));
}

void Philosopher::putDownForks() {
    leftFork.mFork.unlock();
    rightFork.mFork.unlock();

    printState(7);
    this_thread::sleep_for(chrono::seconds(2));
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

    //TODO
    //1. dodac kolory jak w projekcie z algorytmow
    //2. no i teraz jakas globalna funkcja i wowczas wykorzystujemy ten static mutex do printowania zeby tylko jeden mogl naraz pisac
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