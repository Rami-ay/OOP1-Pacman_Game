#include"Cookie.h"


Cookie::Cookie(){}
Cookie::~Cookie() {}


void Cookie::handleCollision(GameObject& gameObject, Toolbar* toolbar)
{
	gameObject.handleCollision(*this,toolbar);
}

void Cookie::handleCollision(Pacman& gameObject, Toolbar* toolbar)
{
	m_Eaten = true;
	gameObject.handleCollision(*this,toolbar);
}

void Cookie::handleCollision(Elf& gameObject,Toolbar* toolbar) {}