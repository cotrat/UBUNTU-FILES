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


    explicit Dice(QWidget *parent = 0, int face = 1);

protected:

    void paintEvent(QPaintEvent *event);
    unsigned int getFaceValue();
    QColor getTeam();
    QPoint getPoint();

signals:


private:


    int m_faceVal;
    QColor m_Team;
    QPoint m_Point;



public slots:






};



#endif // DICE_H
