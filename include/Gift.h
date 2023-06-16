// prevent multiple inclusions of header file:
#pragma once
#include "DataBase.h"
#include "Define.h"
#include "StaticObject.h"
#include "Pacman.h"

class Gift : public StaticObject
{
public:
	Gift();

	virtual void handleCollision(GameObject& gameObject, Toolbar* toolbar);
	virtual void handleCollision(Pacman& gameObject, Toolbar* toolbar);
	virtual void handleCollision(Elf& gameObject, Toolbar* toolbar);
	~Gift();
private:
	sf::Sprite m_sprite;
};