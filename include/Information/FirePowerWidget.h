/********
File: FirePowerWidget.h
Authors: Émile Fugulin, Jean-Philippe Fournier, Philippe Spino, Julien Larochelle
Date: 06 avril 2016
Description: Costum layout to display the current power and receive new information
********/

#ifndef FIREPOWERWIDGET_H
#define FIREPOWERWIDGET_H

#include<QWidget>
#include<QLabel>
#include<QLayout>

#include "GradientBarWidget.h"

class FirePowerWidget : public QWidget
{
	Q_OBJECT
public:
	FirePowerWidget(QWidget *parent = 0);
	~FirePowerWidget();

	void setMinPower(float p_minPower);
	void setMaxPower(float p_maxPower);

private:
	float m_power;

	float m_minPower, m_maxPower;

	QLabel * m_firePower;
	GradientBarWidget * m_powerBar;

public slots:
	void setPower(float p_power);
};

#endif
