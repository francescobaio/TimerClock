#include "button.h"

void Button::subscribe(Observer *o){
    this->o = o;
}

void Button::unsubscribe(Observer *o){
    delete o;
}

void Button::notify(){
    o->update();
}


void  Button ::changeDateFormat() {
    dateCount++;
    setFormat();
    notify();
}

void Button ::changeTimeFormat() {
    timeCount++;
    setFormat();
    notify();
}


void Button::setFormat() {
    if (dateCount % 3 == 0 && timeCount % 2 == 0)
        dateTime = "dd/MM/yyyy hh:mm";
    else if (dateCount % 3 == 0 && timeCount % 2 == 1)
        dateTime = "dd/MM/yyyy hh:mm AP";
    else if (dateCount % 3 == 1 && timeCount % 2 == 0)
        dateTime ="dd.MM.yyyy hh:mm";
    else if (dateCount % 3 == 1 && timeCount % 2 == 1)
        dateTime = "dd.MM.yyyy hh:mm AP";
    else if (dateCount % 3 == 2 && timeCount % 2 == 0)
        dateTime = "d MMMM yyyy hh:mm";
    else if (dateCount % 3 == 2 && timeCount % 2 == 1)
        dateTime = "d MMMM yyyy hh:mm AP";
}
