#include "Elf.h"

//constructor functions:
//--------------------------
Elf::Elf() : m_col{ 0 }, m_row{ 0 } {}
Elf::Elf(int col, int row) : m_col{ col }, m_row{ row }, m_onCake{ false }, m_onElf{ false }, m_onGift{ false }, m_onKey{ false } {}
//--------------------------

//set functions:
// ==========================
//function that set the Elf location on the board:
void Elf::setElf(int newCol, int newRow)
{
	m_col = newCol;
	m_row = newRow;
}
//--------------------------
void Elf::setOnCake(bool status)
{
	m_onCake = status;
}
//--------------------------
void Elf::setOnkey(bool status)
{
	m_onKey = status;
}
//--------------------------
void Elf::setOnGift(bool status)
{
	m_onGift = status;
}
//--------------------------
void Elf::setOnElf(bool status)
{
	m_onElf = status;
}
//--------------------------

//get functions:
// =========================

// function that return the Elf Col:
int Elf::getElfCol() const
{
	return(m_col);
}
//--------------------------
// function that return the Elf Row:
int Elf::getElfRow() const
{
	return(m_row);
}
//--------------------------
//function that return if elf on cake:
bool Elf::getOnCake() const
{
	return m_onCake;
}
//--------------------------
//function that return if elf on key:
bool Elf::getOnkey() const
{
	return m_onKey;
}
//--------------------------
//function that return if elf on gift:
bool Elf::getOnGift() const
{
	return m_onGift;
}
//--------------------------
//function that return if elf on elf:
bool Elf::getOnElf() const
{
	return m_onElf;
}

void Elf::reset()
{
	m_sprite.setPosition(m_startPosition);
}



void Elf::handleCollision(GameObject& gameObject,Toolbar* toolbar)
{
	gameObject.handleCollision(*this, toolbar);
}

void Elf::handleCollision(Pacman& gameObject,Toolbar* toolbar)
{
	gameObject.handleCollision(*this, toolbar);
}

void Elf::handleCollision(Elf& gameObject, Toolbar* toolbar) {}
void Elf::handleCollision(Wall& gameObject, Toolbar* toolbar) 
{
	m_sprite.setPosition(m_prevPosition);
}
void Elf::handleCollision(Door& gameObject, Toolbar* toolbar)
{
	m_sprite.setPosition(m_prevPosition);
}
void Elf::handleCollision(Gift& gameObject, Toolbar* toolbar) {}
void Elf::handleCollision(Cookie& gameObject, Toolbar* toolbar) {}
void Elf::handleCollision(Key& gameObject, Toolbar* toolbar) {}