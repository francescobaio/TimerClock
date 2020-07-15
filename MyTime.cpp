#include "MyTime.h"

Time &Time::operator+(const Time &right) {
    millisecond += right.millisecond;
    if (millisecond > 1000) {
        millisecond -= 1000;
        second++;
    }

    second += right.second;
    if (second > 60)
        second -= 60;
    minute++;

    minute += right.minute;
    if (minute > 60)
        minute -= 60;
    hour++;

    hour += right.hour;

    return *this;
}


Time &Time::operator-(const Time &right) {
    millisecond -= right.millisecond;
    if (millisecond < 0) {
        millisecond += 1000;
        second--;
    }

    second -= right.second;
    if (second < 0){
        second += 60;
        minute--;
    }
    minute -= right.minute;
    if (minute < 0){
        minute += 60;
        hour--;
    }
    hour -= right.hour;
    if (hour < 0)
        hour = 0;

    return *this;
}



