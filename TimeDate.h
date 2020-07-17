#ifndef TIMEDATE_H
#define TIMEDATE_H


#include"Observer.h"
#include"button.h"
#include<list>
#include<string>



class TimeDate : public Observer {
public:
    TimeDate(){
        attach();
    }
    ~TimeDate(){
        detach();
    }
   void attach() override;
   void detach() override;
   void update() override;


   int getTimeCount(){
       return timeCount;
   }
   int getDateCount(){
       return dateCount;
   }

   std::string getFormat(){
       return dateTime;
   }


   void setDateCount(int dc){
       this->dateCount = dc;
   }

   void setTimeCount(int tc){
       this->timeCount = tc;
   }
   void setFormat();


private:
   std::string dateTime;
   std::list<Button*> buttons;
   int timeCount = 0;
   int dateCount = 0;
};

#endif // TIMEDATE_H
