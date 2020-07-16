#ifndef BUTTON_H
#define BUTTON_H

#include"subject.h"
#include<list>
#include<string>
#include<QDateTime>


class Button : public Subject
{
public:
    Button(Observer * o){
       this->o = o;
    }
    void notify() override;
    void subscribe(Observer *o) override;
    void unsubscribe(Observer *o) override;
    void changeTimeFormat();
    void changeDateFormat();
    std::string getFormat(){
        return dateTime;
    }


private:
    void setFormat();
    int timeCount = 0;
    int dateCount = 0;
    std::string dateTime;
    Observer * o;
};

#endif // BUTTON_H
