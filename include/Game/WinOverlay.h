/********
File: WinOverlay.h
Authors: Emile Fugulin, Jean-Philippe Fournier, Philippe Spino, Julien Larochelle
Date: 09 avril 2016
Description: Overlay that appears when a player win the game
********/

#ifndef WINOVERLAY_H
#define WINOVERLAY_H

#include <QGraphicsRectItem>
#include <QPainter>

class WinOverlay : public QGraphicsRectItem
{
public:
    WinOverlay(QString winner, QGraphicsItem* parent = 0) : QGraphicsRectItem(parent), m_winner(winner) {}
    WinOverlay(QString winner, const QRectF & rect, QGraphicsItem* parent = 0) : QGraphicsRectItem(rect, parent), m_winner(winner) {}

	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);

private:
    QString m_winner;
};

#endif
