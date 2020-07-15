#include <QtTest>
#include <QCoreApplication>
#include"MyTime.h"
#include"MyTime.cpp"
#include"timer.h"
#include"timer.cpp"
#include"chrono.h"
#include"chrono.cpp"
#include"clock.h"
#include"clock.cpp"
#include<QTime>

// add necessary includes here

class TestMyTime : public QObject
{
    Q_OBJECT

public:
    TestMyTime(){}
    ~TestMyTime(){}

private slots:
    void test_time();

};




void TestMyTime::test_time()
{
   QTime q;
   Time t1(q.currentTime().hour(),q.currentTime().minute(),q.currentTime().second());
   Chrono cr;
   cr.getTimer()->start(10000);
   while(cr.getTimer()->remainingTime()){
   }
   qDebug() << "remaining" << cr.getTimer()->remainingTime();
   Time t2(q.currentTime().hour(),q.currentTime().minute(),q.currentTime().second());
   Time t3 = t2-t1;
   QCOMPARE(t3.getHour(),0);
   QCOMPARE(t3.getMinute(),0);
   QCOMPARE(t3.getSecond(),10);


}


QTEST_MAIN(TestMyTime)

#include "tst_testmytime.moc"
