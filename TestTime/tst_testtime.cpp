#include <QtTest>
#include <QCoreApplication>
#include"../MyTime.h"
#include"../MyTime.cpp"
#include"../timer.h"
#include"../timer.cpp"
#include"../chrono.h"
#include"../chrono.cpp"
#include"../clock.h"
#include"../clock.cpp"
#include<QTime>

// add necessary includes here

class TestTime : public QObject
{
    Q_OBJECT

public:
    TestTime(){}
    ~TestTime(){}

private slots:
    void test_time();

};




void TestTime::test_time()
{
   QTime q;
   Time t1(q.currentTime().hour(),q.currentTime().minute(),q.currentTime().second());
   Chrono cr;
   cr.getTimer()->start(9000);
   while(cr.getTimer()->remainingTime()){
   }
   qDebug() << "remaining" << cr.getTimer()->remainingTime();
   Time t2(q.currentTime().hour(),q.currentTime().minute(),q.currentTime().second());
   Time t3 = t2-t1;
   QCOMPARE(t3.getHour(),0);
   QCOMPARE(t3.getMinute(),0);
   QCOMPARE(t3.getSecond(),9);


}


QTEST_MAIN(TestTime)

#include "tst_testtime.moc"
