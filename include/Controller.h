// prevent multiple inclusions of header file:
#pragma once

//includes:
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Board.h"
#include "Define.h"
#include "Toolbar.h"

class Controller
{
public:
	Controller();
	void run(sf::RenderWindow* main_window);
private:
	sf::SoundBuffer bacground_buffer;
	sf::Sound background_sound;
};