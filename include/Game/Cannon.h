#ifndef CANNON_H
#define CANNON_H

#include <QGraphicsPixmapItem>

class Cannon : public QGraphicsPixmapItem
{
public:
    Cannon(QGraphicsItem *parent = 0);

private:
    double m_angle;
    double m_power;
};

#endif // CANNON_H
