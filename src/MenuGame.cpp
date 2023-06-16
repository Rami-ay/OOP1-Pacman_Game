#include "MenuGame.h"

//constructor:
//---------------------
MenuGame::MenuGame()
{
	m_window = new sf::RenderWindow(VideoMode(1450, 950), "Pacman");
	m_window->setFramerateLimit(120);
	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
	start_button.setButtonInfo("Start Game", { 200,50 }, 30, sf::Color::Transparent, sf::Color::Yellow,{625,500},font);
	help_button.setButtonInfo("Help", { 200,50 }, 30, sf::Color::Transparent, sf::Color::Yellow, { 625,600 }, font);
	exit_button.setButtonInfo("Exit Game", { 200,50 }, 30, sf::Color::Transparent, sf::Color::Yellow, { 625,700 }, font);

	//Wallpaper load and sprite
	//-----------------------------------------------------
	; if (!wallPaper.loadFromFile("PacmanWallpaper.jpg"))
	{
		//handle loading error:
		std::cout << "Error in loading" << std::endl;
	}
	wallPaperSprite = sf::Sprite(wallPaper);
	wallPaperSprite.setPosition(275, 100);

	//-----------------------------------------------------

	while (m_window->isOpen())
	{
		//clear window
		m_window->clear();
		
		//drwaings:
		//====================================
		//draw wallpaper:
		m_window->draw(wallPaperSprite);

		//draw buttons:
		m_window->draw(start_button.getbutton());
		m_window->draw(start_button.getext());

		m_window->draw(help_button.getbutton());
		m_window->draw(help_button.getext());

		m_window->draw(exit_button.getbutton());
		m_window->draw(exit_button.getext());

		//Display on the window:
		m_window->display();

		//catching events:
		if (auto event = sf::Event{}; m_window->waitEvent(event))
		{
			switch (event.type)
			{
				//closing window:
			case sf::Event::Closed:
				m_window->close();
				break;
				//mouse clicked:
			case sf::Event::MouseButtonReleased:
				handleClick(event.mouseButton);
				break;
				//mouse houvering over buttons:
			case sf::Event::MouseMoved:
				// ======== hovering over start button: =========
				if (start_button.isMouseOver(*m_window))
				{
					start_button.setTextColor(sf::Color::Blue);
				}
				else
					start_button.setTextColor(sf::Color::Yellow);
				// ==============================================
				// ======== hovering over Help button: =========
				if (help_button.isMouseOver(*m_window))
				{
					help_button.setTextColor(sf::Color::Blue);
				}
				else
					help_button.setTextColor(sf::Color::Yellow);
				// ==============================================
				// ======== hovering over Exit button: =========
				if (exit_button.isMouseOver(*m_window))
				{
					exit_button.setTextColor(sf::Color::Red);
				}
				else
					exit_button.setTextColor(sf::Color::Yellow);
				// ==============================================
			}
		}
		

	}
	exit(EXIT_SUCCESS);
}


//-------------------------------------------------------------------
//This function takes event as input and handle it accordingly:
void MenuGame::handleClick(const sf::Event::MouseButtonEvent& event)
{

	//if the user pressed the start game button:
	if (start_button.getbutton().getGlobalBounds().contains(
		m_window->mapPixelToCoords({ event.x, event.y })))
	{
		Controller c = Controller();
		c.run(m_window);
		//start the game
		/*Board game_board = Board();
		game_board.getOneStage();
		game_board.board_run(m_window);*/
	}
	//if the user pressed the Help  button:
	if (help_button.getbutton().getGlobalBounds().contains(
		m_window->mapPixelToCoords({ event.x, event.y })))
	{
		Helper help_page = Helper();
		help_page.help_run(m_window);
	}
	//if the user pressed the exit game button:
	if (exit_button.getbutton().getGlobalBounds().contains(
		m_window->mapPixelToCoords({ event.x, event.y })))
	{
		m_window->close();
	}

}
//-------------------------------------------------------------------