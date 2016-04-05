#ifndef ELLIPSEANGLEWIDGET_H
#define ELLIPSEANGLEWIDGET_H

#include<QWidget>
#include<QLayout>
#include<QPainter>

#define PI 3.14159265

class EllipseAngleWidget : public QWidget
{
	Q_OBJECT
public:
	EllipseAngleWidget(QWidget *parent = 0);
	~EllipseAngleWidget();

	void setValue(float p_angle);

protected:
	void paintEvent(QPaintEvent * paintEvent);

private:
	float m_angle;

	QPoint getLineEnding() const;
	QPoint getPointOnLineAtAngle(float angle, float prct);
};

#endif
