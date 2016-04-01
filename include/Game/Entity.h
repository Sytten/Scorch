#ifndef ENTITY_H
#define ENTITY_H

#include <QGraphicsItem>

#include "Input/FPGAEvent.h"
#include "Game/State.h"

class Entity : public QGraphicsItem
{
    Q_OBJECT

public:
    Entity(QGraphicsItem *parent = 0) : QGraphicsItem(parent) {}

    void update(double deltaTime) = 0;

signals:
    void valueChanged(State state, double value);
};

#endif // ENTITY_H
