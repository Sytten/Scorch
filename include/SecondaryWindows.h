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
#include <QDialogButtonBox>
#include <QGroupBox>
#include <QScrollArea>

class FenetreNewGame : public QDialog
{
	Q_OBJECT
public:
	FenetreNewGame();


private:

	QGroupBox *group1;
	QGroupBox *group2;

	QRadioButton* m_facile;
	QRadioButton * m_moyen;
	QRadioButton * m_difficile;
	QRadioButton * m_aleatoire;
	QRadioButton * m_un;
	QRadioButton * m_deux;
	QDialogButtonBox *dialogButtons;
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
	QLabel * m_ligne5;
};


#endif // !SECONDARYWINDOWS_H
