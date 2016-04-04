#include "GameWindow.h"


GameWindow::GameWindow(QMainWindow *parent) : QMainWindow(parent), m_fpga(this), m_game()
{
	/****General setup****/
	this->setWindowTitle("Scorch");
	this->setStatusBar(new QStatusBar);
	
	setFocus();
	m_game.getView()->setFocusPolicy(Qt::NoFocus);
	
	
	/****Central widget****/
	GameModeWidget * m_gameModeWidget;
	AngleStatusWidget * m_currentAngle;
	FirePowerWidget * m_currentPower;

	this->setCentralWidget(m_game.getView());

	
	/****Bottom Widget (Information about player)****/
	QWidget* bottomWidget = new QWidget;
	QDockWidget* informationPanel = new QDockWidget;
	informationPanel->setAllowedAreas(Qt::BottomDockWidgetArea);
	informationPanel->setFeatures(QDockWidget::NoDockWidgetFeatures);
	GameBottomLayout *bottomLayout = new GameBottomLayout;

	m_gameModeWidget = new GameModeWidget;
	bottomLayout->addWidget(m_gameModeWidget);

	//This should be an object with custom paint method to make it interesting
	m_currentAngle = new AngleStatusWidget;
	m_currentAngle->setAngle(0);

	//This will be an object with custom paint method to make it interesting
	m_currentPower = new FirePowerWidget;
	m_currentPower->setPower(50);

	bottomLayout->addStretch();
	bottomLayout->addWidget(m_currentAngle);
	bottomLayout->setAlignment(m_currentAngle, Qt::AlignRight);
	bottomLayout->addWidget(m_currentPower);

	bottomWidget->setLayout(bottomLayout);
	informationPanel->setWidget(bottomWidget);

	this->addDockWidget(Qt::BottomDockWidgetArea, informationPanel);

	
	/****Menus****/
	m_menuBar = new QMenuBar;
	
	// File menu
	m_menuFichier = new QMenu("Fichier");
	m_actionQuit = new QAction("Quitter", this);
	m_actionNewGame = new QAction("Nouvelle partie", this);
	

	m_menuFichier->addAction(m_actionNewGame);
	m_menuFichier->addSeparator();
	m_menuFichier->addAction(m_actionQuit);
	m_menuBar->addMenu(m_menuFichier);

	// Game menu
	m_menuJeux = new QMenu("Jeux");
	m_actionPlay = new QAction("Play", this);
	m_actionPause = new QAction("Pause", this);
	m_actionMuet = new QAction("Muet", this);

	m_menuJeux->addAction(m_actionPlay);
	m_menuJeux->addSeparator();
	m_menuJeux->addAction(m_actionPause);
	m_menuJeux->addSeparator();
	m_menuJeux->addAction(m_actionMuet);
	m_menuBar->addMenu(m_menuJeux);

	//Help menu
	m_menuAide = new QMenu("Aide");
	m_actionTutoriel = new QAction("Tutoriel", this);
	m_actionVersion = new QAction("Version", this);

	m_menuAide->addAction(m_actionTutoriel);
	m_menuAide->addSeparator();
	m_menuAide->addAction(m_actionVersion);
	m_menuBar->addMenu(m_menuAide);

	this->setMenuBar(m_menuBar);

	
	/****Connections****/
	// Connect Menu
	connect(m_actionQuit, &QAction::triggered, QApplication::instance(), &QApplication::quit);
	connect(m_actionNewGame, SIGNAL(triggered()), this, SLOT(openNewGame()));
	connect(m_actionTutoriel, SIGNAL(triggered()), this, SLOT(openTutoriel()));
	connect(m_actionVersion, SIGNAL(triggered()), this, SLOT(openVersion()));

	// Connect Input
	connect(&m_fpga, &FPGAReceiver::fpgaError, this, &GameWindow::displayStatusMessage);

	// Connect Game
	connect(&m_game, &Game::playerChanged, this, &GameWindow::playerChanged);
	connect(&m_game, &Game::angleChanged, this, &GameWindow::angleChanged);
	connect(&m_game, &Game::powerChanged, this, &GameWindow::powerChanged);
	connect(&m_game, &Game::stateChanged, this, &GameWindow::stateChanged);
	
	// Connect Info Widgets
	connect(this, &GameWindow::changeAngle, m_currentAngle, &AngleStatusWidget::setAngle);
	connect(this, &GameWindow::changePlayer, m_gameModeWidget, &GameModeWidget::setCurrentPlayer);
	connect(this, &GameWindow::changePower, m_currentPower, &FirePowerWidget::setPower);
	connect(this, &GameWindow::changeState, m_gameModeWidget, &GameModeWidget::setCurrentMode);
}

GameWindow::~GameWindow()
{
}

void GameWindow::displayStatusMessage(QString message)
{
	statusBar()->showMessage(message);
}

void GameWindow::playerChanged(Player p_player)
{
	emit changePlayer(p_player);
}

void GameWindow::stateChanged(State p_state)
{
	emit changeState(p_state);
}

void GameWindow::angleChanged(float p_angle)
{
	emit changeAngle(p_angle);
}

void GameWindow::powerChanged(float p_power)
{
	emit changePower(p_power);
}

void GameWindow::keyPressEvent(QKeyEvent * KeyEvent)
{
    //NOTE: Hack to simulate correctly the FPGA input
    m_fpga.handlePressEvent(KeyEvent);
}

void GameWindow::customEvent(QEvent *event)
{
    if(event->type() == FPGAEvent::customFPGAEvent) {
        FPGAEvent* fpgaEvent = static_cast<FPGAEvent *>(event);

        QCoreApplication::postEvent(&m_game, new FPGAEvent(*fpgaEvent));
    }
}

void GameWindow::openNewGame()
{
	fenNewGame = new FenetreNewGame();

	fenNewGame->show();
}

void GameWindow::openTutoriel()
{
	fenTutoriel = new FenetreTutoriel();
	fenTutoriel->show();
	
}

void GameWindow::openVersion()
{
	fenVersion = new FenetreVersion();

	fenVersion->show();
}

void GameWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    m_game.getView()->fitInView(m_game.getView()->sceneRect(), Qt::KeepAspectRatio);
}
