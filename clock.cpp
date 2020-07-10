#include "clock.h"


void Clock::update(){
    if(t->getSecond() >= 60){
        t->setMinute(t->getMinute() + 1);
        t->setSecond(t->getSecond() - 60);
    }
    if(t->getMinute() >= 60)
        t->setHour(t->getHour() + 1);
        t->setMinute(t->getMinute() - 60);
}

void Clock::attach(){
  t->subscribe(this);
}

void Clock::detach(){
  t->unsubscribe(this);
}

void Clock::startTimer(){
    t->getTimer()->start();
}
