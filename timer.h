#ifndef TIMER_H
#define TIMER_H

#include"subject.h"
#include<QTimer>


class Timer : public Subject {
public:
    Timer( int h = 0, int m = 0, int s = 0);

    virtual ~Timer() {
        if (!(q->isActive()))
            q->stop();
        delete q;
    }

    void notify() override;

    void subscribe(Observer *o) override;

    void unsubscribe(Observer *o) override;

    virtual void setState();

    void setHour(int h);

    void setMinute(int m);

    void setSecond(int s);

    QTimer *getTimer() const {
        return q;
    }

    int getHour() const {
        return hour;
    }

    int getMinute() const {
        return minute;
    }

    int getSecond() const {
        return second;
    }


private:
    int hour, minute, second;
    QTimer *q;
    std::list<Observer *> observers;

};

#endif // TIMER_H
