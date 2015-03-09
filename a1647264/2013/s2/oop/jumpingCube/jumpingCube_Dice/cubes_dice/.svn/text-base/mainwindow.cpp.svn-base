#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dice.h"
#include<QColor>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QColor col(Qt::red);
    QColor col2(Qt::blue);
    Dice * die = new Dice(ui->centralWidget, 3,col);
    Dice * die2 = new Dice(ui->centralWidget, 1,col);
    Dice * die3 = new Dice(ui->centralWidget, 1,col);
    Dice * die4 = new Dice(ui->centralWidget, 1,col2);
    Dice * die5 = new Dice(ui->centralWidget, 1);
    Dice * die6 = new Dice(ui->centralWidget, 2,col);
    Dice * die7 = new Dice(ui->centralWidget, 4);
    Dice * die8 = new Dice(ui->centralWidget, 2,col2);
    Dice * die9 = new Dice(ui->centralWidget, 3,col2);

    ui->gridLayout->addWidget(die,0,0);
    ui->gridLayout->addWidget(die2,0,1);
    ui->gridLayout->addWidget(die3,0,2);
    ui->gridLayout->addWidget(die4,1,0);
    ui->gridLayout->addWidget(die5,1,1);
    ui->gridLayout->addWidget(die6,1,2);
    ui->gridLayout->addWidget(die7,2,0);
    ui->gridLayout->addWidget(die8,2,1);
    ui->gridLayout->addWidget(die9,2,2);



}



MainWindow::~MainWindow()
{
    delete ui;

}
