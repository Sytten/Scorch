#ifndef SECONDARYWINDOWS_H
#define SECONDARYWINDOWS_H

#include <qwidget.h>
#include <qpushbutton.h>
#include <qcheckbox.h>
#include <QVBoxLayout>
#include <QHBoxlayout>
#include <qlabel.h>

class FenetreNewGame : public QWidget
{
	Q_OBJECT
public:
	FenetreNewGame();

private:
	QPushButton * m_facile;
	QPushButton * m_moyen;
	QPushButton * m_difficile;
	QPushButton * m_aleatoire;
	QCheckBox * m_un;
	QCheckBox * m_deux;
	QLabel * m_joueur1;
	QLabel * m_joueur2;
};

class FenetreTutoriel : public QWidget
{
	Q_OBJECT
public:
	FenetreTutoriel();
};

class FenetreVersion : public QWidget
{
	Q_OBJECT
public:
	FenetreVersion();
private:
	QLabel * m_ligne1;
	QLabel * m_ligne2;
	QLabel * m_ligne3;
	QLabel * m_ligne4;
};


#endif // !SECONDARYWINDOWS_H