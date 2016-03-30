#ifndef ANGLESTATUSWIDGET_H
#define ANGLESTATUSWIDGET_H

#include<QtWidgets>
#include<QLayout>
#include<QSizePolicy>

#include "EllipseAngleWidget.h"

class AngleStatusWidget : public QWidget
{
	Q_OBJECT
public:
	AngleStatusWidget(QWidget *parent = 0);
	~AngleStatusWidget();

	void setAngle(float p_angle);


private:
	float m_angle;
	QLabel * m_currentAngle;
	EllipseAngleWidget * m_ellipseAngle;
};

#endif