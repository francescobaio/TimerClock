#include "timer.h"
#include<QTimer>


void Timer::notify() {
    for (auto obs : observers)
        obs->update();
}

void Timer::setState() {
    while (second || minute || hour) {
        while (second >= 0) {
            q->start(1000);
            while (q->remainingTime()) {
            }
            second--;
            notify();
        }
        second = 0;
        if (minute) {
            minute--;
            second = 59;
            notify();

        } else if (hour) {
            hour--;
            minute = 59;
            second = 59;
            notify();
        }
    }
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


void Timer::subscribe(Observer *o) {
    observers.push_back(o);
}

void Timer::unsubscribe(Observer *o) {
    observers.remove(o);
}


Timer::Timer(int h, int m, int s) : hour(h), minute(m), second(s) {
    q = new QTimer;
    q->setSingleShot(true);
    setSecond(s);
    setMinute(m);
    setHour(h);
}









