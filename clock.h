#ifndef CLOCK_H
#define CLOCK_H

#include"Observer.h"
#include"timer.h"
#include"chrono.h"


class Clock : public Observer {
public:
    Clock() {}

    Clock(Timer *tm, int h = 0, int m = 0, int s = 0, int ms = 0) : t(tm), hour(h), minute(m), second(s),
                                                                    millisecond(ms) {
        attach();
    }

    ~Clock() {
        detach();
    }

    void update() override;

    void attach() override;

    void detach() override;

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

    void setHour(int h) {
        hour = h;
    }

    void setMinute(int m) {
        minute = m;
    }

    void setSecond(int s) {
        second = s;
    }


private:
    Timer *t;
    int hour, minute, second, millisecond;

};

#endif // CLOCK_H
