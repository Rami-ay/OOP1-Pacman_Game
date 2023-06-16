#include "SuperPacman.h"

//constructor functions:
//--------------------------
SuperPacman::SuperPacman(int col, int row) : m_col{col} , m_row{row}{}
//--------------------------

//set functions:
// ==================================
//function that set the SuperPacman location on the board:
void SuperPacman::setSuperPacman(int newCol, int newRow)
{
	m_col = newCol;
	m_row = newRow;
}
//--------------------------
//function that sets the sprite position:
void SuperPacman::setSpritePosition(int currentCol, int currentRow, int boardCol, int boardRow)
{
	m_superPacmanSprite.setPosition(725 - (boardCol * 48 / 2) + (currentCol * icon_width), 500 - (boardRow * 48 / 2) + (currentRow * icon_height));
}
//get functions:
// ==================================
// function that return the Super Pacman Col:
int SuperPacman::getSuperPacmanCol() const
{
	return m_col;
}
//--------------------------
// function that return the Super Pacman Row:
int SuperPacman::getSuperPacmanRow() const
{
	return m_row;
}
//--------------------------
//function that returns the sprite of the pacman:
sf::Sprite SuperPacman::getPacmanSprite() const
{
	return m_superPacmanSprite;
}
//--------------------------
//function that gets the input key and handle
//the Super pacman movement:
void SuperPacman::handleInput(sf::Event event)
{
	if (event.key.code == sf::Keyboard::Left)
	{
		m_superPacmanSprite.setRotation(180);
		m_superPacmanSprite.move(-6, 0);
	}
	else if (event.key.code == sf::Keyboard::Right)
	{
		m_superPacmanSprite.setRotation(0);
		m_superPacmanSprite.move(6, 0);

	}
	else if (event.key.code == sf::Keyboard::Up)
	{
		m_superPacmanSprite.setRotation(270);
		m_superPacmanSprite.move(0, -6);
	}
	else if (event.key.code == sf::Keyboard::Down)
	{
		m_superPacmanSprite.setRotation(90);
		m_superPacmanSprite.move(0, 6);
	}
}
