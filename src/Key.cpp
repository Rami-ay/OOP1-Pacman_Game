#include"Key.h"

Key::Key(){}
Key::~Key() {}

void Key::handleCollision(GameObject& gameObject, Toolbar* toolbar)
{
	gameObject.handleCollision(*this, toolbar);
}

void Key::handleCollision(Pacman& gameObject, Toolbar* toolbar)
{
	m_Eaten = true;
	gameObject.handleCollision(*this, toolbar);
}

void Key::handleCollision(Elf& gameObject, Toolbar* toolbar) {}
