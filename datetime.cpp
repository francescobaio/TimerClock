#include "datetime.h"


void DateTime::changeDateFormat() {
    dateCount++;
    setFormat();
}

void DateTime::changeTimeFormat() {
    timeCount++;
    setFormat();
}


void DateTime::setFormat() {
    if (dateCount % 3 == 0 && timeCount % 2 == 0)
        setDisplayFormat("dd/MM/yyyy hh:mm");
    else if (dateCount % 3 == 0 && timeCount % 2 == 1)
        setDisplayFormat("dd/MM/yyyy hh:mm AP");
    else if (dateCount % 3 == 1 && timeCount % 2 == 0)
        setDisplayFormat("dd.MM.yyyy hh:mm");
    else if (dateCount % 3 == 1 && timeCount % 2 == 1)
        setDisplayFormat("dd.MM.yyyy hh:mm AP");
    else if (dateCount % 3 == 2 && timeCount % 2 == 0)
        setDisplayFormat("d MMMM yyyy hh:mm");
    else if (dateCount % 3 == 2 && timeCount % 2 == 1)
        setDisplayFormat("d MMMM yyyy hh:mm AP");
}
