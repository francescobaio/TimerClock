#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"button.h"
#include"TimeDate.h"
#include"timer.h"
#include"clock.h"
#include"chrono.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
      private
        slots:


         void on_pushButton_5_clicked();

         void on_pushButton_clicked();

        void on_pushButton_2_clicked();


        void on_pushButton_4_clicked();

        void on_pushButton_6_clicked();

        void on_spinBox_valueChanged(int arg1);

        void on_spinBox_2_valueChanged(int arg1);

        void on_spinBox_3_valueChanged(int arg1);

        void on_pushButton_7_clicked();

        void on_pushButton_3_clicked();

        void on_pushButton_8_clicked();

        void displayChrono();

        void displayTimer();


private:
    Ui::MainWindow *ui;
    TimeDate *td;
    Button *b;
    Timer *t;
    Chrono *ch;
    Clock *c;
    Clock * cl;
    int count = 0;
};
#endif // MAINWINDOW_H
