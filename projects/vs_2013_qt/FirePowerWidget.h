#include<QtWidgets>
#include<QLayout>

#include "GradientBarWidget.h"

class FirePowerWidget : public QWidget
{
	Q_OBJECT
public:
	FirePowerWidget(QWidget *parent = 0);
	~FirePowerWidget();

private:
	float m_power;

	float m_minPower, m_maxPower;

	GradientBarWidget * m_powerBar;
};