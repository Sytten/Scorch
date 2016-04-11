/********
File: AnimationWithSound.h
Authors: Émile Fugulin, Jean-Philippe Fournier, Philippe Spino, Julien Larochelle
Date: 11 avril 2016
Description: Animation with sound effect
********/

#ifndef ANIMATIONWITHSOUND_H
#define ANIMATIONWITHSOUND_H

#include <QMediaPlayer>
#include <QDir>

#include "Game/Animation.h"

class AnimationWithSound : public Animation
{
public:
	AnimationWithSound(const QPixmap& spriteSheet, int numberOfFrame, int spriteWidth, int spriteHeight, QString soundName, QGraphicsItem* parent = 0);

private:
	QMediaPlayer m_sound;
};

#endif