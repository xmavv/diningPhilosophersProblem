#include "./Philosopher.h"
#include <thread>

//needs to be like this because the address (reference) cannot be assign after constructor runs, reference cannot be null
Philosopher::Philosopher(int id, Fork &leftFork, Fork &rightFork): id(id), leftFork(leftFork), rightFork(rightFork) {
    if(id % 2 == 0) swap(leftFork, rightFork);
}

void Philosopher::think() {
    //TODO
    //jakis problem z tym cout sie blokuja naraz wszystkie threadsy

    cout << "philosopher " << id << " is thinking" << endl;
    this_thread::sleep_for(chrono::seconds (rand() % 5 + 1 ));
}

void Philosopher::eat() {
    //TODO
    //parzystosc i nieparzystosc

    while(true) {
        if(!leftFork.isTaken && !rightFork.isTaken) {
            leftFork.pickUpFork();
            rightFork.pickUpFork();
            break;
        }
    }

    cout << "philosopher " << id << " is eating" << endl;
    this_thread::sleep_for(chrono::seconds (rand() % 5 + 1 ));

    leftFork.putDownFork();
    rightFork.putDownFork();
}

void Philosopher::exist() {
    while (true) {
        think();
        eat();
    }
}