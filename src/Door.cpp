#include "Door.h"

//constructor functions:
//--------------------------
Door::Door(){}


//get functions
//--------------------------
int Door::getDoorCol() const
{
	return m_col;
}
//--------------------------
int Door::getDoorRow() const
{
	return m_row;
}
//--------------------------
//set functions:
//--------------------------
void Door::setDoorCol(int newCol)
{
	m_col = newCol;
}
//--------------------------
void Door::setDoorRow(int newRow)
{
	m_row = newRow;
}
//--------------------------

void Door::handleCollision(GameObject& gameObject, Toolbar* toolbar)
{
	gameObject.handleCollision(*this, toolbar);
}

void Door::handleCollision(Pacman& gameObject, Toolbar* toolbar)
{
	
	gameObject.handleCollision(*this, toolbar);
	if (gameObject.getISuper())
		m_Eaten = true;
}

void Door::handleCollision(Elf& gameObject,Toolbar* toolbar) {}