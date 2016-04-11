#include "Game/AnimationWithSound.h"

AnimationWithSound::AnimationWithSound(const QPixmap& spriteSheet, int numberOfFrame, int spriteWidth, int spriteHeight, QString soundName, QGraphicsItem* parent)
	: Animation(spriteSheet, numberOfFrame, spriteWidth, spriteHeight, parent)
{
	m_sound.setMedia(QUrl::fromLocalFile(QDir::currentPath() + soundName));
	m_sound.play();
}