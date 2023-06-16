// prevent multiple inclusions of header file:
#pragma once
#include "DataBase.h"
#include "Define.h"
#include "StaticObject.h"
#include "Pacman.h"
// Wall abstract data type definition
class Wall : public StaticObject 
{
public:

	Wall();

	virtual void handleCollision(GameObject& gameObject, Toolbar* toolbar);
	virtual void handleCollision(Pacman& gameObject, Toolbar* toolbar);
	virtual void handleCollision(Elf& gameObject, Toolbar* toolbar);

   ~Wall();
private:
};