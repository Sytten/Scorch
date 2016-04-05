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

	int middleY = ((rect().top() + rect().bottom()) / 2);
	QLinearGradient gradient(rect().left(), middleY, rect().right(), middleY);
	gradient.setColorAt(0, Qt::green);
	gradient.setColorAt(1, Qt::red);
	
	QRect greenRect = getFillRectangle();

	painter.fillRect(rect(), gradient);
	painter.fillRect(greenRect, Qt::black);
	painter.drawRect(rect());

	//WTF
	//painter.drawText(rect().center(), QString(m_currentPercent + QString("%")));

	if (m_currentPercent < 15.0)
		painter.setPen(Qt::white);
	else
		painter.setPen(Qt::black);

	QFont font = painter.font();
	font.setPixelSize(36);
	painter.setFont(font);
	painter.drawText(rect().bottomLeft() - QPoint(0, rect().height() / 8), QString(QString::number(m_currentPercent) + QString("%")));

}


QRect GradientBarWidget::getFillRectangle()
{
	QRect fillRectangle;

	fillRectangle = rect();

	fillRectangle.setLeft(fillRectangle.right() - (fillRectangle.right() - fillRectangle.left()) * ((100.0f - m_currentPercent )/ 100.0f));

	return fillRectangle;
}

void GradientBarWidget::setPercent(float p_percent)
{
	m_currentPercent = qBound(0.0f, p_percent, 100.0f);
	update();
}
