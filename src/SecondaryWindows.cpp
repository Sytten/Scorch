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

Difficulty FenetreNewGame::getChosenDifficulty()
{
	if (m_facile->isChecked())
		return Difficulty::Easy;
	else if (m_moyen->isChecked())
		return Difficulty::Intermediate;
	else if (m_difficile->isChecked())
		return Difficulty::Hard;
	return Difficulty::Random;
}

FenetreTutoriel::FenetreTutoriel()
{

	setWindowTitle("Tutoriel");
    setWindowIcon(QIcon(QPixmap(":/resources/icon_big.png")));
	setMinimumSize(QSize(655, 400));
	setMaximumSize(QSize(655, 600));
	setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);

	window = new QVBoxLayout();


	QGroupBox * group0 = new QGroupBox("General");
	QHBoxLayout * zeroRow = new QHBoxLayout;
	content = new QLabel("Pour ajuster les param" + QString(232) + "tre du canon, dite 'A' ou 'O' et le tenir jusqu'"
		+ QString(224) + " ce que vous vouliez arr" + QString(234) + "ter. Pour changer le mode, il faut prononcer la lettre 'I'. Les clavier peut aussi contr" + QString(147) + "ler les activit" + QString(233) + "s de tir, les fl" + QString(232) + "ches gauche et droite permettant de modifier le mode d'ajustement et les fl" + QString(232) + "ches haut et bas permettant d'ajuster le param" + QString(232) + "tre. La barre espace permet quant à elle de provoquer le tir lorsque le mode est \"tir\"");
	content->setWordWrap(true);
	zeroRow->addWidget(content, 0, Qt::AlignLeft);
	group0->setLayout(zeroRow);

	QGroupBox * group1 = new QGroupBox("Cette partie de l'interface repr" + QString(233) + "sente l'indication du joueur courant. Dans ce cas-ci, le joueur 1 est actif");
	QHBoxLayout * firstRow = new QHBoxLayout;
	QLabel * firstPicture = new QLabel;
	firstPicture->setPixmap(QPixmap(":/resources/tutoriel/tour_joueur.jpg"));
	firstRow->addWidget(firstPicture, 0, Qt::AlignCenter);
	group1->setLayout(firstRow);

	QGroupBox * group2 = new QGroupBox("Cette partie de l'interface repr" + QString(233) + "sente l'indication du mode d'ajustement courant du joueur.");
	QHBoxLayout * secondRow = new QHBoxLayout;
	QLabel * secondPicture = new QLabel;
	secondPicture->setPixmap(QPixmap(":/resources/tutoriel/mode_joueur.jpg"));
	secondRow->addWidget(secondPicture, 0, Qt::AlignCenter);
	group2->setLayout(secondRow);

	QGroupBox * group3 = new QGroupBox("Indicateur des param" + QString(232) + "tres de tir du joueur");
	QHBoxLayout * thirdRow = new QHBoxLayout;
	QLabel * thirdPicture = new QLabel;
	thirdPicture->setPixmap(QPixmap(":/resources/tutoriel/parametres_mode.jpg"));
	thirdRow->addWidget(thirdPicture, 0, Qt::AlignCenter);
	group3->setLayout(thirdRow);

	QGroupBox * group4 = new QGroupBox("Dialogue de nouvelle partie");
	QVBoxLayout * fourthRow = new QVBoxLayout;
	QLabel * fourthText = new QLabel("Dans le menu de nouvelle partie, il est possible de s" + QString(233) + "lectionner un mode de jeu entre \"un joueur\" et \"deux joueurs\". Le mode simple joueur inclut une intelligence pour l'adversaire." + QString("Aussi dans la cr" + QString(233) + "ation d'une nouvelle partie, il est possible de s" + QString(233) + "lectionner le difficult" + QString(233) + ", qui ajuste premi" + QString(232) + "rement le niveau de difficult" + QString(233) + " du terrain."));
	fourthText->setWordWrap(true);
	QLabel * fourthPicture = new QLabel;
	fourthPicture->setPixmap(QPixmap(":/resources/tutoriel/fenetre_nouvelle_partie.jpg"));
	fourthRow->addWidget(fourthText, 0, Qt::AlignLeft);
	fourthRow->addWidget(fourthPicture, 0, Qt::AlignLeft);
	group4->setLayout(fourthRow);

	window->addWidget(group0);
	window->addWidget(group1);
	window->addWidget(group2);
	window->addWidget(group3);
	window->addWidget(group4);
	//window->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);

	QWidget * main = new QWidget();
	main->setLayout(window);
	//main->setMaximumSize(QSize(800, 400));
	//main->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
	

	QScrollArea * scrollArea = new QScrollArea;
	scrollArea->setWidget(main);
	//scrollArea->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

	QVBoxLayout * mainLayout = new QVBoxLayout;
	mainLayout->addWidget(scrollArea);

	setLayout(mainLayout);
}

FenetreVersion::FenetreVersion()
{
	setWindowTitle("Version");
    setWindowIcon(QIcon(QPixmap(":/resources/icon_big.png")));
	setFixedSize(560, 250);

	QVBoxLayout * vertical = new QVBoxLayout();
	m_ligne1 = new QLabel("SCORCH VERSION 0.5");
	m_ligne2 = new QLabel("Derniere mise a jour : 2016-04-04");
	m_ligne3 = new QLabel("Developpe par l'equipe P19 de l'U de S");
	m_ligne4 = new QLabel("Les programmeurs ayant particip" + QString(233) + " " + QString(224) + " la cr" + QString(233) + "ation de Scorch");
	m_ligne5 = new QLabel("Emile Fugulin, Jean-Philippe Fournier, Julien Larochelle, Philippe Spino");
	QLabel * ligne6 = new QLabel("Pippin the Hunchback, Celtic Impulse, Angevin B by Kevin MacLeod (incompetech.com) \n" +
		QString("Licensed under Creative Commons : By Attribution 3.0 License\n") +
		QString("http ://creativecommons.org/licenses/by/3.0/"));
	QGroupBox * group = new QGroupBox("Cr" + QString(233) + "dits additionnels");
	QVBoxLayout * layout = new QVBoxLayout;

	m_ligne1->setFont(QFont("OCR A extented",10));
	m_ligne2->setFont(QFont("fantasque sans mono",10));
	m_ligne3->setFont(QFont("fantasque sans mono",10));
	m_ligne4->setFont(QFont("fantasque sans mono",10));
	m_ligne5->setFont(QFont("fantasque sans mono",10));
	ligne6->setFont(QFont("fantasque sans mono", 10));
	layout->addWidget(ligne6);
	group->setLayout(layout);

	vertical->addWidget(m_ligne1, 1, Qt::AlignCenter);
	vertical->addWidget(m_ligne2, 1, Qt::AlignCenter);
	vertical->addWidget(m_ligne3, 1, Qt::AlignCenter);
	vertical->addWidget(m_ligne4, 1, Qt::AlignCenter);
	vertical->addWidget(m_ligne5, 1, Qt::AlignCenter);
	vertical->addWidget(group, 1, Qt::AlignCenter);
	setLayout(vertical);
}
