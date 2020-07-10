#include "timer.h"


void Timer::notify(){
 for(auto obs : observers)
     obs->update();
}

void Timer::setState(){
    while(second || minute || hour){
        q->start(1000);
        while(q->isActive()){
        }
    second--;
    notify();
    }
}


void Timer::setSecond(int s){
    q->setInterval(s * 1000);
    notify();
}

void Timer::setMinute(int m){
    q->setInterval(m * 60000);
    notify();
}

void Timer::setHour(int h){
    q->setInterval(h * 3600000);
    notify();
}


void Timer::subscribe(Observer * o){
    observers.push_back(o);
}

void Timer::unsubscribe(Observer *o){
    observers.remove(o);
}


Timer::Timer(QTimer * q,int h ,int m ,int s) : hour(h),minute(m),second(s){
  q = new QTimer;
  setSecond(s);
  setMinute(m);
  setHour(h);
  q->start();
}






