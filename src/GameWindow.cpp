#include "GameWindow.h"


GameWindow::GameWindow(QMainWindow *parent) : QMainWindow(parent)
{
	setupUI();
}

void GameWindow::setupUI()
{

	temp_power = 35;
	temp_angle = 45;

	QWidget * centralWidget = new QWidget;

	QVBoxLayout *layout = new QVBoxLayout;
	GameBottomLayout *bottomLayout = new GameBottomLayout;

	m_mainGameWidget = new QLabel("This is the core of the game");
	m_mainGameWidget->setStyleSheet("QLabel { background-color : red; color : blue; }");
	m_mainGameWidget->setMinimumSize(QSize(800, 600));
	
	layout->addWidget(m_mainGameWidget);

	/*m_newGameButton = new QPushButton("Nouvelle partie");
	m_newGameButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
	bottomLayout->addWidget(m_newGameButton);*/


	//This should be an object
	QVBoxLayout *modeLayout = new QVBoxLayout;
	m_currentMode = new QLabel("Current mode goes here");
	
	m_currentPlayerTurn = new QLabel("Current player turn goes here");

	modeLayout->addWidget(m_currentMode);
	modeLayout->addWidget(m_currentPlayerTurn);
	bottomLayout->addLayout(modeLayout);
	//END OF This should be an object

	//This should be an object with custom paint method to make it interesting
	m_currentAngle = new AngleStatusWidget;
	m_currentAngle->setAngle(temp_angle);

	//This will be an object with custom paint method to make it interesting
	m_currentPower = new FirePowerWidget;
	m_currentPower->setPower(temp_power);

	bottomLayout->addStretch();
	bottomLayout->addWidget(m_currentAngle);
	bottomLayout->setAlignment(m_currentAngle, Qt::AlignRight);
	bottomLayout->addWidget(m_currentPower);

	layout->addLayout(bottomLayout);
	centralWidget->setLayout(layout);
	
	this->setCentralWidget(centralWidget);

	m_menuBar = new QMenuBar;
	m_menuFile = new QMenu("Fichier");
	m_actionQuit = new QAction("Quitter", this);
	m_actionNewGame = new QAction("New game", this);

	connect(m_actionQuit, &QAction::triggered, QApplication::instance(), &QApplication::quit);

	m_menuFile->addAction(m_actionNewGame);
	m_menuFile->addSeparator();
	m_menuFile->addAction(m_actionQuit);
	m_menuBar->addMenu(m_menuFile);

	this->setMenuBar(m_menuBar);
	this->setWindowTitle("Scorch");

	m_statusBar = new QStatusBar;
	this->setStatusBar(m_statusBar);

	statusBar()->showMessage("FPGA non-connecté");

	setFocusPolicy(Qt::TabFocus);
}

GameWindow::~GameWindow()
{
}


void GameWindow::keyPressEvent(QKeyEvent * KeyEvent)
{
	if (KeyEvent->isAutoRepeat())
		return;
	switch (KeyEvent->key()){
	case Qt::Key_Right:
		temp_power += 10;
		m_currentPower->setPower(temp_power);
		break;
	case Qt::Key_Left:
		temp_power -= 10;
		
		m_currentPower->setPower(temp_power);
		break;
	case Qt::Key_Up:
		temp_angle += 5;
		m_currentAngle->setAngle(temp_angle);
		break;
	case Qt::Key_Down:
		temp_angle -= 5;
		m_currentAngle->setAngle(temp_angle);
		break;
	default:
		break;
	}
}

void GameWindow::keyReleaseEvent(QKeyEvent * KeyEvent)
{
	if (KeyEvent->isAutoRepeat())
		return;

	switch (KeyEvent->key()) {
	case Qt::Key_Right:
	case Qt::Key_Left:
		break;
	case Qt::Key_Up:
	case Qt::Key_Down:
		break;
	default:
		break;
	}
}


void GameWindow::closeEvent(QCloseEvent * CloseEvent)
{
	
}