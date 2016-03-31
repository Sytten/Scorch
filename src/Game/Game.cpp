#include "Game/Game.h"

Game::Game(QObject parent) : QObject(parent), m_timeLastUpdate(QTime::currentTime()), m_currentPlayer(Player1)
{
    m_view = new QGraphicsView(&m_scene);

    m_timer.setInterval(1000/60);
    connect(&m_timer, &QTimer::timeout, this, &Game::update);

    m_timer.start();
}

Game::~Game()
{

}

void Game::customEvent(QEvent *event)
{

}

void Game::checkCollisions()
{

}

void Game::update()
{
    checkCollisions();
    m_timeLastUpdate = QTime::currentTime();
}
