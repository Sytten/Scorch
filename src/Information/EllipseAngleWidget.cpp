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
	//Check for bounds of angle or add/subtract to get a good value
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
	
	//Paint 1/4 ellipse
	QPainterPath remplissage = QPainterPath();
	remplissage.moveTo(rect().bottomRight());
	remplissage.lineTo(rect().bottomLeft().rx(),rect().top());
	remplissage.arcTo(QRect(-rect().width(), 0, rect().width() * 2, rect().height() * 2), 0, 90);
	remplissage.lineTo(rect().bottomLeft());

	painter.drawPath(remplissage);


	QPen pen = painter.pen();
	pen.setColor(Qt::white);
	pen.setWidth(2);
	painter.setPen(pen);

	//Paint the dial increments
	for (int i = 0; i <= 90; i += 10)
		painter.drawLine(getPointOnLineAtAngle(i, 0.9), getPointOnLineAtAngle(i, 1.0));

	//Draw red line
	painter.setPen(Qt::red);
	painter.drawLine(rect().bottomLeft(), getLineEnding());	

	painter.setPen(pen);
	QFont font = painter.font();
	font.setPixelSize(36);
	painter.setFont(font);
	//Draw angle indication text
	painter.drawText(rect().bottomLeft() - QPoint(0, rect().height() / 8), QString(QString::number(m_angle) + '\260'));
}


QPoint EllipseAngleWidget::getLineEnding() const
{
	QPoint finalPoint;

	float radius = rect().right();

	//Calculate the end point of the dial line
	finalPoint.setX(rect().bottomLeft().x() + (radius * cos(m_angle * PI / 180.0)));
	finalPoint.setY(rect().bottomLeft().y() - (radius * sin(m_angle * PI / 180.0)));

	return finalPoint;
}

QPoint EllipseAngleWidget::getPointOnLineAtAngle(float angle, float prct)
{
	QPoint finalPoint;

	float radius = rect().right();

	//Calculate a point from a line at a certain angle
	finalPoint.setX(rect().bottomLeft().x() + (prct * (radius * cos(angle * PI / 180.0))));
	finalPoint.setY(rect().bottomLeft().y() - (prct * (radius * sin(angle * PI / 180.0))));

	return finalPoint;
}