#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dice.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Dice * die = new Dice(ui->centralWidget, 3);
    ui->gridLayout->addWidget(die,0,0);
}

MainWindow::~MainWindow()
{
    delete ui;

}
