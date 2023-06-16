#include "StaticObject.h"



//constructor:
StaticObject::StaticObject() {}

bool StaticObject::isEtaen()
{
	return m_Eaten;
}
void StaticObject::setEataen(bool val)
{
	m_Eaten = val;
}
void StaticObject::resetGiftType()
{
	gift_type = 0;
}

int StaticObject::getGiftType() const
{
	return gift_type;
}

//function that generates numbers between 1 and 3 (inclusive):
void StaticObject::generateRandomMode()
{
	gift_type = (rand() % 3 + 1);
}
void StaticObject::handleCollision(Wall& gameObject, Toolbar* toolbar) {}
void StaticObject::handleCollision(Door& gameObject, Toolbar* toolbar) {}
void StaticObject::handleCollision(Gift& gameObject, Toolbar* toolbar) {}
void StaticObject::handleCollision(Cookie& gameObject, Toolbar* toolbar) {}
void StaticObject::handleCollision(Key& gameObject, Toolbar* toolbar) {}