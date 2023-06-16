// --- includes --- 
#include <SFML/Graphics.hpp>
#include "Helper.h"
// ------------------


//constructor:
//the costructor renders a window of size 1450X1050 and loads the help
//page that already contains the instructions.
//displays the help page on window
//the help page is not suppose to do anything and shoul only
//close when the player choose to:
Helper::Helper()
{
	//Wallpaper load and sprite
	//-----------------------------------------------------
	if (!help_wallPaper.loadFromFile("Helper.jpg"))
	{
		//handle loading error:
		std::cout << "Error in loading" << std::endl;
	}
	help_wallPaperSprite = sf::Sprite(help_wallPaper);
	help_wallPaperSprite.setPosition(50, 100);
	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
	back_button.setButtonInfo("Back", { 200,50 }, 40, sf::Color::Transparent, sf::Color::Red, { 600,800 }, font);
	back_button.setBold();
}
//-------------------------------------------------------------------
//this function handles the help page:
void Helper::help_run(RenderWindow* main_window)
{
	bool condition = false;
	while (main_window->isOpen() && condition == false)
	{
		//clear window
		main_window->clear();

		//drwaings:
		//====================================
		//draw wallpaper:
		main_window->draw(help_wallPaperSprite);

		//draw buttons:
		main_window->draw(back_button.getbutton());
		main_window->draw(back_button.getext());


		//Display on the window:
		main_window->display();

		//catching events:
		if (auto event = sf::Event{}; main_window->waitEvent(event))
		{
			switch (event.type)
			{
				//closing window:
			case sf::Event::Closed:
				main_window->close();
				break;
				//mouse clicked:
			case sf::Event::MouseButtonReleased:
				condition = back_click(main_window, event.mouseButton);
				break;
				//mouse houvering over buttons:
			case sf::Event::MouseMoved:
				// ======== hovering over start button: =========
				if (back_button.isMouseOver(*main_window))
				{
					back_button.setTextColor(sf::Color::Blue);
				}
				else
					back_button.setTextColor(sf::Color::Red);

			}
		}
	}
}
//-------------------------------------------------------------------
//this function handles the back button click:
bool Helper::back_click(RenderWindow* main_window, const sf::Event::MouseButtonEvent& event)
{
	if (back_button.getbutton().getGlobalBounds().contains(
		main_window->mapPixelToCoords({ event.x, event.y })))
	{
		return true;
	}
	else
		return false;
}
//-------------------------------------------------------------------