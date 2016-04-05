#include "Information/AngleStatusWidget.h"


AngleStatusWidget::AngleStatusWidget(QWidget *parent) : QWidget(parent)
{
	m_currentAngle = new QLabel("Angle: ");

	QFont font = m_currentAngle->font();
	font.setBold(true);
	font.setPixelSize(12);
	m_currentAngle->setFont(font);

	m_ellipseAngle = new EllipseAngleWidget;

	QVBoxLayout * layout = new QVBoxLayout;

	layout->addWidget(m_currentAngle);
	layout->addWidget(m_ellipseAngle);

	setLayout(layout);

	m_angle = 0.0f;

	m_currentAngle->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
	m_currentAngle->setAlignment(Qt::AlignCenter);
	m_ellipseAngle->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);	
	layout->setAlignment(m_ellipseAngle, Qt::AlignCenter);

	setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
}

AngleStatusWidget::~AngleStatusWidget()
{}

void AngleStatusWidget::setAngle(float p_angle)
{
	while (p_angle >= 360)p_angle -= 360;
	while (p_angle < 0)p_angle += 360;
	m_angle = p_angle;

	/*QString labelText("Angle courant : ");
	labelText.append(QString::number(m_angle));
	m_currentAngle->setText(labelText);*/

	m_ellipseAngle->setValue(m_angle);
}
