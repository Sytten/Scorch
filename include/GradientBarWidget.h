#include<QtWidgets>
#include<QLayout>


class GradientBarWidget : public QWidget
{
	Q_OBJECT
public:
	GradientBarWidget(QWidget *parent = 0);
	~GradientBarWidget();

	void setPercent(float p_percent);

protected:
	void paintEvent(QPaintEvent * paintEvent);

private:
	QRect getFillRectangle();

	float m_currentPercent;
};