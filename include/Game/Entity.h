#ifndef ENTITY_H
#define ENTITY_H

#include <QGraphicsItem>

#include "Input/FPGAEvent.h"
#include "Game/State.h"
#include "Game/Player.h"

class Entity : public QGraphicsItem
{
    Q_OBJECT

    Q_ENUM(Player)
    Q_PROPERTY(Player owner READ owner WRITE setOwner NOTIFY ownerChanged)

public:
    Entity(Player owner, QGraphicsItem *parent = 0);

    virtual void update(double deltaTime) = 0;
    Player owner() const;

public slots:
    void setOwner(Player owner);

private:
    Player m_owner;

signals:
    void valueChanged(State state, double value);
    void ownerChanged(Player owner);
};

#endif // ENTITY_H
