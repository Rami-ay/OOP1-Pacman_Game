#include "Toolbar.h"



//constructor:
Toolbar::Toolbar(sf::Vector2f rect_size, sf::Vector2f pos, sf::Clock theClock, int min, int sec) : 
	m_min{min}, m_sec{sec}
{
	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
	remaining_time = m_min * 60 + m_sec;
	//background rectangle settings:
	m_toolbar_background.setFillColor(sf::Color::Transparent);
	m_toolbar_background.setSize(rect_size);
	m_toolbar_background.setPosition(pos);

	// freeze mode Sprite:
	freeze_status = false;
	freeze_mode = m_database.freezeSprite;
	freeze_mode.setColor(sf::Color(240, 240, 240,150));
	freeze_mode.setPosition(m_toolbar_background.getPosition().x + 3 * (m_toolbar_background.getGlobalBounds().width / 5),
		m_toolbar_background.getPosition().y);

	  
	//life sprites:
	for (int i = 0; i < 3; i++)
	{
		sf::Sprite temp = m_database.lifeSprite;
		m_lives.push_back(temp);
		m_lives[i].setPosition(m_toolbar_background.getPosition().x + 4* (m_toolbar_background.getGlobalBounds().width / 5) + (i * 40),
			m_toolbar_background.getPosition().y);
	}
	m_level = 0;
	m_points = 0;
	//the clock text:
	clock_text.setFont(font);
	clock_text.setCharacterSize(16);
	clock_text.setFillColor(sf::Color::Yellow);
	clock_text.setPosition(m_toolbar_background.getPosition().x, m_toolbar_background.getPosition().y + 10);

	//the level text:
	level_text.setString("Level: " + std::to_string(m_level));
	level_text.setFont(font);
	level_text.setCharacterSize(16);
	level_text.setFillColor(sf::Color::Yellow);
	level_text.setPosition(m_toolbar_background.getPosition().x + (m_toolbar_background.getGlobalBounds().width /5),
		m_toolbar_background.getPosition().y + 10);
	//the points text:
	points_text.setString("Points: " + std::to_string(m_points));
	points_text.setFont(font);
	points_text.setCharacterSize(16);
	points_text.setFillColor(sf::Color::Yellow);
	points_text.setPosition(m_toolbar_background.getPosition().x + 2*(m_toolbar_background.getGlobalBounds().width / 5),
		m_toolbar_background.getPosition().y + 10);


}
//destructor:
Toolbar::~Toolbar() {}

//this function increases the level by 1:
void Toolbar::increaseLevel()
{
	m_level++;
	level_text.setString("Level: " + std::to_string(m_level));
}

//this function increases the points:
void Toolbar::increasePoints(int points_to_add)
{
	m_points = m_points + points_to_add;
	points_text.setString("Points: " + std::to_string(m_points));
}

void Toolbar::decreaseLife()
{
	if(!m_lives.empty())
		m_lives.pop_back();
}

void Toolbar::increaselife()
{
	if (m_lives.size() < 3)
	{
		sf::Sprite temp = m_database.lifeSprite;
		m_lives.push_back(temp);
		m_lives[m_lives.size() - 1].setPosition(m_lives[m_lives.size() - 2].getPosition().x + 48,
			m_lives[m_lives.size() - 2].getPosition().y);
	}
}

void Toolbar::freezeModeON()
{
	freeze_status = true;
	freezClock.restart();
	freeze_mode.setColor(m_database.freezeSprite.getColor());
}
void Toolbar::freezeModeOFF()
{
	freeze_status = false;
	freezClock.restart();
	freeze_mode.setColor(sf::Color(240, 240, 240, 150));
}

sf::Clock Toolbar::getFreezeClock() const
{
	return freezClock;
}

bool Toolbar::isFrozen() const
{
	return freeze_status;
}

void Toolbar::draw(sf::RenderWindow* main_window, sf::Clock theClock)
{
	//Getting the elapsed time
	sf::Time elapsed = theClock.getElapsedTime();
	int elapsed_time = elapsed.asSeconds();
	//Calculating the remaining time
	remaining_time = (m_min * 60 + m_sec) - elapsed_time;
	//If time is up, set remaining time to 0
	if (remaining_time < 0) 
		remaining_time = 0;
	//Calculating the remaining minutes and seconds
	int remaining_minutes = remaining_time / 60;
	int remaining_seconds = remaining_time % 60;


	//Updating the clock text
	std::stringstream ss;
	ss << std::setfill('0') << std::setw(2) << remaining_minutes << ":" << std::setfill('0') << std::setw(2) << remaining_seconds;
	clock_text.setString(ss.str());
	//start drawing:
	main_window->draw(m_toolbar_background);
	main_window->draw(level_text);
	main_window->draw(points_text);
	main_window->draw(clock_text);
	main_window->draw(freeze_mode);
	//draw the lives:
	for (int i = 0; i < m_lives.size(); i++)
		main_window->draw(m_lives[i]);
}

int Toolbar::getLives() const
{
	return (m_lives.size());
}


int Toolbar::getMin() const	
{
	return m_min;
}
int Toolbar::getSecs() const
{
	return m_sec;
}

int Toolbar::getRemainingTime() const
{
	return remaining_time;
}
bool Toolbar::getFreezeMode() const
{
	return freeze_status;
}



void Toolbar::setMin(int newMin)
{
	m_min = newMin;
}
void Toolbar::setSecs(int newSec)
{
	 m_sec = newSec;
}