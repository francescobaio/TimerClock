#ifndef CLOCK_H
#define CLOCK_H

#include<Observer.h>
#include<timer.h>
#include"chrono.h"


class Clock : public Observer
{
public:
    Clock(Timer * tm,int h,int m,int s,int ms) : t(tm),hour(h),minute(m),second(s),millisecond(ms){
        attach();
    }
    ~Clock(){
        detach();
    }

    void update() override;
    void attach() override;
    void detach() override;
    int getHour(){
        return hour;
    }
    int getMinute(){
        return minute;
    }
    int getSecond(){
        return second;
    }

    void setHour(int h){
        hour = h;
    }

    void setMinute(int m){
        minute = m;
    }

    void setSecond(int s){
        second = s;
    }


private:
    Timer * t;
    int hour,minute,second,millisecond;

};

#endif // CLOCK_H
