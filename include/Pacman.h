// prevent multiple inclusions of header file:
#pragma once
#include "DataBase.h"
#include "Define.h"
#include "MovingObject.h"
#include "StaticObject.h"
#include "Toolbar.h"
#include "Elf.h"
#include "Door.h"
// Pacman abstract data type definition
class Pacman : public MovingObject
{
public:
	//constructor functions:
	//------------------------------------------------
	Pacman();
	Pacman(int col, int row);
	//set functions:
	// ==================================
	void setPacman(int newCol, int newRow);
	//get functions:
	// ==================================
	int getPacmanCol() const;
	int getPacmanRow() const;
	

	void superPacman(MovingObject& m);
	void playFreezeSong();
	void PlayHeartSong();
	void PlayTimeSong();

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

	sf::SoundBuffer Eat_buffer;
	sf::Sound Eat_song;

	sf::SoundBuffer death_buffer;
	sf::Sound death_song;

	sf::SoundBuffer freeze_buffer;
	sf::Sound freeze_song;

	sf::SoundBuffer heart_buffer;
	sf::Sound heart_song;

	sf::SoundBuffer time_buffer;
	sf::Sound time_song;
};