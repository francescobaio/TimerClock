#include <QtTest>
#include <QCoreApplication>
#include"../timer.h"
#include"../timer.cpp"
#include"../clock.h"
#include"../clock.cpp"
#include"../chrono.h"
#include"../chrono.cpp"

// add necessary includes here

class TestTimer : public QObject {
    Q_OBJECT

public:
    TestTimer() {}

    ~TestTimer() {}

private
    slots:
            void

    test_timer();

};

void TestTimer::test_timer() {
    Timer t(0, 0, 10);
    Clock c(&t);
    t.setState();
    QCOMPARE(t.getSecond(), 0);
    QCOMPARE(c.getSecond(), 0);
}


QTEST_MAIN(TestTimer)

#include "tst_testtimer.moc"
