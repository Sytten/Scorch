#include "Game/GameOverlay.h"

void GameOverlay::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
}

void GameOverlay::newPlayerLife(Player player, int life)
{
	if (player == Player1)
		m_player1Life = life;
	else if (player == Player2)
		m_player2Life = life;
}