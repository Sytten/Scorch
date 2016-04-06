/********
File: Terrain.h
Authors: Émile Fugulin, Jean-Philippe Fournier, Philippe Spino, Julien Larochelle
Date: 06 avril 2016
Description: Random terrain generator for the game
********/

#include <qpainterpath.h>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QVector>

enum BezierMode{
	Flat = 0,
	LowCurves,
	HighCurves,
	InsaneCurves
};

class Terrain : public QGraphicsItem
{

public:
	Terrain(BezierMode mode = BezierMode::HighCurves, float terrainSize = 1920, float margin = 75, QGraphicsItem *parent = 0);
	~Terrain();
	
	void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
	QRectF boundingRect() const;

	void setPos(const QPointF &pos);
	void setPos(qreal x, qreal y);

	bool intersects(const QRectF &p_rectangle)const;
	QPointF PointAtX(const float p_x)const;

	QPointF getHighestPointBetween(float p_x1, float p_x2);
	QPointF getLowestPointBetween(float p_x1, float p_x2);
protected:
	void calculateNewPath();
private:
	void createBezierBasePoints(BezierMode p_mode, float p_basePointsSpacing, float p_curveEndPoints);

	QVector<QPointF> m_terrainPoints;
	QVector<QPointF> m_controlPoints;
	QRectF m_bounding;
	QPainterPath m_paintPath;

	QBrush m_brush;
};