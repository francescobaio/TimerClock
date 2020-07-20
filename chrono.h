#ifndef CHRONO_H
#define CHRONO_H

#include"timer.h"

class Chrono : public Timer {
    Q_OBJECT
public:
    Chrono();

    virtual ~Chrono() {}

    void setMillisecond(int ms);

    int getMillisecond() const {
        return millisecond;
    }

public
    slots:
            void

    setChrono();

private:
    int millisecond;
};

#endif // CHRONO_H
