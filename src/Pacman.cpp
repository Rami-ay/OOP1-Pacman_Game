#include "Pacman.h"

//constructor functions:
//--------------------------
Pacman::Pacman() : m_col{ 0 }, m_row{ 0 }
{
	Eat_buffer.loadFromFile("pacman_chomp.wav");
	death_buffer.loadFromFile("pacman_death.wav");
	freeze_buffer.loadFromFile("freez.wav");
	heart_buffer.loadFromFile("heart.wav");
	time_buffer.loadFromFile("Stopwatch.wav");

	//SuperPac_buffer.loadFromFile("")

	Eat_song.setBuffer(Eat_buffer);
	Eat_song.setVolume(35);
	Eat_song.setPitch(1.75f);

	death_song.setBuffer(death_buffer);
	
	freeze_song.setBuffer(freeze_buffer);

	heart_song.setBuffer(heart_buffer);

	time_song.setBuffer(time_buffer);


}
Pacman::Pacman(int col, int row) : m_col{ col }, m_row{ row } 
{
	Eat_buffer.loadFromFile("pacman_chomp.wav");
	death_buffer.loadFromFile("pacman_death.wav");
	freeze_buffer.loadFromFile("freez.wav");
	heart_buffer.loadFromFile("heart.wav");
	time_buffer.loadFromFile("Stopwatch.wav");

	//SuperPac_buffer.loadFromFile("")

	Eat_song.setBuffer(Eat_buffer);
	Eat_song.setVolume(35);
	Eat_song.setPitch(1.75f);

	death_song.setBuffer(death_buffer);

	freeze_song.setBuffer(freeze_buffer);

	heart_song.setBuffer(heart_buffer);

	time_song.setBuffer(time_buffer);
}
//--------------------------
//set functions:
// ==========================
//function that set the Pacman location on the board:
void Pacman::setPacman(int newCol, int newRow)
{
	m_col = newCol;
	m_row = newRow;
}

//get functions:
// =========================

// function that return the Pacman Col:
int Pacman::getPacmanCol() const
{
	return(m_col);
}
//--------------------------
// function that return the Pacman Row:
int Pacman::getPacmanRow() const
{
	return(m_row);
}
//--------------------------
void Pacman::handleCollision(GameObject& gameObject, Toolbar* toolbar)
{
	gameObject.handleCollision(*this, toolbar);
}
void Pacman::handleCollision(Pacman& gameObject,Toolbar* toolbar){}
void Pacman::handleCollision(Elf& gameObject,Toolbar* toolbar)
{
	if (!is_super) 
	{
		
		m_sprite.setPosition(m_startPosition);
		gameObject.reset();
		toolbar->decreaseLife();
		death_song.play();
	}
	else if (is_super)
	{
		//Do Nothing
	}

}
void Pacman::handleCollision(Wall& gameObject, Toolbar* toolbar)
{
	m_sprite.setPosition(m_prevPosition);
}
void Pacman::handleCollision(Door& gameObject, Toolbar* toolbar)
{
	if (!is_super)
	{
		m_sprite.setPosition(m_prevPosition);
	}
}
void Pacman::handleCollision(Gift& gameObject, Toolbar* toolbar)
{
	activeSuperPacman();
	toolbar->increasePoints(5);
}
void Pacman::handleCollision(Cookie& gameObject, Toolbar* toolbar)
{
	Eat_song.play();
	toolbar->increasePoints(2);

}
void Pacman::handleCollision(Key& gameObject, Toolbar* toolbar)
{
	toolbar->increasePoints(7);
}

void Pacman::superPacman(MovingObject& m)
{
	is_super = true;
	m_sprite.setColor(sf::Color::Red);
}

void Pacman::playFreezeSong()
{
	freeze_song.play();
}
void Pacman::PlayHeartSong()
{
	heart_song.play();
}

void Pacman::PlayTimeSong()
{
	time_song.play();
}
