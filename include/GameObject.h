// prevent multiple inclusions of header file:
#pragma once
#include "DataBase.h"
#include "Define.h"
#include "Toolbar.h"
#include <memory>

class Pacman;
class Elf;
class Wall;
class Gift;
class Door;
class Key;
class Cookie;
class MovingObject;
class staticObject;


class GameObject
{
public:
	GameObject();
	void initObjectPac(int currentCol, int currentRow, int boardCol, int boardRow, sf::Sprite newSprite);
	void initObject(int currentCol, int currentRow, int boardCol, int boardRow, sf::Sprite newSprite);
	void draw(sf::RenderWindow* main_window);
	sf::Sprite getSprite() const;

	void resetSuperPacman();
	void activeSuperPacman();

	bool checkCollision(const GameObject& other) const;

	virtual void handleCollision(GameObject& gameObject, Toolbar* toolbar) = 0;
	virtual void handleCollision(Pacman& gameObject, Toolbar* toolbar) = 0;
	virtual void handleCollision(Elf& gameObject, Toolbar* toolbar) = 0;
	virtual void handleCollision(Wall& gameObject, Toolbar* toolbar) = 0;
	virtual void handleCollision(Door& gameObject, Toolbar* toolbar) = 0;
	virtual void handleCollision(Gift& gameObject, Toolbar* toolbar) = 0;
	virtual void handleCollision(Cookie& gameObject, Toolbar* toolbar) = 0;
	virtual void handleCollision(Key& gameObject, Toolbar* toolbar) = 0;



protected:
	sf::Sprite m_sprite;
	sf::Vector2f m_startPosition;
	bool is_super = false;
	int gift_type = 0;
};



