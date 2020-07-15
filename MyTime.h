#ifndef TIME_H
#define TIME_H

#include<QTime>


class Time {
public:
    Time(int h = 0, int m = 0, int s = 0, int ms = 0) : hour(h), minute(m), second(s), millisecond(ms) {
    }

    Time &operator+(const Time &right);

    Time &operator-(const Time &right);

    int getHour() const {
        return hour;
    }

    int getMinute() const {
        return minute;
    }

    int getSecond() const {
        return second;
    }

    int getMillisecond() const {
        return millisecond;
    }


private:
    int hour, minute, second, millisecond;
};

#endif // TIME_H
