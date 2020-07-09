#ifndef CLOCK_H
#define CLOCK_H

#include<Observer.h>
#include<QLCDNumber>
#include<timer.h>


class Clock : public Observer,public QLCDNumber
{
    Q_OBJECT
public:
    Clock(QWidget * Q,Timer * tm) : QLCDNumber(Q),t(tm){
        attach();
    }
    ~Clock(){
        detach();
    }

    void update() override;
    void attach() override;
    void detach() override;
public slots:
    void startTimer();

private:
    Timer * t;

};

#endif // CLOCK_H
