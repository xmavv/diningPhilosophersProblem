#include "./Fork.h"

void Fork::pickUpFork() {
    isTaken = true;
}

void Fork::putDownFork() {
    isTaken = false;
}