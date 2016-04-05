#include "SecondaryWindows.h"

FenetreNewGame::FenetreNewGame()
{
    setWindowTitle("Nouvelle partie");
    setWindowIcon(QIcon(QPixmap(":/resources/icon_big.png")));
    setFixedSize(300, 240);

	QGridLayout *grid1 = new QGridLayout();
	QGridLayout *grid2 = new QGridLayout();

	group1 = new QGroupBox();
	group2 = new QGroupBox();
	dialogButtons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

	connect(dialogButtons, &QDialogButtonBox::accepted, this, &QDialog::accept);
	connect(dialogButtons, &QDialogButtonBox::rejected, this, &QDialog::reject);

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
	setWindowTitle("Tutoriel");
    setWindowIcon(QIcon(QPixmap(":/resources/icon_big.png")));

	window = new QVBoxLayout();
	title = new QLabel("Dans ce pr" + QString(233) + "sent tutoriel, l'explication du jeu sera fait enti" + QString(232) + "rement.");

	content = new QLabel("	Pour ajuster les param" + QString(232) + "tre du canon, dite 'A' ou 'O' et le tenire jusqu'"
		+ QString(224) + " ce que vous vouliez arr" + QString(234) +
		"ter! \n	Pour change le mode, dite 'I' pour changer le mode \n");

	window->addWidget(title, 1, Qt::AlignCenter);
	window->addWidget(content, 1, Qt::AlignCenter);

	QHBoxLayout * firstRow = new QHBoxLayout;
	QLabel * firstPicture = new QLabel;
	firstPicture->setPixmap(QPixmap(":/resources/tutoriel/tour_joueur.jpg"));
	QLabel * firstText = new QLabel("Cette partie de l'interface repr" + QString(233) + "sente l'indication du joueur courant.");

	firstRow->addWidget(firstPicture);
	firstRow->addWidget(firstText, 0, Qt::AlignRight);

	QHBoxLayout * secondRow = new QHBoxLayout;
	QLabel * secondPicture = new QLabel;
	secondPicture->setPixmap(QPixmap(":/resources/tutoriel/mode_joueur.jpg"));
	QLabel * secondText = new QLabel("Cette partie de l'interface repr" + QString(233) + "sente l'indication du mode d'ajustement courant du joueur.");

	secondRow->addWidget(secondPicture);
	secondRow->addWidget(secondText, 0, Qt::AlignRight);

	QHBoxLayout * thirdRow = new QHBoxLayout;
	QLabel * thirdPicture = new QLabel;
	thirdPicture->setPixmap(QPixmap(":/resources/tutoriel/parametres_mode.jpg"));
	QLabel * thirdText = new QLabel("Indicateur des param" + QString(232) + "tres de tir du joueur");

	thirdRow->addWidget(thirdPicture);
	thirdRow->addWidget(thirdText, 0, Qt::AlignRight);

	window->addLayout(firstRow);
	window->addLayout(secondRow);
	window->addLayout(thirdRow);

	setLayout(window);

}

FenetreVersion::FenetreVersion()
{
	setWindowTitle("Version");
    setWindowIcon(QIcon(QPixmap(":/resources/icon_big.png")));
	setFixedSize(500, 140);

	QVBoxLayout * vertical = new QVBoxLayout();
	m_ligne1 = new QLabel("SCORCH VERSION 0.5");
	m_ligne2 = new QLabel("Derniere mise a jour : 2016-04-04");
	m_ligne3 = new QLabel("Developpe par l'equipe P19 de l'U de S");
	m_ligne4 = new QLabel("Les programmeurs ayant particip" + QString(233) + " " + QString(224) + " la cr" + QString(233) + "ation de Scorch");
	m_ligne5 = new QLabel("Emile Fugulin, Jean-Philippe Fournier, Julien Larochelle, Philippe Spino");

	m_ligne1->setFont(QFont("OCR A extented",10));
	m_ligne2->setFont(QFont("fantasque sans mono",10));
	m_ligne3->setFont(QFont("fantasque sans mono",10));
	m_ligne4->setFont(QFont("fantasque sans mono",10));
	m_ligne5->setFont(QFont("fantasque sans mono",10));

	vertical->addWidget(m_ligne1, 1, Qt::AlignCenter);
	vertical->addWidget(m_ligne2, 1, Qt::AlignCenter);
	vertical->addWidget(m_ligne3, 1, Qt::AlignCenter);
	vertical->addWidget(m_ligne4, 1, Qt::AlignCenter);
	vertical->addWidget(m_ligne5, 1, Qt::AlignCenter);
	setLayout(vertical);
}
