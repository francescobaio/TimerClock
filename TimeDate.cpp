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
    for (auto but : buttons)
        this->dateTime = but->getFormat();
}
