#ifndef ENTITY_H
#define ENTITY_H

#include <QGraphicsPixmapItem>
#include <QObject>

#include "Game/State.h"
#include "Game/Player.h"

class Entity : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    Q_ENUM(Player)
    Q_PROPERTY(Player owner READ owner WRITE setOwner NOTIFY ownerChanged)

public:
    Entity(const QPixmap &pixmap, Player owner, QGraphicsItem *parent = 0);

    virtual void updateEntity(double deltaTime) = 0;
    Player owner() const;

public slots:
    void setOwner(Player owner);

private:
    Player m_owner;

signals:
    void ownerChanged(Player owner);
};

#endif // ENTITY_H
