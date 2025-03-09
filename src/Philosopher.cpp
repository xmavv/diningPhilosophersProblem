#include "./Philosopher.h"
#include <thread>


void Philosopher::think() {
    //TODO
    //jakis problem z tym cout sie blokuja naraz wszystkie threadsy

    cout << "philosopher " << id << " is thinking" << endl;
    this_thread::sleep_for(chrono::seconds(rand() * 5 ));
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
    this_thread::sleep_for(chrono::seconds(rand() * 5 ));

    leftFork.putDownFork();
    rightFork.putDownFork();
}

void Philosopher::exist() {
    while (true) {
        think();
        eat();
    }
}