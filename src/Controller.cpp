#include "Controller.h"


Controller::Controller()
{
	bacground_buffer.loadFromFile("beep.wav");
	background_sound.setBuffer(bacground_buffer);
	background_sound.setLoop(true);
}

void Controller::run(sf::RenderWindow* main_window)
{
	background_sound.play();
	bool round_end;
	ifstream file;
	file.open("Board.txt");
	main_window->setFramerateLimit(120);
	Board game_board = Board();
	//start the game
	game_board.getOneStage(file);
	//start the game clock:
	sf::Clock theClock;
	theClock.restart();
	//initiate the toolbar:
	Toolbar toolbar = Toolbar({ (float)game_board.getboardCol() * 48,48 }, { 725 - ((float)game_board.getboardCol() * 48 / 2),
		500 - ((float)game_board.getBoardRow() * 48 / 2) - 30 }, theClock, game_board.getMin(), game_board.getsec());

	for (int round = 0; round < 3; round++)
	{
		//song.play();
		round_end = false;
		theClock.restart();
		toolbar.increaseLevel();
		toolbar.setMin(game_board.getMin()); toolbar.setSecs(game_board.getsec());
		toolbar.freezeModeOFF();
		sf::Clock elf_clock, pacman_clock; // create a clock to track time since last move
		elf_clock.restart(); // start the elf clock
		pacman_clock.restart();
		while (main_window->isOpen() && round_end == false)
		{

			//Clear window
			main_window->clear();


			//drwaings:
			//====================================
			//draw the board:
			game_board.drawCharacters(main_window);
			//draw the toolbar:
			toolbar.draw(main_window, theClock);

			//Display on the window:
			main_window->display();

			if (toolbar.getFreezeMode() == false)
			{

				if (elf_clock.getElapsedTime().asSeconds() >= 0.15) // check if 0.3 seconds have passed
				{
					game_board.moveElfs(); // move the elf
					round_end = game_board.update(*main_window, &toolbar);
					elf_clock.restart(); // restart the clock
				}
			}
			else
			{
				if (toolbar.getFreezeClock().getElapsedTime().asSeconds() > 10)
				{
					toolbar.freezeModeOFF();
				}
			}  
			if (game_board.getPacmanObj()->getISuper() == true)
			{
				if (pacman_clock.getElapsedTime().asSeconds() >= 15) // check if 15 seconds have passed
				{
					// pacman.reset();
					game_board.getPacmanObj()->resetSuperPacman();
					pacman_clock.restart();
				}
			}
			//catching events:
			if (auto event = sf::Event{}; main_window->pollEvent(event))
			{

				switch (event.type)
				{
					//closing window:
				case sf::Event::Closed:
					main_window->close();
					break;
					//handle pacman movement:
				case sf::Event::KeyPressed:
					game_board.movePac(event);
					round_end = game_board.update(*main_window, &toolbar);
					break;
				}
			}
			if (toolbar.getRemainingTime() <= 0)
			{
				game_board.setRoundLost(game_board.getRoundLost() + 1);
				round_end = true;
			}
		}
		if (round < 2)
			game_board.getOneStage(file);
	}
}