#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QVector>
#include <QGridLayout>
#include "dice.h"

class Board : public QWidget
{
    Q_OBJECT
public:
    //enum posType_t {COR,EDG,SURR};
    explicit Board(QWidget *parent = 0);
    int pos(Dice &d);
signals:

public slots:
    void wipe();
    void resized(int val);
    void updateFace(QPoint location);
private:

    QVector< QVector<Dice*> > m_Dice;
    int m_gridSize;
    QGridLayout *m_Layout;
    int m_Turn;

};

#endif // BOARD_H
