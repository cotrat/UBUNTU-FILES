#include "board.h"
#include <Qcolor>
#include <Qpoint>
#include <QVector>
#include "dice.h"
#include<QString>
#include <QGridLayout>
#include <QMessageBox>

Board::Board(QWidget *parent) :
    QWidget(parent)
{
    m_Turn = 0;
    m_Layout = new QGridLayout();   // Creating a layout inside of the board widget
    this->setLayout(m_Layout);      // Setting the Board to take this widget
    m_gridSize = 4;                 // Default grid size of 4x4
    int x;
    int y;

    QColor col(Qt::black);
    QVector<Dice*> rowVector;
    // Iterating through each empty grid spot and placing a "dice" in this spot
    // and also adding it to the vector of dice

    for(y = 0; y < m_gridSize; y++)
    {
        for(x = 0; x < m_gridSize; x++)
            {
                QPoint pos(x,y);
                Dice * myDie = new Dice(this,1,col,pos);
                QObject::connect(myDie,SIGNAL(pressed(QPoint)),this,SLOT(updateFace(QPoint)));
                rowVector.append(myDie);
                this->m_Layout->addWidget(myDie,x,y);

            }
        m_Dice.append(rowVector);
        rowVector.clear();
     }


}

void Board::wipe()
{

    int x;
    int y;
    for(y = 0; y < m_gridSize; y++)
    {
        for(x = 0; x < m_gridSize; x++)
            {
            m_Dice[y][x]->setFaceValue(1);
            m_Dice[y][x]->setTeam(QColor(Qt::black));
            }
    }
    this->update();
}

int Board::pos(Dice& d)
{
    int xpos = d.getPoint().x();
    int ypos = d.getPoint().y();

    if((xpos or ypos)==0)
    {
        return 2;
    }
}

void Board::resized(int val)
{

    int x;
    int y;
    for(y = 0; y < m_gridSize; y++)
    {
        for(x = 0; x< m_gridSize;x++)
        {
            delete m_Dice[y][x];
        }
    }

    m_Dice.clear();
    m_gridSize = val;
    QVector<Dice*> rowVector;
    QColor col(Qt::black);
    for(y = 0; y < m_gridSize; y++)
    {
        for(x = 0; x < m_gridSize; x++)
            {
                QPoint pos(x,y);
                Dice * myDie = new Dice(this,1,col,pos);
                QObject::connect(myDie,SIGNAL(pressed(QPoint)),this,SLOT(updateFace(QPoint)));
                rowVector.append(myDie);
                this->m_Layout->addWidget(myDie,x,y);

            }
        m_Dice.append(rowVector);
        rowVector.clear();
     }
    this->update();
}

void Board::updateFace(QPoint location)
{
    if((m_Turn%2==0) and (m_Dice[location.y()][location.x()]->getTeam())==QColor(Qt::blue))
    {
        QMessageBox::information(NULL, "Invalid Move","Only your own colors or black");
        return;
    }
    if((m_Turn%2==1) and (m_Dice[location.y()][location.x()]->getTeam())==QColor(Qt::red))
    {
        QMessageBox::information(NULL, "Invalid Move","Only your own colors or black");
        return;
    }
    int test = pos(*m_Dice[location.y()][location.x()]);
    QMessageBox::information(NULL, "Invalid Move",QString::number(test));
    unsigned int currentFace = m_Dice[location.y()][location.x()]->getFaceValue();
    m_Dice[location.y()][location.x()]->setFaceValue(currentFace+1);
    if(m_Turn%2==0)
    {
       m_Dice[location.y()][location.x()]->setTeam(QColor(Qt::red));
    }
    else if(m_Turn%2==1)
    {
       m_Dice[location.y()][location.x()]->setTeam(QColor(Qt::blue));
    }
    m_Turn = m_Turn+1;
    this->update();

}
