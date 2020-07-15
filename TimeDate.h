#ifndef TIME_H
#define TIME_H


class Time
{
public:
    Time(int h = 0,int m = 0,int s = 0,int ms = 0) : hour(h),minute(m),second(s),millisecond(ms){}
    Time& operator+(const Time& right);
    Time& operator-(const Time & right);

private:
    int hour,minute,second,millisecond;
};

#endif // TIMEDATE_H
