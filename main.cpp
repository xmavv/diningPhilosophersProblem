#include <vector>
#include <thread>
#include "src/Philosopher.h"
#include "src/Fork.h"
#include "src/State.h"

#include <iostream>
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#undef BYTE
#undef WORD
#undef DWORD
#include <windows.h>

int colorOutput(int state) {
    if(state == static_cast<int>(State::EAT)) return 12;
    if(state == static_cast<int>(State::THINK)) return 7;
    if(state == static_cast<int>(State::EXIST)) return 14;
    if(state == static_cast<int>(State::PICK_UP_FORK)) return 9;
    if(state == static_cast<int>(State::PUT_DOWN_FORK)) return 11;
}

mutex Philosopher::mPrint;
vector<Philosopher>* pPilosophers = nullptr;

void printDinner() {
    //clear console
    system("cls");

    //needs to be a reference not a copy...
    for(auto& philosopher: *pPilosophers) {
        cout << "philosopher ";

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorOutput(philosopher.getCurrentState()));
        cout << philosopher.getId();

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << " is ";

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorOutput(philosopher.getCurrentState()));
        cout << philosopher.castCurrentState() << endl;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
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
