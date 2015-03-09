#include "dice.h"
#include<QGridLayout>
#include<QFrame>
#include<QLabel>
#include<QPen>
#include<QString>
#include<QPainter>
#include<QPoint>
#include<QSize>
#include<QColor>
#include<QRect>



Dice::Dice(QWidget *parent, int face, QColor col, QPoint p) :
    QWidget(parent)
{
    m_faceVal = face;
    m_Point = p;
    m_Team = col;
}

QColor Dice::getTeam() const
{
    return(m_Team);
}

QPoint Dice::getPoint() const
{
    return(m_Point);
}

unsigned int Dice::getFaceValue() const
{

    return(m_faceVal);
}

void Dice::setPoint(QPoint point)
{
    m_Point = point;
}

void Dice::setTeam(QColor color)
{
    m_Team = color;
}

void Dice::setFaceValue(unsigned int faceVal)
{
    m_faceVal = faceVal;
}
void Dice::mousePressEvent(QMouseEvent *event)
{
    QPoint location = getPoint();
    emit pressed(location);
    //setFaceValue(getFaceValue()+1);
    //this->update();
}

void Dice::paintEvent(QPaintEvent *event)
{

    QRect r1(this->rect());

    int size = (r1.width() + r1.height())*0.3;
    QFont newFont("Arial", size);

    QPen pen(m_Team, 2, Qt::SolidLine);
    QPainter painter(this);
    painter.eraseRect(r1);
    painter.setFont(newFont);
    painter.setPen(pen);
    QString s = QString::number(m_faceVal);
    painter.drawText(r1,Qt::AlignCenter,s);

}
