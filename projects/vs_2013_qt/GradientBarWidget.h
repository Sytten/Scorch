#include<QtWidgets>
#include<QLayout>


class GradientBarWidget : public QWidget
{
	Q_OBJECT
public:
	GradientBarWidget(QWidget *parent = 0);
	~GradientBarWidget();

protected:
	void paintEvent(QPaintEvent *);

private:

};