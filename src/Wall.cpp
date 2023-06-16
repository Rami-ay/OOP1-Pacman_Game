#include "Wall.h"



Wall::Wall() {}
Wall::~Wall(){}

void Wall::handleCollision(GameObject& gameObject, Toolbar* toolbar)
{
	gameObject.handleCollision(*this, toolbar);
}
void Wall::handleCollision(Pacman& gameObject, Toolbar* toolbar)
{
	gameObject.handleCollision(*this, toolbar);
}
void Wall::handleCollision(Elf& gameObject, Toolbar* toolbar) {}