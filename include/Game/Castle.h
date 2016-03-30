#ifndef CASTLE_H
#define CASTLE_H

#include <QGraphicsPixmapItem>

class Castle : public QGraphicsPixmapItem
{
public:
    Castle(int p_initialLife, QGraphicsItem *parent = 0);

    bool isAlive();
    void takeDamage(int p_damage);

private:
    int m_life;
};

#endif // CASTLE_H
