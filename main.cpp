#include <vector>
#include <thread>
#include "src/Philosopher.h"
#include "src/Fork.h"

mutex Philosopher::mPrint;
vector<Philosopher>* pPilosophers = nullptr;

void printDinner() {
    //clear console
    system("cls");

    //needs to be a reference not a copy...
    for(auto& philosopher: *pPilosophers) {
        cout << "philosopher " << philosopher.getId()<< "is " << philosopher.getCurrentState() << endl;
    }
}

int main() {
    const int numOfPhilosophers = 10;

    vector<Philosopher> philosophers;
    vector<Fork> forks(numOfPhilosophers);
    vector<thread> threads;

    for(int i=0; i<numOfPhilosophers; i++) {
        int left = i;
        int right = (i+1)%numOfPhilosophers;
        //assign forks to the philosophers
        philosophers.emplace_back(i, forks[left], forks[right]);
    }

    pPilosophers = &philosophers;

    for(auto& philosopher: philosophers) {
        //assign threads to the philosophers
        threads.emplace_back(&Philosopher::exist, &philosopher);
    }

    for(int i=0; i<numOfPhilosophers; i++) {
        //block main untill thread lives
        threads[i].join();
    }

    return 0;
}
