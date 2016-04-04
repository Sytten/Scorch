#include "Terrain/Terrain.h"

Terrain::Terrain(QGraphicsItem * parent) : QGraphicsItem(parent), m_brush(QPixmap(":/resources/grass.png"))
{
	Curves terrainCurve(BezierMode::InsaneCurves, 75, 2400);
	m_terrainPoints = terrainCurve.getBasePoint();

	float minimumX = 0.0, minimumY = 0.0, maximumX = 0.0, maximumY = 0.0;

	for each (QPointF var in m_terrainPoints)
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
	return QRectF(-1, -1, 2000, 800);
}

void Terrain::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{	
	painter->setPen(Qt::black);
	painter->fillPath(m_paintPath, m_brush);

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

		//control1 += this->pos();
		//control2 += this->pos();
		//mid += this->pos();

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