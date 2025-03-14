#include "./Philosopher.h"
#include <thread>

void printDinner();

//needs to be like this because the address (reference) cannot be assign after constructor runs, reference cannot be null
Philosopher::Philosopher(int id, Fork& leftFork, Fork& rightFork)
        : id(id),
          leftFork(id % 2 == 0 ? leftFork : rightFork),
          rightFork(id % 2 == 1 ? leftFork : rightFork),
          currentState("existing") {}

void Philosopher::think() {
    printState("thinking");
    this_thread::sleep_for(chrono::seconds(2));
}

void Philosopher::eat() {
    //TODO
    //parzystosc i nieparzystosc

    printState("eating");
    this_thread::sleep_for(chrono::seconds(2));
}

void Philosopher::pickUpForks() {
    leftFork.mFork.lock();
    rightFork.mFork.lock();

    printState("picked up forks");
    this_thread::sleep_for(chrono::seconds(2));
}

void Philosopher::putDownForks() {
    leftFork.mFork.unlock();
    rightFork.mFork.unlock();

    printState("put down forks");
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

void Philosopher::printState(string state) {


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

string Philosopher::getCurrentState() {
    return currentState;
}