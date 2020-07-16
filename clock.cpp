#include "clock.h"


void Clock::update() {
    if (t->getSecond() >= 0) {
        hour = t->getHour();
        minute = t->getMinute();
        second = t->getSecond();
    } else {
        second = 0;
    }
    Chrono *q = dynamic_cast<Chrono *>(t);
    if (q)
        millisecond = q->getMillisecond();
}

void Clock::attach() {
    t->subscribe(this);
}

void Clock::detach() {
    t->unsubscribe(this);
}

