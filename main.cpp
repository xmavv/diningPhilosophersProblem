#include <iostream>
#include <vector>
#include <thread>

#include "src/Philosopher.h"
#include "src/Fork.h"
const int numOfPhilosophers = 10;
vector<string> states(numOfPhilosophers, "living");

int main() {
    vector<Philosopher> philosophers;
    vector<Fork> forks(numOfPhilosophers);
    vector<thread> threads;

    for(int i=0; i<numOfPhilosophers; i++) {
        int left = i;
        int right = (i+1)%numOfPhilosophers;
        //assign forks to the philosophers
        philosophers.emplace_back(i, forks[left], forks[right], states);
    }

    for(int i=0; i<numOfPhilosophers; i++) {
        //assign threads to the philosophers
        threads.emplace_back(&Philosopher::exist, philosophers[i]);
    }

    for(int i=0; i<numOfPhilosophers; i++) {
        //block main untill thread lives
        threads[i].join();
    }

    return 0;
}
