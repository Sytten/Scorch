/********
File: PauseOverlay.h
Authors: Émile Fugulin, Jean-Philippe Fournier, Philippe Spino, Julien Larochelle
Date: 06 avril 2016
Description: Overlay that appears when the game is on pause
********/

#ifndef PAUSEOVERLAY_H
#define PAUSEOVERLAY_H

#include <QGraphicsRectItem>
#include <QPainter>

class PauseOverlay : public QGraphicsRectItem
{
public:
	PauseOverlay(QGraphicsItem* parent = 0) : QGraphicsRectItem(parent) {}
	PauseOverlay(const QRectF & rect, QGraphicsItem* parent = 0) : QGraphicsRectItem(rect, parent) {}

	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
};

#endif