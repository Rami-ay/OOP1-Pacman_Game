// prevent multiple inclusions of header file:
#pragma once
#include"Pacman.h"
#include <SFML/Graphics.hpp>
#include "DataBase.h"
#include "Define.h"
#include "MovingObject.h"
// Elf abstract data type definition
class Elf : public MovingObject
{
public:
//constructor functions:
//------------------------------------------------
	Elf();
	Elf(int col, int row);
	//set functions:
	// ==================================
	void setElf(int newCol, int newRow);
	void setOnCake(bool status) ;
	void setOnkey(bool status) ;
	void setOnGift(bool status) ;
	void setOnElf(bool status) ;

	

	//get functions:
	// ==================================
	int getElfCol() const;
	int getElfRow() const;
	bool getOnCake() const;
	bool getOnkey() const;
	bool getOnGift() const;
	bool getOnElf() const;
	void reset();

	virtual void handleCollision(GameObject& gameObject, Toolbar* toolbar);
	virtual void handleCollision(Pacman& gameObject, Toolbar* toolbar);
	virtual void handleCollision(Elf& gameObject, Toolbar* toolbar);
	virtual void handleCollision(Wall& gameObject, Toolbar* toolbar);
	virtual void handleCollision(Door& gameObject, Toolbar* toolbar);
	virtual void handleCollision(Gift& gameObject, Toolbar* toolbar);
	virtual void handleCollision(Cookie& gameObject, Toolbar* toolbar);
	virtual void handleCollision(Key& gameObject, Toolbar* toolbar);

	
private:
	int m_col;
	int m_row;

	//statuses:
	bool m_onCake = false;
	bool m_onKey = false;
	bool m_onGift = false;
	bool m_onElf = false;


};