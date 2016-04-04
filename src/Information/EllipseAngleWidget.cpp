#include "Information/EllipseAngleWidget.h"


EllipseAngleWidget::EllipseAngleWidget(QWidget * parent) : QWidget(parent)
{

	m_angle = 0.0f;
	setMinimumSize(QSize(100, 100));

}

EllipseAngleWidget::~EllipseAngleWidget()
{

}

void EllipseAngleWidget::setValue(float p_angle)
{
	while (p_angle >= 360)p_angle -= 360;
	while (p_angle < 0)p_angle += 360;
	m_angle = p_angle;

	update();
}


void EllipseAngleWidget::paintEvent(QPaintEvent * paintEvent)
{
	Q_UNUSED(paintEvent);
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setPen(Qt::black);
	painter.setBrush(QBrush(Qt::black));
	
	QPainterPath *remplissage = new QPainterPath();
	remplissage->moveTo(rect().bottomRight());
	remplissage->lineTo(rect().bottomLeft().rx(),rect().top()-1);
	remplissage->arcTo(QRect(-100,0,200,200), 0, 90);
	remplissage->lineTo(rect().bottomLeft());

	painter.drawPath(*remplissage);

	//painter.fillPath(*remplissage,Qt::black);

	painter.setPen(Qt::red);
	painter.drawLine(rect().bottomLeft(), getLineEnding());	
}


QPoint EllipseAngleWidget::getLineEnding() const
{
	QPoint finalPoint;

	float radius = ((rect().right() - rect().bottomLeft().x()) * (rect().bottomLeft().y() - rect().top())) /
		sqrtf(pow((rect().bottomLeft().y() - rect().top()) * cos(m_angle * PI / 180.0), 2) + pow((rect().right() - rect().bottomLeft().x()) * sin(m_angle * PI / 180.0), 2));

	finalPoint.setX(rect().bottomLeft().x() + (radius * cos(m_angle * PI / 180.0)));
	finalPoint.setY(rect().bottomLeft().y() + (radius * sin(m_angle * PI / 180.0)));

	return finalPoint;
}
