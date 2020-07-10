#include "chrono.h"




void Chrono::setState(){
  while(getHour() < 24){
    while(getMinute() < 60){
       while(getSecond() < 60){
            while(millisecond < 1000){
            getTimer()->start(1);
            millisecond++;
            }
       setSecond(getSecond() +1);
       millisecond = 0;
       }
    setMinute(getMinute() +1);
    setSecond(0);
   }
  setHour(getHour()+1);
  setMinute(0);
   }

 }



void Chrono::setMillisecond(int ms){
    getTimer()->setInterval(ms);
    notify();
}

