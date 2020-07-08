#ifndef TIMER_H
#define TIMER_H


#include<QTimer>
#include<QLCDNumber>

class Timer : public QLCDNumber
{
    Q_OBJECT
public:
    Timer(QWidget * Q): QLCDNumber(Q){
        q = new QTimer;
    }

public slots:
    void getStarted();
    void getStopped();
    void setInterval();

private:
    QTimer * q;

};

#endif // TIMER_H
