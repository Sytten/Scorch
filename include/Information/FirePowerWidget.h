#ifndef FIREPOWERWIDGET_H
#define FIREPOWERWIDGET_H

#include<QtWidgets>
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
