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
}

MainWindow::~MainWindow() {
    delete ui;
    delete td;
    delete b;
}


void::MainWindow::on_pushButton_5_clicked(){

}

void MainWindow::on_pushButton_clicked()
{
    b->changeDateFormat();
    ui->dateTimeEdit->setDisplayFormat(QString::fromStdString(b->getFormat()));

}


void MainWindow::on_pushButton_2_clicked()
{
    b->changeTimeFormat();
    ui->dateTimeEdit->setDisplayFormat(QString::fromStdString(b->getFormat()));
}
