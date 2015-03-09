#include "lines.h"
#include <QPen>
#include <QPainter>

Lines::Lines(QWidget *parent) :
    QWidget(parent)
{
}

void Lines::paintEvent(QPaintEvent *event)
{
    QPen pen(Qt::black, 2, Qt::SolidLine);

    QPainter painter(this);

    painter.setPen(pen);
    painter.drawLine(20, 40, 250, 40);

    pen.setStyle(Qt::DashLine);
    pen.setColor(Qt::cyan);
    painter.setPen(pen);
    painter.drawLine(20, 80, 250, 80);

    pen.setStyle(Qt::DotLine);
    pen.setColor(Qt::magenta);
    painter.setPen(pen);
    painter.drawLine(20, 20, 20, 120);

    pen.setStyle(Qt::DashDotDotLine);
    pen.setColor(Qt::red);
    pen.setWidth(10);
    painter.setPen(pen);
    painter.drawLine(20, 160, 250, 160);

    QVector<qreal> dashes;
    qreal space = 4;
    dashes << 1 << space << 5 << space;

    pen.setStyle(Qt::CustomDashLine);
    pen.setDashPattern(dashes);
    pen.setColor(Qt::blue);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawLine(20, 20, 250, 200);
}
