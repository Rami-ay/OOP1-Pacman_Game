// prevent multiple inclusions of header file:
#pragma once
#include "DataBase.h"
#include "Define.h"
#include "StaticObject.h"
#include "Pacman.h"

class Key : public StaticObject
{
public:
	Key();

	virtual void handleCollision(GameObject& gameObject, Toolbar* toolbar);
	virtual void handleCollision(Pacman& gameObject, Toolbar* toolbar);
	virtual void handleCollision(Elf& gameObject, Toolbar* toolbar);
	~Key();
private:
	sf::Sprite m_sprite = m_database.keySprite;
};