/********
File: GameBottomLayout.h
Authors: �mile Fugulin, Jean-Philippe Fournier, Philippe Spino, Julien Larochelle
Date: 06 avril 2016
Description: Costum Layout for the information panel
********/

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