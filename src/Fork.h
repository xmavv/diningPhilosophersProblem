#ifndef SRC_FORK_H_
#define SRC_FORK_H_
#include <iostream>
#include <mutex>

using namespace std;

class Fork {
public:
    mutex mFork;
};

#endif //SRC_FORK_H_
