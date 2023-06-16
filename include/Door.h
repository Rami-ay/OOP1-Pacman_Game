// prevent multiple inclusions of header file:
#pragma once
#include <iosfwd>
#include "DataBase.h"
#include "Define.h"
#include "Pacman.h"
#include "StaticObject.h"
// Door abstract data type definition
class Door : public StaticObject

{
public:
    Door();


    //get functions
    int getDoorCol() const;
    int getDoorRow() const;

    //set functions:
    void setDoorCol(int newCol);
    void setDoorRow(int newRow);

    virtual void handleCollision(GameObject& gameObject,Toolbar* toolbar);
    virtual void handleCollision(Pacman& gameObject, Toolbar* toolbar);
    virtual void handleCollision(Elf& gameObject, Toolbar* toolbar);

private:
    int m_col = 0; // x
    int m_row = 0; // y

    sf::Sprite m_sprite = m_database.doorSprite;
};