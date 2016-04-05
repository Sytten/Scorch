#include "Terrain/Terrain.h"

Terrain::Terrain(BezierMode mode, float terrainSize, float margin, QGraphicsItem * parent) : QGraphicsItem(parent), m_brush(QPixmap(":/resources/grass.png"))
{
	
	createBezierBasePoints(mode, margin, terrainSize + (2 * margin));

	float minimumX = 0.0, minimumY = 0.0, maximumX = 0.0, maximumY = 0.0;

	for (QPointF var : m_terrainPoints)
	{
		if (minimumX > var.rx())
			minimumX = var.rx();
		if (maximumX < var.rx())
			maximumX = var.rx();
		if (minimumY > var.ry())
			minimumY = var.ry();
		if (maximumY < var.ry())
			maximumY = var.ry();
	}
	m_bounding = QRectF(minimumX, minimumY, maximumX, maximumY);

	calculateNewPath();
}

Terrain::~Terrain()
{}

QRectF Terrain::boundingRect() const
{
	return QRectF(0, 0, 1920, 800);
}

void Terrain::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{	
	Q_UNUSED(widget);
	Q_UNUSED(option);

	painter->setPen(Qt::black);
	if (scene())
		painter->setClipRect(mapFromScene(scene()->sceneRect().intersected(mapToScene(boundingRect()).boundingRect())).boundingRect());
	painter->fillPath(m_paintPath, m_brush);

	//Debugging for terrain generation
	//painter->drawPath(m_paintPath);
	//painter->drawRect(m_bounding);
	/*
	QPen linepen(Qt::red);
	linepen.setWidth(4);
	painter->setPen(linepen);
	for each (QPointF var in m_controlPoints)
	{
		painter->drawPoint(var);
	}
	linepen.setColor(Qt::blue);
	painter->setPen(linepen);
	for each (QPointF var in m_terrainPoints)
	{
		painter->drawPoint(var);
	}*/
}




void Terrain::setPos(const QPointF &pos)
{
	QGraphicsItem::setPos(pos);
	calculateNewPath();
}

void Terrain::setPos(qreal x, qreal y)
{
	QGraphicsItem::setPos(x, y);
	calculateNewPath();
}

void Terrain::calculateNewPath()
{
	m_controlPoints.empty();

	m_paintPath = QPainterPath();

	m_paintPath.moveTo(this->pos().x(), this->pos().y() + m_bounding.size().height());

	m_paintPath.lineTo(/*this->pos() + */m_terrainPoints[0]);
	for (int i = 0; i < m_terrainPoints.length() - 2; i += 1)
	{
		QPointF start = m_terrainPoints[i];
		QPointF mid = m_terrainPoints[i + 1];
		QPointF end = m_terrainPoints[i + 2];

		QPointF control1 = QPointF((start.rx() + mid.rx()) / 2, (start.ry() + mid.ry()) / 2);
		QPointF control2 = QPointF((mid.rx() + end.rx()) / 2, (mid.ry() + end.ry()) / 2);

		m_controlPoints += control1;
		m_controlPoints += control2;
		if (i == 0)
			m_paintPath.lineTo(control1);

		m_paintPath.cubicTo(mid, mid, control2);

	}
	m_paintPath.lineTo(m_paintPath.currentPosition().rx(), this->pos().y() + m_bounding.size().height());
	m_paintPath.lineTo(this->pos().x(), this->pos().y() + m_bounding.size().height());
}

bool Terrain::intersects(const QRectF &p_rectangle)const
{
	return m_paintPath.intersects(p_rectangle);
}

QPointF Terrain::PointAtX(const float p_x)const
{	
	for (int i = 1; i < scene()->sceneRect().bottom(); i++)
	{
		if (m_paintPath.intersects(QRectF(p_x, 0, 0, i))){			
			return QPointF(p_x, i);
		}
	}
	return QPointF(-1, -1);
}


QPointF Terrain::getHighestPointBetween(float p_x1, float p_x2)
{
	QPointF currentHighest = QPointF(4000,4000);
	for (QPointF var : m_terrainPoints){
		//Inversed because of coordinate system
		if (var.rx() < p_x2 && var.rx() > p_x1)
		{
			if (currentHighest.ry() > var.ry())
				currentHighest = var;
		}
	}
	for (QPointF var : m_controlPoints){
		//Inversed because of coordinate system
		if (var.rx() < p_x2 && var.rx() > p_x1)
		{
			if (currentHighest.ry() > var.ry())
				currentHighest = var;
		}
	}
	return currentHighest;
}

QPointF Terrain::getLowestPointBetween(float p_x1, float p_x2)
{
	QPointF currentLowest = QPointF(0, 0);
	for (QPointF var : m_terrainPoints){
		//Inversed because of coordinate system
		if (var.rx() < p_x2 && var.rx() > p_x1)
		{
			if (currentLowest.ry() < var.ry())
				currentLowest = var;
		}
	}
	for (QPointF var : m_controlPoints){
		//Inversed because of coordinate system
		if (var.rx() < p_x2 && var.rx() > p_x1)
		{
			if (currentLowest.ry() < var.ry())
				currentLowest = var;
		}
	}
	return currentLowest;
}

void Terrain::createBezierBasePoints(BezierMode p_mode, float p_basePointsSpacing, float p_curveEndPoints)
{
	m_terrainPoints.clear();
	if (p_mode == BezierMode::InsaneCurves)	{
		for (int i = 0; i < p_curveEndPoints; i += p_basePointsSpacing){
			m_terrainPoints += QPointF(i, (rand() % 100) + (fmod(rand(), 1000) / 1000));
		}
	}
	else if (p_mode == BezierMode::Flat){
		for (int i = 0; i < p_curveEndPoints; i += p_basePointsSpacing){
			m_terrainPoints += QPointF(i, 1.0f);
		}
	}
	else if (p_mode == BezierMode::HighCurves){
		for (int i = 0; i < p_curveEndPoints; i += p_basePointsSpacing){
			m_terrainPoints += QPointF(i, (rand() % 100) + (fmod(rand(), 100) / 1000));
		}
	}
	else{
		for (int i = 0; i < p_curveEndPoints; i += p_basePointsSpacing){
			m_terrainPoints += QPointF(i, (rand() % 10) + (fmod(rand(), 100) / 1000));
		}
	}
}