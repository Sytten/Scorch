#include "GameWindow.h"


GameWindow::GameWindow(QMainWindow *parent) : QMainWindow(parent), m_fpga(this), temp_isPowerControlled(true)
{
	setupUI();
}

void GameWindow::setupUI()
{
	temp_power = 35;
	temp_angle = 45;
	temp_player1Turn = true;


    /****Central widget, will be replaced by actual game****/

	m_mainGameWidget = new QLabel("This is the core of the game");
	m_mainGameWidget->setStyleSheet("QLabel { background-color : red; color : blue; }");
	m_mainGameWidget->setMinimumSize(QSize(800, 400));
	
    this->setCentralWidget(m_mainGameWidget);

	/*m_newGameButton = new QPushButton("Nouvelle partie");
	m_newGameButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
	bottomLayout->addWidget(m_newGameButton);*/


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
	m_currentAngle->setAngle(temp_angle);

	//This will be an object with custom paint method to make it interesting
	m_currentPower = new FirePowerWidget;
	m_currentPower->setPower(temp_power);

	bottomLayout->addStretch();
	bottomLayout->addWidget(m_currentAngle);
	bottomLayout->setAlignment(m_currentAngle, Qt::AlignRight);
	bottomLayout->addWidget(m_currentPower);

    bottomWidget->setLayout(bottomLayout);
    informationPanel->setWidget(bottomWidget);

    this->addDockWidget(Qt::BottomDockWidgetArea, informationPanel);


    /****Menus****/

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

	setFocusPolicy(Qt::TabFocus);

	connect(&m_fpga, &FPGAReceiver::fpgaError, this, &GameWindow::displayStatusMessage);
}

GameWindow::~GameWindow()
{
}

void GameWindow::displayStatusMessage(QString message)
{
	statusBar()->showMessage(message);
}

void GameWindow::keyPressEvent(QKeyEvent * KeyEvent)
{
	switch (KeyEvent->key()){
	case Qt::Key_Space:
		if (KeyEvent->isAutoRepeat())
			return;
		m_gameModeWidget->togglePlayer();
		break;
	default:
        m_fpga.handlePressEvent(KeyEvent);
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

void GameWindow::customEvent(QEvent *event)
{
    if(event->type() == FPGAEvent::customFPGAEvent) {
        FPGAEvent* fpgaEvent = static_cast<FPGAEvent *>(event);
        switch (fpgaEvent->command()) {
        case Change:
                temp_isPowerControlled = !temp_isPowerControlled;
            break;
        case Increase:
            if(temp_isPowerControlled) {
                temp_power += 1;
                m_currentPower->setPower(temp_power);
            } else {
                temp_angle += 1;
                m_currentAngle->setAngle(temp_angle);
            }
            break;
        case Decrease:
            if(temp_isPowerControlled) {
                temp_power -= 1;
                m_currentPower->setPower(temp_power);
            } else {
                temp_angle -= 1;
                m_currentAngle->setAngle(temp_angle);
            }
            break;
        default:
            break;
        }
    }

}
