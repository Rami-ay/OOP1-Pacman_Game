// prevent multiple inclusions of header file:
#pragma once

//includes:
#include <SFML/Graphics.hpp>
#include <memory>
#include "Toolbar.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "HelpingFunc.h"
#include "Pacman.h"
#include "SuperPacman.h"
#include "Elf.h"
#include "Door.h"
#include "Cookie.h"
#include "Wall.h"
#include "Key.h"
#include "Gift.h"
#include "DataBase.h"
#include "Define.h"
#include "StaticObject.h"
#include "GameObject.h"
// --- usings: ---
using namespace std;
enum ObjectType
{
	PacmanChar = 'a',
	SuperPacmanChar = '@',
	ElfChar = '&',
	WallChar = '#',
	DoorChar = 'D',
	KeyChar = '%',
	CookieChar = '*',
	GiftChar = '$',
};


// Board abstract data type definition
class Board
{
public:


	bool update(sf::RenderWindow& window, Toolbar* toolbar);
	void movePac(sf::Event event);
	void moveElfs();
	//constructor function:
	// ==================================
	Board();

	//function that translates chars to images :
	void convert2images();
	
	std::unique_ptr<MovingObject>&& getPacmanObj();

	//set functions:
	// ==================================
	void setTile(int col, int row, char tile);
	void setKeyNum(int newNum);
	void setDoorNum(int newNum);
	void setCakesNum(int cakesNum);
	void setRoundLost(int newnum);
	void setRoundWon(int newnum);

	//get functions:
	// ===================================
	int getboardCol() const;
	int getBoardRow() const;
	char getTile(int col, int row) const;
	int getKeyNum() const;
	int getDoorNum() const;
	int getCakesNum() const;
	int getMin() const;
	int getsec() const;
	int getRoundLost() const;
	int getRoundWon() const;
	int getPacManPlace() const;
	int getOneStage(ifstream& file);
	void createObject(ObjectType type, int currentCol, int currentRow,
		int boardCol, int boardRow);


	void handleCollisions(GameObject& gameObject,Toolbar* toolbar);

	void deleteDoor();


	void initiateBoard();
	bool validRound() const;
	void countSpecialChars(char tempChar);
	void handleInValidRound() const;
	void setObjects();
	void drawCharacters(sf::RenderWindow* main_window);
private:
	//the board dimensions:
	int m_row;
	int m_col;
	//the board itself:
	vector<vector<char>> m_board;
	Pacman m_pacman = Pacman(0, 0);
	//the board with images:
	//std::vector<vector<sf::Sprite>> m_boardSprites;
	int pacman_col, pacman_row;
	vector<Door> m_doors;
	//number of items:
	int m_startingSuperPacMan = 0;
	int m_pacmanNum = 0;
	int m_cakeNum = 0;
	int m_keysNum = 0;
	int m_doorNum = 0;
	int m_elfsNum = 0;
	int m_isSuper = 0;
	int m_SuperSteps = 0;

	
	//Objects :
	Elf* m_elfs_ch;
	vector<unique_ptr<MovingObject>> m_movable;
	vector<unique_ptr<StaticObject>> m_static;
	sf::Vector2f pacman_pos = { 725,500 };
	int pacman_place;

	int rounds_won;
	int round_lost;

	//time:
	int min;
	int sec;
	//help funtion:
	
};