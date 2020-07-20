#include "chrono.h"





Chrono::Chrono(){
    millisecond = 0;
    QObject::connect(getTimer(),SIGNAL(timeout()),this,SLOT(setChrono()));
}


void Chrono::setMillisecond(int ms) {
    millisecond = ms;
    notify();
}

void Chrono::setChrono(){
   if(millisecond < 1000)
       millisecond++;
   else{
       millisecond = 0;
       if(second < 60)
           second++;
       else{
           second = 0;
           if(minute < 60)
               minute++;
           else{
               minute = 0;
               if(hour < 24)
                   hour++;
                }
           }
   }

   notify();
}




