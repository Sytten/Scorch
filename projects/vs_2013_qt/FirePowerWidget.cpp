#include"FirePowerWidget.h"

FirePowerWidget::FirePowerWidget(QWidget *parent) :QWidget(parent)
{
	m_power = m_minPower = 0;
	m_maxPower = 100;

	QVBoxLayout * layout = new QVBoxLayout;

	layout->addWidget(new QLabel("Puissance:"));

	m_powerBar = new GradientBarWidget;

	layout->addWidget(m_powerBar);

	setLayout(layout);
}

FirePowerWidget::~FirePowerWidget()
{

}