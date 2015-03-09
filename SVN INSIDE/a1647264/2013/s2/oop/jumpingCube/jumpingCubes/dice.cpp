#include "dice.h"

#include<QGridLayout>
#include<QFrame>
#include<QLabel>
#include<QPen>
#include<QString>
#include<QPainter>
#include<QPushButton>


Dice::Dice(QWidget *parent, int face) :

    QWidget(parent)

{

    m_faceVal = face;



}

void Dice::paintEvent(QPaintEvent *event)
{

    QPen pen(Qt::black, 2, Qt::SolidLine);

    QPainter painter(this);
    painter.setPen(pen);
    QString s = QString::number(m_faceVal);
    painter.drawText(10,10,s);

}
