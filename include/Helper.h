//progma once prevent us from including
//multiple times:
#pragma once
// --- includes --- 
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

#include "Button.h"
// ---- namspaces ---
using namespace std;
using namespace sf;
// ------------------


class Helper
{

public:
	Helper();
	void help_run(RenderWindow* main_window);

private:
	
	//wallpaper items:
	sf::Texture help_wallPaper;
	//wallpaper spirits
	sf::Sprite help_wallPaperSprite;
	//back button:
	Button back_button;
	//font:
	sf::Font font;

	//help function:
	bool back_click(RenderWindow* main_window, const sf::Event::MouseButtonEvent& event);
};