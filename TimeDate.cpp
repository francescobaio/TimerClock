#include"TimeDate.h"


void TimeDate::attach(){
    for(auto but : buttons)
        but->subscribe(this);
}

void TimeDate::detach(){
    for(auto but : buttons)
        but->unsubscribe(this);
}


void TimeDate::update(){
      setFormat();
}


void TimeDate::setFormat() {
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
