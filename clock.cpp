#include "clock.h"



void Clock::update(){
   hour = t->getHour();
   minute = t->getMinute();
   second = t->getSecond();
    Chrono * q = dynamic_cast<Chrono*>(t);
    if(q)
        millisecond = q->getMillisecond();
}

void Clock::attach(){
  t->subscribe(this);
}

void Clock::detach(){
  t->unsubscribe(this);
}

