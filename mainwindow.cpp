#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit->setDisabled(true);
    td = new TimeDate;
    b = new Button(td);

    t = new Timer;
    ch = new Chrono;
    c = new Clock(ch);
    cl = new Clock(t);

    ui->spinBox->setRange(0, 23);
    ui->spinBox_2->setRange(0, 59);
    ui->spinBox_3->setRange(0, 59);

    QObject::connect(t->getTimer(), SIGNAL(timeout()), t, SLOT(setTimer()));


    QObject::connect(ch->getTimer(), SIGNAL(timeout()), this, SLOT(displayChrono()));
    QObject::connect(t->getTimer(), SIGNAL(timeout()), this, SLOT(displayTimer()));
}


MainWindow::~MainWindow() {
    delete ui;
    delete td;
    delete b;
    delete t;
    delete ch;
    delete c;
    delete cl;
}

void MainWindow::displayChrono() {
    ui->lcdNumber_4->display(c->getHour());
    ui->lcdNumber_5->display(c->getMinute());
    ui->lcdNumber_6->display(c->getSecond());
}

void MainWindow::displayTimer() {
    ui->lcdNumber->display(cl->getHour());
    ui->lcdNumber_2->display(cl->getMinute());
    ui->lcdNumber_3->display(cl->getSecond());
}


void ::MainWindow::on_pushButton_5_clicked() {
    ch->getTimer()->stop();
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
    ch->getTimer()->stop();
    ch->setHour(0);
    ch->setMinute(0);
    ch->setSecond(0);
    ui->lcdNumber_4->display(0);
    ui->lcdNumber_5->display(0);
    ui->lcdNumber_6->display(0);
}

void MainWindow::on_pushButton_6_clicked() {
    t->getTimer()->stop();
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
    t->getTimer()->start(1000);
}


void MainWindow::on_pushButton_3_clicked() {
    t->getTimer()->stop();
}

void MainWindow::on_pushButton_8_clicked() {
    ch->getTimer()->start(1);
}
