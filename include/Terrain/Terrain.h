#include <qpainterpath.h>
#include <QGraphicsItem>
#include <QPainter>
#include <QVector>

#include "Bezier.h"

class Terrain : public QGraphicsItem
{

public:
	Terrain(QGraphicsItem *parent = 0);
	~Terrain();


	void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
	QRectF boundingRect() const;

	void setPos(const QPointF &pos);
	void setPos(qreal x, qreal y);

	bool intersects(const QRectF &p_rectangle)const;
protected:
	void calculateNewPath();
private:
	QVector<QPointF> m_terrainPoints;
	QVector<QPointF> m_controlPoints;
	QRectF m_bounding;
	QPainterPath m_paintPath;

	QBrush m_brush;
};