#include "Information/FirePowerWidget.h"

FirePowerWidget::FirePowerWidget(QWidget *parent) :QWidget(parent)
{
	m_power = m_minPower = 0;
	m_maxPower = 100;

	QVBoxLayout * layout = new QVBoxLayout;

	m_firePower = new QLabel("Puissance:");
	QFont font = m_firePower->font();
	font.setBold(true);
	font.setPixelSize(14);
	m_firePower->setFont(font);

	m_powerBar = new GradientBarWidget;

	m_firePower->setAlignment(Qt::AlignCenter);
	layout->addWidget(m_firePower);

	m_powerBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
	layout->addWidget(m_powerBar);

	setLayout(layout);

}

FirePowerWidget::~FirePowerWidget()
{

}

void FirePowerWidget::setPower(float p_power)
{
	m_power = qBound(m_minPower, p_power, m_maxPower);
	m_powerBar->setPercent(((m_power - m_minPower) / (m_maxPower - m_minPower)) * 100);
	QString labelText = "Puissance : ";
	labelText.append(QString::number(m_power));
	m_firePower->setText(labelText);
}

void FirePowerWidget::setMinPower(float p_minPower)
{
	m_minPower = p_minPower;
}

void FirePowerWidget::setMaxPower(float p_maxPower)
{
	m_maxPower = p_maxPower;
}
