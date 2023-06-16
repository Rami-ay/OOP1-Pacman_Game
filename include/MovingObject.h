// prevent multiple inclusions of header file:
#pragma once
#include "DataBase.h"
#include "Define.h"
#include <memory>
#include "GameObject.h"
#include "StaticObject.h"


class Pacman;
class Elf;

class MovingObject:public GameObject
{
public:
	MovingObject();
	void handleInput(sf::Event event);
	void moveElf(int boardCol, int boardRow, sf::Vector2f pacman_position, std::vector<std::unique_ptr<StaticObject>>& objects, float chaseProbability);
	sf::Vector2f closestNeighbor(const sf::Vector2f& target, const sf::Vector2f& current, sf::Vector2f neighbors[4]);
	bool validNeighbor(sf::Vector2f closeNeighbor, int boardCol, int boardRow);
	float distance(const sf::Vector2f& p1, const sf::Vector2f& p2);
	int getlives();
	sf::Vector2f getSpritePos()const;



	void setISuper(bool status);
	bool getISuper() const;
	
protected:
	int live = 3;
	sf::Vector2f m_prevPosition;
	int row = 0;
};