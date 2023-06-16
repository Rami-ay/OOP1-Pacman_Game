// prevent multiple inclusions of header file:
#pragma once
#include "DataBase.h"
#include "Define.h"
#include "StaticObject.h"
#include "Pacman.h"
#include "GameObject.h"


class Cookie : public StaticObject
{
public:
	Cookie();
	virtual void handleCollision(GameObject& gameObject, Toolbar* toolbar);
	virtual void handleCollision(Pacman& gameObject, Toolbar* toolbar);
	virtual void handleCollision(Elf& gameObject, Toolbar* toolbar);
	~Cookie();

private:
	sf::Sprite m_sprite = m_database.cookieSprite;
};