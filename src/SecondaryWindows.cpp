#include "SecondaryWindows.h"



FenetreNewGame::FenetreNewGame()
{
	setWindowTitle("Nouvelle partie");
	// choix de la difficulte
	m_facile = new QPushButton("Facile");
	m_moyen = new QPushButton("Moyen");
	m_difficile = new QPushButton("Difficile");
	m_aleatoire = new QPushButton("Aleatoire");

	// choix du nombre de joueurs
	m_un = new QCheckBox;
	m_deux = new QCheckBox;
	m_joueur1 = new QLabel("Un joueur");
	m_joueur2 = new QLabel("Deux joueurs");
	QLabel * joueur = new QLabel("Selectionner le nombre de joueurs");
	QLabel * difficultes = new QLabel("Selectionner la difficulte");
	QLabel * endl = new QLabel("");
	// integration de bouton
	QVBoxLayout * vertical = new QVBoxLayout();
	QHBoxLayout * difficulte = new QHBoxLayout();
	QHBoxLayout * joueurs1 = new QHBoxLayout();
	QHBoxLayout * joueurs2 = new QHBoxLayout();
	vertical->addWidget(joueur);
	joueurs1->addWidget(m_joueur1);
	joueurs1->addWidget(m_un);
	joueurs2->addWidget(m_joueur2);
	joueurs2->addWidget(m_deux);
	vertical->addLayout(joueurs1);
	vertical->addLayout(joueurs2);
	vertical->addWidget(endl);
	vertical->addWidget(difficultes);
	difficulte->addWidget(m_facile);
	difficulte->addWidget(m_moyen);
	difficulte->addWidget(m_difficile);
	difficulte->addWidget(m_aleatoire);
	vertical->addLayout(difficulte);

	setLayout(vertical);
}

FenetreTutoriel::FenetreTutoriel()
{
	
}

FenetreVersion::FenetreVersion()
{
	QVBoxLayout * vertical = new QVBoxLayout();
	m_ligne1 = new QLabel("SCORCH VERSION 0.1");
	m_ligne2 = new QLabel("Derniere mise a jour : 2016-04-03");
	m_ligne3 = new QLabel("Developpe par l'equipe P19 de l'U de S");
	m_ligne4 = new QLabel("Julien Larochelle, Emile Fugulin, Jean-Philippe Fournier, Philippe Spino");
	vertical->addWidget(m_ligne1);
	vertical->addWidget(m_ligne2);
	vertical->addWidget(m_ligne3);
	vertical->addWidget(m_ligne4);
	setLayout(vertical);
}