#include "button.h"


void Button::subscribe(Observer *o) {
    this->o = o;
}

void Button::unsubscribe(Observer *o) {
    delete o;
}

void Button::notify() {
    o->update();
}



