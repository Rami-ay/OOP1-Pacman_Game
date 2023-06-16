// prevent multiple inclusions of header file:
#pragma once
#include "DataBase.h"
#include "Define.h"
#include "GameObject.h"

class Wall;
class Gift;
class Door;
class Key;
class Cookie;

class StaticObject : public GameObject
{
public:
	StaticObject();
	bool isEtaen();
	void setEataen(bool val);
	void resetGiftType();
	int getGiftType() const;
	void generateRandomMode();
	virtual void handleCollision(Wall& gameObject, Toolbar* toolbar);
	virtual void handleCollision(Door& gameObject, Toolbar* toolbar);
	virtual void handleCollision(Gift& gameObject, Toolbar* toolbar);
	virtual void handleCollision(Cookie& gameObject, Toolbar* toolbar);
	virtual void handleCollision(Key& gameObject, Toolbar* toolbar);


protected:
	
	bool m_Eaten = false;
};