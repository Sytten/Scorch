#include "GameWindow.h"


GameWindow::GameWindow(QMainWindow *parent) : QMainWindow(parent), m_fpga(this)
{
	setupUI();
}

void GameWindow::setupUI()
{
	temp_power = 35;
	temp_angle = 45;
	temp_player1Turn = true;
	temp_isPowerControlled = State::Angle;
    /****Central widget****/

    this->setCentralWidget(m_game.getView());

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

    this->setStatusBar(new QStatusBar);

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
    //NOTE: Hack to simulate correctly the FPGA input
    m_fpga.handlePressEvent(KeyEvent);
}

void GameWindow::customEvent(QEvent *event)
{
    if(event->type() == FPGAEvent::customFPGAEvent) {
        FPGAEvent* fpgaEvent = static_cast<FPGAEvent *>(event);

        QCoreApplication::postEvent(&m_game, new FPGAEvent(*fpgaEvent));

        //TODO: Following part needs to foward the events on the good widget based on the game state
        switch (fpgaEvent->command()) {
        case Change:			
			if (temp_isPowerControlled == State::Angle)
				temp_isPowerControlled = State::Fire;
			else if (temp_isPowerControlled == State::Fire)
				temp_isPowerControlled = State::Power;
			else
				temp_isPowerControlled = State::Angle;
			m_gameModeWidget->setCurrentMode(temp_isPowerControlled);
            break;
        case Increase:
            if(temp_isPowerControlled == State::Power) {
                temp_power += 1;
                m_currentPower->setPower(temp_power);
			}
			else if (temp_isPowerControlled == State::Angle){
                temp_angle += 1;
                m_currentAngle->setAngle(temp_angle);
            }
            break;
        case Decrease:
			if (temp_isPowerControlled == State::Power) {
                temp_power -= 1;
                m_currentPower->setPower(temp_power);
			}
			else if (temp_isPowerControlled == State::Angle) {
                temp_angle -= 1;
                m_currentAngle->setAngle(temp_angle);
            }
            break;
        default:
            break;
        }
    }

}
