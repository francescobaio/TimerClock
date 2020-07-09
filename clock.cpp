#include "clock.h"


void Clock::update(){

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
