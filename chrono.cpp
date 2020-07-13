#include "chrono.h"




void Chrono::setState(){
  while(getHour() < 24){
    while(getMinute() < 60){
       while(getSecond() < 60){
            while(millisecond < 1000){
                getTimer()->start(1);
                while(getTimer()->isActive()){
                }
                millisecond++;
                notify();
            }
       setSecond(getSecond() +1);
       millisecond = 0;
       notify();
       }
    setMinute(getMinute() +1);
    setSecond(0);
    notify();
   }
  setHour(getHour()+1);
  setMinute(0);
  notify();
   }

 }



void Chrono::setMillisecond(int ms){
    millisecond = ms;
    notify();
}



