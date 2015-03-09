#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lines = new Lines(ui->centralWidget);
    ui->verticalLayout->addWidget(lines);
}

MainWindow::~MainWindow()
{
    delete lines;
    delete ui;
}
