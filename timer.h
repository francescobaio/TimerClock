#ifndef TIMER_H
#define TIMER_H

#include<subject.h>
#include<QTimer>
#include<QTime>


class Timer : public Subject,public QTime
{
public:
    Timer(QTimer * q,int h = 0,int m = 0,int s= 0);

    virtual ~Timer(){
        if(!(q->isActive()))
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
    QTimer* getTimer(){
        return q;
    }

    int getHour(){
        return hour;
    }

    int getMinute(){
        return minute;
    }

    int getSecond(){
        return second;
    }


private:
    int hour,minute,second;
    QTimer * q;
    std::list<Observer*> observers;

};

#endif // TIMER_H