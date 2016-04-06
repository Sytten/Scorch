/********
File: AngleStatusWidget.h
Authors: Émile Fugulin, Jean-Philippe Fournier, Philippe Spino, Julien Larochelle
Date: 06 avril 2016
Description: Costum layout for angle widget with some slots to receive new information
********/

#ifndef ANGLESTATUSWIDGET_H
#define ANGLESTATUSWIDGET_H

#include<QWidget>
#include<QLabel>
#include<QLayout>
#include<QSizePolicy>

#include "EllipseAngleWidget.h"

class AngleStatusWidget : public QWidget
{
	Q_OBJECT
public:
	AngleStatusWidget(QWidget *parent = 0);
	~AngleStatusWidget();	
private:
	float m_angle;
	QLabel * m_currentAngle;
	EllipseAngleWidget * m_ellipseAngle;

public slots:
	void setAngle(float p_angle);
};

#endif
