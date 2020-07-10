#ifndef CLOCK_H
#define CLOCK_H

#include<Observer.h>
#include<QLCDNumber>
#include<timer.h>


class Clock : public Observer,public QLCDNumber
{
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
private:
    Timer * t;

};

#endif // CLOCK_H
