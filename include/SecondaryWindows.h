#ifndef SECONDARYWINDOWS_H
#define SECONDARYWINDOWS_H

#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QRadioButton>
#include <QStatusBar>

class FenetreNewGame : public QDialog
{
	Q_OBJECT
public:
	FenetreNewGame();

private:
	QPushButton * m_facile;
	QPushButton * m_moyen;
	QPushButton * m_difficile;
	QPushButton * m_aleatoire;
	QRadioButton * m_un;
	QRadioButton * m_deux;
	QLabel * m_joueur1;
	QLabel * m_joueur2;
};

class FenetreTutoriel : public QDialog
{
	Q_OBJECT
public:
	FenetreTutoriel();
private:
	QWidget *Layout;
	QVBoxLayout *window;
	QLabel *title;
	QLabel *content;
};

class FenetreVersion : public QDialog
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
