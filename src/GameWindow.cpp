#include "GameWindow.h"


GameWindow::GameWindow(QMainWindow *parent) : QMainWindow(parent), m_fpga(this, 0), m_game()
{
	/****General setup****/
	this->setWindowTitle("Scorch");
	this->setStatusBar(new QStatusBar);
    this->setWindowIcon(QIcon(QPixmap(":/resources/icon_big.png")));
	
	setFocus();
	setStyleSheet("QMainWindow::separator{ width:0px; height:0px;}");
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
		m_actionQuit->setShortcut(QKeySequence("Q"));
	m_actionNewGame = new QAction("Nouvelle partie", this);
		m_actionNewGame->setShortcut(QKeySequence("N"));

	m_menuFichier->addAction(m_actionNewGame);
	m_menuFichier->addSeparator();
	m_menuFichier->addAction(m_actionQuit);
	m_menuBar->addMenu(m_menuFichier);

	// Game menu
    m_menuJeux = new QMenu("Jeu");
	m_actionPause = new QAction("Pause", this);
		m_actionPause->setShortcut(QKeySequence("P"));
	m_actionMuet = new QAction("Muet", this);
		m_actionMuet->setShortcut(QKeySequence("M"));

	m_menuJeux->addAction(m_actionPause);
	m_menuJeux->addSeparator();
	m_menuJeux->addAction(m_actionMuet);
	m_menuBar->addMenu(m_menuJeux);

	//Help menu
	m_menuAide = new QMenu("Aide");
	m_actionTutoriel = new QAction("Tutoriel", this);
        m_actionTutoriel->setShortcut(QKeySequence("F1"));
	m_actionVersion = new QAction("Version", this);
        m_actionVersion->setShortcut(QKeySequence("F2"));
	QAction* actionAboutQt = new QAction(QString(224)+" Propos de Qt", this);
        actionAboutQt->setShortcut(QKeySequence("F3"));

	m_menuAide->addAction(m_actionTutoriel);
	m_menuAide->addSeparator();
	m_menuAide->addAction(m_actionVersion);
	m_menuAide->addSeparator();
	m_menuAide->addAction(actionAboutQt);
	m_menuBar->addMenu(m_menuAide);

	this->setMenuBar(m_menuBar);
	
	/****Connections****/
	// Connect Menu
    connect(m_actionQuit, &QAction::triggered, this, &QMainWindow::close);
	connect(actionAboutQt, &QAction::triggered, QApplication::instance(), &QApplication::aboutQt);
	connect(m_actionPause, &QAction::triggered, this, &GameWindow::pausedTriggered);
    connect(m_actionMuet, &QAction::triggered, this, &GameWindow::muteTriggered);
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
    connect(&m_game, &Game::newGameGenerated, this, &GameWindow::resetPause);
	
	// Connect Info Widgets
	connect(this, &GameWindow::changeAngle, m_currentAngle, &AngleStatusWidget::setAngle);
	connect(this, &GameWindow::changePlayer, m_gameModeWidget, &GameModeWidget::setCurrentPlayer);
	connect(this, &GameWindow::changePower, m_currentPower, &FirePowerWidget::setPower);
	connect(this, &GameWindow::changeState, m_gameModeWidget, &GameModeWidget::setCurrentMode);

    /****Music****/
    QMediaPlaylist* playlist = new QMediaPlaylist;
        playlist->addMedia(QUrl::fromLocalFile(QDir::currentPath() + "/resources/music/Angevin_B.mp3"));
        playlist->addMedia(QUrl::fromLocalFile(QDir::currentPath() + "/resources/music/Celtic_Impulse.mp3"));
        playlist->addMedia(QUrl::fromLocalFile(QDir::currentPath() + "/resources/music/Pippin_the_Hunchback.mp3"));
        playlist->shuffle();
        playlist->setPlaybackMode(QMediaPlaylist::Loop);

    m_musicPlayer.setPlaylist(playlist);
    m_musicPlayer.play();

    QTimer::singleShot(1, this, &GameWindow::openMainMenu);
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

void GameWindow::stateChanged(InputState p_state)
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

void GameWindow::pausedTriggered()
{
	if (m_game.pause()) {
		m_game.setPause(false);
        m_actionPause->setText("Pause");
	}
	else {
		m_game.setPause(true);
		if(m_game.pause())
            m_actionPause->setText("Jouer");
    }
}

void GameWindow::muteTriggered()
{
    if(m_musicPlayer.state() == QMediaPlayer::PlayingState) {
        m_musicPlayer.pause();
        m_actionMuet->setText("Non Muet");
    }
    else if(m_musicPlayer.state() == QMediaPlayer::PausedState) {
        m_musicPlayer.play();
        m_actionMuet->setText("Muet");
    }
}

void GameWindow::resetPause()
{
    m_actionPause->setText("Pause");
}

void GameWindow::keyPressEvent(QKeyEvent * KeyEvent)
{
	//NOTE: Hack to simulate correctly the FPGA input
    if (m_game.getInputState() == InputState::Fire && KeyEvent->key() == Qt::Key_Space){
		QKeyEvent * key = new QKeyEvent(KeyEvent->type(), Qt::Key_Up, Qt::KeyboardModifier::NoModifier);

		m_fpga.handlePressEvent(key);
	}
    else if (m_game.getInputState() == InputState::Fire && (KeyEvent->key() == Qt::Key_Up || KeyEvent->key() == Qt::Key_Down))
		return;
	else
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
	FenetreNewGame fenNewGame;
	fenNewGame.exec();
    if (fenNewGame.result() == QDialog::Accepted) {
		m_game.newGame(fenNewGame.getChosenDifficulty(), 2);
        m_game.startPlaying();
    }
}

void GameWindow::openTutoriel()
{
    FenetreTutoriel fenTutoriel;
    fenTutoriel.exec();
}

void GameWindow::openVersion()
{
    FenetreVersion fenVersion;
    fenVersion.exec();
}

void GameWindow::openMainMenu()
{
	FenetreNewGame fenNewGame;
	fenNewGame.exec();
    if (fenNewGame.result() == QDialog::Accepted) {
        m_game.newGame(fenNewGame.getChosenDifficulty(), 2);
        m_game.startPlaying();
    }
	else
		this->close();
}

void GameWindow::resizeEvent(QResizeEvent *event)
{
	QMainWindow::resizeEvent(event);
	m_game.getView()->fitInView(m_game.getView()->sceneRect(), Qt::KeepAspectRatio);
}

void GameWindow::closeEvent(QCloseEvent *event)
{
	QMessageBox *quitMessage = new QMessageBox(QMessageBox::Information, "Quitter", "Etes vous sur de vouloir quitter?", QMessageBox::Yes | QMessageBox::No);

	quitMessage->setWindowIcon(QIcon(QPixmap(":/resources/icon_big.png")));
	quitMessage->setFixedSize(80, 220);

	if (QMessageBox::Yes == quitMessage->exec())
		event->accept();
    else {
        event->ignore();
        if (m_game.getGameState() == Menu)
            QTimer::singleShot(1, this, &GameWindow::openMainMenu);
    }
}
