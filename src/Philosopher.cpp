#include "./Philosopher.h"
#include <thread>

const int numOfPhilosophers = 10;

void print(vector<string> states) {
    //clear console
    system("cls");

    for(int i=0; i<numOfPhilosophers; i++) {
        cout << "philosopher id " << i << "is: " << states[i] << endl;
    }
}

//needs to be like this because the address (reference) cannot be assign after constructor runs, reference cannot be null
Philosopher::Philosopher(int id, Fork &leftFork, Fork &rightFork, vector<string> states): id(id), leftFork(leftFork), rightFork(rightFork), states(states) {
    if(id % 2 == 0) swap(leftFork, rightFork);
}

void Philosopher::think() {
    //TODO
    //jakis problem z tym cout sie blokuja naraz wszystkie threadsy

    states[id] = "think";
    print(states);
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

    states[id] = "eat";
    print(states);
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