#include "timer.h"


void Timer::getStarted()
{
    q->start();

}


void Timer::getStopped(){
    q->stop();
}

void Timer::setInterval(){
    q->setInterval(intValue());
}










