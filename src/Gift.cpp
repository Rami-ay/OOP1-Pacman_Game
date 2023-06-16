#include "Gift.h"


Gift::Gift(){}
Gift::~Gift(){}


void Gift::handleCollision(GameObject& gameObject,Toolbar* toolbar)
{
	gameObject.handleCollision(*this, toolbar);
}

void Gift::handleCollision(Pacman& gameObject, Toolbar* toolbar)
{
	//toolbar->superPacON();
	gameObject.activeSuperPacman();
	switch (gift_type)
	{
	case 1:
		toolbar->setSecs(toolbar->getSecs() + 30);
		gameObject.PlayTimeSong();
		break;
	case 2:
		toolbar->freezeModeON();
		gameObject.playFreezeSong();
		break;
	case 3:
		toolbar->increaselife();
		gameObject.PlayHeartSong();
		break;
	}
	m_Eaten = true;
	gameObject.handleCollision(*this, toolbar);
}

void Gift::handleCollision(Elf& gameObject, Toolbar* toolbar) {}
