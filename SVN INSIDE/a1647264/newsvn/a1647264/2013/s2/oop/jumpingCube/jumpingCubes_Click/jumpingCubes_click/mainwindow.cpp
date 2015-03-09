#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dice.h"
#include "board.h"
#include <QObject>
#include<QColor>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Board * board = new Board(ui->centralWidget);
    ui->gridLayout->addWidget(board);

    QObject::connect(ui->restartButton, SIGNAL(clicked()), board , SLOT(wipe()));

    QObject::connect(ui->spinBox, SIGNAL(valueChanged(int)), board, SLOT(resized(int)));

}



MainWindow::~MainWindow()
{
    delete ui;

}
