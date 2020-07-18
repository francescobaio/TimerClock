#ifndef DATETIME_H
#define DATETIME_H

#include <QDateTimeEdit>
#include<QDateTime>


class DateTime : public QDateTimeEdit, public QDateTime {
    Q_OBJECT

public:
    DateTime(QWidget *Q) : QDateTimeEdit(Q) {
        QDateTimeEdit::setDateTime(currentDateTime());
        setDisabled(true);
    }

public
    slots:
            void

    changeTimeFormat();

    void changeDateFormat();

private:
    void setFormat();

    int dateCount = 0;
    int timeCount = 0;
};

#endif // DATETIME_H
