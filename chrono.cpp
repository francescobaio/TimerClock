#include "chrono.h"


void Chrono::setState() {
    getTimer()->start(1);
    while (getTimer()->remainingTime()) {
    }
    millisecond++;
    notify();
}


void Chrono::setMillisecond(int ms) {
    millisecond = ms;
    notify();
}



