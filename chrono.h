#ifndef CHRONO_H
#define CHRONO_H

#include"timer.h"

class Chrono : public Timer {
public:
    Chrono() : Timer(0, 0, 0), millisecond(0) {
        setHour(0);
        setMinute(0);
        setSecond(0);
        setMillisecond(0);
    }

    void setState() override;

    void setMillisecond(int ms);

    int getMillisecond() const {
        return millisecond;
    }

private:
    int millisecond;
};

#endif // CHRONO_H
