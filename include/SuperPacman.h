// prevent multiple inclusions of header file:
#pragma once
#include "DataBase.h"
#include "Define.h"
// SuperPacman abstract data type definition
class SuperPacman
{
public:
	//constructor functions:
	//-----------------------------------
	SuperPacman(int col	, int row);

	//set functions:
	// ==================================
	void setSuperPacman(int newCol, int newRow);
	void setSpritePosition(int currentCol, int currentRow, int boardCol, int boardRow);

	//get functions:
	// ==================================
	int getSuperPacmanCol() const;
	int getSuperPacmanRow() const;
	sf::Sprite getPacmanSprite() const;

	void handleInput(sf::Event event);

private:
	int m_col;
	int m_row;
	sf::Sprite m_superPacmanSprite = m_database.pacmanSprite;
};