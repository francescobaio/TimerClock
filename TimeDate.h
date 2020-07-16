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
private:
   std::string dateTime;
   std::list<Button*> buttons;

};

#endif // TIMEDATE_H
