//progma once prevent us from including
//multiple times:
#pragma once
// --- includes --- 
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include "Button.h"
#include "Helper.h"
#include "Board.h"
#include "Controller.h"
// ---- namspaces ---
using namespace std;
using namespace sf;
// ------------------

class MenuGame
{
public:
	//constructor:
	MenuGame();

	
private:
	//our menu's window:
	RenderWindow* m_window;
	
	//menu items:
	sf::Texture wallPaper;
	//menu spirits
	sf::Sprite wallPaperSprite;

	//buttons:
	Button start_button;
	Button help_button;
	Button exit_button;

	//font:
	sf::Font font;
	
	//sound
	sf::SoundBuffer backSound;
	sf::Sound song;

	//Help Functions:
	// ====================================
	//function to handle mouse clicks:
	void handleClick(const sf::Event::MouseButtonEvent& event);
	/*void handleMouseOver(Button which_button);*/
};