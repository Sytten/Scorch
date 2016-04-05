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