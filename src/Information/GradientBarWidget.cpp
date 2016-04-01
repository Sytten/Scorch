#include "Information/GradientBarWidget.h"

GradientBarWidget::GradientBarWidget(QWidget *parent) :QWidget(parent)
{
	setPercent(50.0f);
}

GradientBarWidget::~GradientBarWidget()
{

}

void GradientBarWidget::paintEvent(QPaintEvent * paintEvent)
{
	Q_UNUSED(paintEvent);

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	int middleY = (rect().top() + rect().bottom()) / 2;
	QRect fillRect = getFillRectangle();

	QLinearGradient gradient(fillRect.left(), middleY, fillRect.right(), middleY);
	gradient.setColorAt(0, Qt::red);
	gradient.setColorAt(1, Qt::green);

	painter.fillRect(fillRect, gradient);

	painter.drawRect(rect());

}


QRect GradientBarWidget::getFillRectangle()
{
	QRect fillRectangle;

	fillRectangle = rect();

	fillRectangle.setRight(fillRectangle.left() + (fillRectangle.right() - fillRectangle.left()) * (m_currentPercent / 100.0f));

	return fillRectangle;
}

void GradientBarWidget::setPercent(float p_percent)
{
	m_currentPercent = qBound(0.0f, p_percent, 100.0f);
	update();
}
