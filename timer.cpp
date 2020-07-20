#include "timer.h"
#include<QTimer>



Timer::Timer(int h, int m, int s) : hour(h), minute(m), second(s) {
    q = new QTimer;
    q->setTimerType(Qt::PreciseTimer);
}

void Timer::notify() {
    for (auto obs : observers)
        obs->update();
}


void Timer::subscribe(Observer *o) {
    observers.push_back(o);
}

void Timer::unsubscribe(Observer *o) {
    observers.remove(o);
}


void Timer::setSecond(int s) {
    second = s;
    notify();
}

void Timer::setMinute(int m) {
    minute = m;
    notify();
}

void Timer::setHour(int h) {
    hour = h;
    notify();
}



void Timer::setTimer(){
    if(second || minute || hour){
        if(second)
            second--;
        else{
            second = 59;
            if(minute)
            minute--;
        else{
            minute = 59;
            if(hour)
                hour --;
        }
    }

    notify();
 }else{
        q->stop();
    }
}









