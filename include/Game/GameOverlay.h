#ifndef GAMEOVERLAY_H
#define GAMEOVERLAY_H

#include <QGraphicsRectItem>
#include <QPainter>

#include "Player.h"

class GameOverlay : public QGraphicsItem
{
public:
    GameOverlay(QGraphicsItem* parent = 0) : QGraphicsItem(parent), m_player1Life(100), m_player2Life(100) {}

    virtual QRectF boundingRect() const;

	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);

public slots:
	void newPlayerLife(Player player, int life);

private:
	int m_player1Life;
	int m_player2Life;
};

#endif
