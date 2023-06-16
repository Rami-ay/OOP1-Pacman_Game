//progma once prevent us from including
//multiple times:
#pragma once
// --- includes --- 
#include <SFML/Graphics.hpp>
#include <SFML/system.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include "Define.h"
#include "DataBase.h"
#include <sstream>
#include <chrono>
// ---- namspaces ---
using namespace std;
// ------------------


class Toolbar
{
public:
	//constructor:
	Toolbar(sf::Vector2f rect_size, sf::Vector2f pos, sf::Clock theClock, int min, int sec);
	~Toolbar();
	void decreaseLife();
	void increaseLevel();
	void increasePoints(int points_to_add);
	void increaselife();
	void draw(sf::RenderWindow* main_window, sf::Clock theClock);
	int getLives() const;
	int getMin() const;
	int getSecs() const;
	int getRemainingTime() const;
	bool getFreezeMode() const;
	bool getSuperPacMode() const;
	void freezeModeON();
	void freezeModeOFF();
	void superPacON();
	void superPacOFF();
	sf::Clock getFreezeClock() const;



	bool isFrozen() const;
	void setSecs(int newSec);
	void setMin(int newMin);


private:
	int m_level;
	int m_points;
	sf::RectangleShape m_toolbar_background;
	vector<sf::Sprite> m_lives;

	//freeze members:
	bool freeze_status;
	sf::Clock freezClock;
	sf::Sprite freeze_mode;


	//texts:
	sf::Text clock_text;
	sf::Text level_text;
	sf::Text points_text;
	//font:
	sf::Font font;

	//time limitaion:
	int m_min;
	int m_sec;
	int remaining_time;

};