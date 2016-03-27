#include"GradientBarWidget.h"

GradientBarWidget::GradientBarWidget(QWidget *parent) :QWidget(parent)
{
	
}

GradientBarWidget::~GradientBarWidget()
{

}

void GradientBarWidget::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	int middleY = (rect().top() + rect().bottom()) / 2;
	

	QLinearGradient gradient(rect().left(), middleY, rect().right(), middleY);
	gradient.setColorAt(0, Qt::red);
	gradient.setColorAt(1, Qt::green);

	painter.fillRect(rect(), gradient);

}