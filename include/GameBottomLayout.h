#include<QHBoxLayout>

class GameBottomLayout : public QHBoxLayout
{
public:
	GameBottomLayout(QWidget *parent = 0) :QHBoxLayout(parent){}

	~GameBottomLayout(){}

protected:
	QSize maximumSize() const{
		return QSize(4000, 150);
	}
private:

};