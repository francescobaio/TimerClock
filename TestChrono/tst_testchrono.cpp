#include <QtTest>
#include <QCoreApplication>
#include<../timer.h>
#include<../timer.cpp>
#include"../chrono.h"
#include"../chrono.cpp"
#include"../clock.h"
#include"../clock.cpp"

// add necessary includes here

class TestChrono : public QObject
{
    Q_OBJECT

public:
    TestChrono(){}
    ~TestChrono(){}

private slots:
    void test_chrono();

};




void TestChrono::test_chrono()
{
        Chrono cr;
        Clock c(&cr);
        cr.setHour(23);
        cr.setMinute(59);
        cr.setSecond(59);
        cr.setMillisecond(0);
        cr.setState();
        QCOMPARE(cr.getHour(),24);
        QCOMPARE(c.getHour(),24);
        QCOMPARE(cr.getMinute(),0);
        QCOMPARE(c.getMinute(),0);
        QCOMPARE(cr.getSecond(),0);
        QCOMPARE(c.getSecond(),0);
        QCOMPARE(cr.getMillisecond(),0);
        QCOMPARE(c.getMillisecond(),0);

}

QTEST_MAIN(TestChrono)

#include "tst_testchrono.moc"
