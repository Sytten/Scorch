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
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setPen(Qt::white);
	painter.setBrush(QBrush(Qt::black));
	painter.drawEllipse(rect());

	painter.setPen(Qt::red);
	painter.drawLine(rect().center(), getLineEnding());	
}


QPoint EllipseAngleWidget::getLineEnding() const
{
	QPoint finalPoint;

	float radius = ((rect().right() - rect().center().x()) * (rect().center().y() - rect().top())) /
		sqrtf(pow((rect().center().y() - rect().top()) * cos(m_angle * PI / 180.0), 2) + pow((rect().right() - rect().center().x()) * sin(m_angle * PI / 180.0), 2));

	finalPoint.setX(rect().center().x() + (radius * cos(m_angle * PI / 180.0)));
	finalPoint.setY(rect().center().y() + (radius * sin(m_angle * PI / 180.0)));

	return finalPoint;
}
