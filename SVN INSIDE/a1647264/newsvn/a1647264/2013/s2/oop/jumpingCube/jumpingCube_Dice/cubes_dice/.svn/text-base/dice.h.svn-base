#ifndef DICE_H
#define DICE_H
#include <QWidget>
#include<QColor>
#include<QPoint>
#include<QString>

class Dice : public QWidget

{

    Q_OBJECT

public:

    explicit Dice(QWidget *parent = 0, int face = 1,QColor col = QColor(Qt::black),QPoint p = QPoint());

    unsigned int getFaceValue() const;

    QColor getTeam() const;

    QPoint getPoint() const;

    //void setFaceValue(unsigned int faceVal);

    //void setTeam(QColor color);

    //void setPoint(QPoint point);

protected:

    void paintEvent(QPaintEvent *event);



signals:

private:

    int m_faceVal;

    QColor m_Team;

    QPoint m_Point;

public slots:

};

#endif // DICE_H


