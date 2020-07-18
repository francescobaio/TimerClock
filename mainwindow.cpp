#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDateTime>
#include<QString>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit->setDisabled(true);
    td = new TimeDate;
    b = new Button(td);

    t = new Timer;
    ch = new Chrono;
    c = new Clock(t);

    ui->spinBox->setRange(0, 23);
    ui->spinBox_2->setRange(0, 59);
    ui->spinBox_3->setRange(0, 59);

}

MainWindow::~MainWindow() {
    delete ui;
    delete td;
    delete b;
    delete t;
    delete ch;
    delete c;
}


void ::MainWindow::on_pushButton_5_clicked() {
    int hour = ch->getHour();
    ch->setHour(24);
    ui->lcdNumber_4->display(hour);
    ui->lcdNumber_5->display(c->getMinute());
    ui->lcdNumber_6->display(c->getSecond());
    ui->lcdNumber_7->display(c->getMillisecond());


}

void MainWindow::on_pushButton_clicked() {
    td->setDateCount(td->getDateCount() + 1);
    b->notify();
    ui->dateTimeEdit->setDisplayFormat(QString::fromStdString(td->getFormat()));

}


void MainWindow::on_pushButton_2_clicked() {
    td->setTimeCount(td->getTimeCount() + 1);
    b->notify();
    ui->dateTimeEdit->setDisplayFormat(QString::fromStdString(td->getFormat()));
}


void MainWindow::on_pushButton_4_clicked() {
    ui->lcdNumber_4->display(0);
    ui->lcdNumber_5->display(0);
    ui->lcdNumber_6->display(0);
    ui->lcdNumber_7->display(0);
}

void MainWindow::on_pushButton_6_clicked() {
    ui->lcdNumber->display(ui->spinBox->value());
    t->setHour(ui->spinBox->value());
    ui->lcdNumber_2->display(ui->spinBox_2->value());
    t->setMinute(ui->spinBox_2->value());
    ui->lcdNumber_3->display(ui->spinBox_3->value());
    t->setSecond(ui->spinBox_3->value());
}


void MainWindow::on_spinBox_valueChanged(int arg1) {
    ui->lcdNumber->display(arg1);
    t->setHour(arg1);
}


void MainWindow::on_spinBox_2_valueChanged(int arg1) {
    ui->lcdNumber_2->display(arg1);
    t->setMinute(arg1);
}

void MainWindow::on_spinBox_3_valueChanged(int arg1) {
    ui->lcdNumber_3->display(arg1);
    t->setSecond(arg1);
}

void MainWindow::on_pushButton_7_clicked() {
    while (t->getHour() || t->getMinute() || t->getSecond()) {
        while (t->getSecond() >= 0) {
            t->setState();
            ui->lcdNumber_3->display(c->getSecond());
        }
        t->setSecond(0);
        if (t->getMinute()) {
            t->setMinute(t->getMinute() - 1);
            t->setSecond(59);
            t->notify();
            ui->lcdNumber_2->display(c->getMinute());
            ui->lcdNumber_3->display(c->getSecond());

        } else if (t->getHour()) {
            t->setHour(t->getHour() - 1);
            t->setMinute(59);
            t->setSecond(59);
            t->notify();
            ui->lcdNumber->display(c->getHour());
            ui->lcdNumber_2->display(c->getMinute());
            ui->lcdNumber_3->display(c->getSecond());
        }
    }
}

void MainWindow::on_pushButton_3_clicked() {
    t->setHour(24);
    t->setMinute(0);
    t->setSecond(0);
}

void MainWindow::on_pushButton_8_clicked() {
    while (ch->getHour() < 24) {
        while (ch->getMinute() < 60) {
            while (ch->getSecond() < 60) {
                while (ch->getMillisecond() < 1000) {
                    ch->setState();
                    ui->lcdNumber_7->display(c->getMillisecond());
                }
                ch->setSecond(ch->getSecond() + 1);
                ch->setMillisecond(0);
                ch->notify();
                ui->lcdNumber_7->display(c->getMillisecond());
                ui->lcdNumber_6->display(c->getSecond());
            }
            ch->setMinute(ch->getMinute() + 1);
            ch->setSecond(0);
            ch->notify();
            ui->lcdNumber_7->display(c->getMillisecond());
            ui->lcdNumber_6->display(c->getSecond());
            ui->lcdNumber_5->display(c->getMinute());
        }
        ch->setHour(ch->getHour() + 1);
        ch->setMinute(0);
        ch->notify();
        ui->lcdNumber_7->display(c->getMillisecond());
        ui->lcdNumber_6->display(c->getSecond());
        ui->lcdNumber_5->display(c->getMinute());
        ui->lcdNumber_4->display(c->getHour());
    }
}
