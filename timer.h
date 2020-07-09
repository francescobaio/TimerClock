#ifndef TIMER_H
#define TIMER_H

#include<subject.h>
#include<QTimer>
#include<QDateTimeEdit>
#include<QLCDNumber>
#include<QTime>
#include<QProgressBar>


class Timer : public Subject,public QTimer,public QTime
{
public:
    Timer(QTimer * q,int h = 0,int m = 0,int s= 0);

    virtual ~Timer(){
        if(!isActive())
            q->stop();
        delete q;
    }
    void notify() override;
    void subscribe(Observer *o) override;
    void unsubscribe(Observer *o) override;
    void setState();
    void setHour(int h);
    void setMinute(int m);
    void setSecond(int s);
    QTimer* getTimer(){
        return q;
    }



private:
    int hour,minute,second;
    QTimer * q;
    std::list<Observer*> observers;

};

#endif // TIMER_H
