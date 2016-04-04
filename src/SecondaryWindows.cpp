#include "SecondaryWindows.h"



FenetreNewGame::FenetreNewGame()
{
	setFixedSize(300, 240);

	QGridLayout *grid1 = new QGridLayout();
	QGridLayout *grid2 = new QGridLayout();

	group1 = new QGroupBox();
	group2 = new QGroupBox();
	dialogButtons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

	connect(dialogButtons, &QDialogButtonBox::accepted, this, &QDialog::accept);
	connect(dialogButtons, &QDialogButtonBox::rejected, this, &QDialog::reject);


	setWindowTitle("Nouvelle partie");
	// choix de la difficulte
	m_facile = new QRadioButton("Facile");
	m_moyen = new QRadioButton("Moyen");
	m_difficile = new QRadioButton("Difficile");
	m_aleatoire = new QRadioButton("Aleatoire");

	// choix du nombre de joueurs
	m_un = new QRadioButton("Un joueur");
	m_deux = new QRadioButton("Deux joueurs");

	//Definition des Sections;
	grid1->addWidget(m_un);
	grid1->addWidget(m_deux);
	m_un->setChecked(true);

	grid2->addWidget(m_facile, 0, 0, 0, 9, Qt::AlignLeft);
	grid2->addWidget(m_moyen, 0, 4, 0, 8);
	grid2->addWidget(m_difficile, 0, 6, 0, 9, Qt::AlignCenter);
	grid2->addWidget(m_aleatoire, 0, 9, 0, 9, Qt::AlignRight);
	m_facile->setChecked(true);

	// integration de bouton
	QVBoxLayout *vertical = new QVBoxLayout();
	QHBoxLayout *horizontal = new QHBoxLayout();

	group1->setLayout(grid1);
	group1->setTitle("Selectionner le nombre de joueurs");
	group2->setLayout(grid2);
	group2->setTitle("Selectionner la difficulte");
	vertical->addWidget(group1);
	horizontal->addWidget(group2);
	vertical->addLayout(horizontal);
	vertical->addWidget(dialogButtons);

	setLayout(vertical);
}

FenetreTutoriel::FenetreTutoriel()
{

	setFixedSize(500, 100);

	QLabel *empty = new QLabel("");

	Layout = new QWidget();
	window = new QVBoxLayout();
	title = new QLabel("Ce pr" + QString(233) + "sent tu tutoriel, l'explication du jeu sera fait enti" + QString(232) + "rement.");
	content = new QLabel("Pour ajuster l'angle du canon, dite 'A' et le tenire jusqu'" + QString(230) + " ce que vous vouliez arr" + QString(234) + "ter! \nPour Ajuster la force de tire, dite 'I' pour changer le mode et ensuite redite 'A' pour ajuster la valeur! \n");

	window->addWidget(title);
	window->addWidget(content);
	setLayout(window);

}

FenetreVersion::FenetreVersion()
{
	setFixedSize(500, 100);

	QVBoxLayout * vertical = new QVBoxLayout();
	m_ligne1 = new QLabel("SCORCH VERSION 0.1");
	m_ligne2 = new QLabel("Derniere mise a jour : 2016-04-03");
	m_ligne3 = new QLabel("Developpe par l'equipe P19 de l'U de S");
	m_ligne4 = new QLabel("Julien Larochelle, Emile Fugulin, Jean-Philippe Fournier, Philippe Spino");
	vertical->addWidget(m_ligne1, 1, Qt::AlignCenter);
	vertical->addWidget(m_ligne2, 1, Qt::AlignCenter);
	vertical->addWidget(m_ligne3, 1, Qt::AlignCenter);
	vertical->addWidget(m_ligne4, 1, Qt::AlignCenter);
	setLayout(vertical);
}
