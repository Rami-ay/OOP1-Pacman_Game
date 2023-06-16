// include definition of Board Class from Board.h:
#include "Board.h"

bool Board::update(sf::RenderWindow& window, Toolbar* toolbar)
{
	
	for (auto& movable : m_movable)
	{
		if (typeid(*movable) == typeid(Pacman))
		{
			pacman_pos = movable->getSpritePos();
			handleCollisions(*movable, toolbar);
			if (toolbar->getLives() == 0)
			{
				round_lost++;
				return true;
			}
		}
		handleCollisions(*movable, toolbar);
		for (auto& unmovable : m_static)
		{
			if (typeid(*unmovable) == typeid(Key))
			{
				if (unmovable->isEtaen()) {
					deleteDoor();
				}
			}
			handleCollisions(*unmovable, toolbar);
		}
		std::erase_if(m_static, [](auto& unmovable)
			{
				return unmovable->isEtaen();
			});
	}
	// check for remaining cookies
	int remainingCookies = std::count_if(m_static.begin(), m_static.end(), [](auto& unmovable) {
		return typeid(*unmovable) == typeid(Cookie) && !unmovable->isEtaen();
		});
	if (remainingCookies == 0) 
	{
		rounds_won++;
		return true;
	}
	return false;
}


void Board::movePac(sf::Event event)
{
	m_movable[pacman_place]->handleInput(event);
}

void Board::moveElfs()
{
	for (int i = 0; i < m_movable.size(); i++)
	{
		if (i == pacman_place)
		{
			//DO NOTHING!
		}
		else
		{
			m_movable[i]->moveElf(m_col, m_row, m_movable[pacman_place]->getSpritePos(), m_static, 0.35);
		}
	}
}
//constructor:
// ==================================
Board::Board() : m_col{ 0 }, m_row{ 0 }, m_pacmanNum{ 0 }, m_cakeNum{ 0 }, m_keysNum{ 0 }, m_doorNum{ 0 }
, rounds_won { 0 }, round_lost{ 0 }
{
	//initiate the board with spaces:
	initiateBoard();
}
//------------------------------------------------------
//this function takes file as input and it loads one stage 
//from file
int Board::getOneStage(ifstream& file)
{
	
	//checking if the file opened successfully:
	CheckIfBoardExist(file);
	//var that hold chars from the file:
	char tempChar;
	int throwEndOfLine;
	int runRow = 0, runCol = 0;
	//vars that holds the board dimentions:
	int boardCol, boardRow;
	

	//saving the board dimensions:
	//------------------------------------
	//first the number of rows (height):
	file >> boardRow;
	//the the number of cols:
	file >> boardCol;
	//get the minutes:
	file >> min;
	//get the seconds:
	file >> sec;
	//------------------------------------
	//if the size is valid:
	if (isValidBoardSize(boardCol, boardRow))
	{
		m_col = boardCol;
		m_row = boardRow;
		
	}
	//if not:
	else
	{
		cerr << "the board dimensions are not valid!\n";
		exit(EXIT_FAILURE);
	}
	//------------------------------------
	//initiate the board with spaces:
	initiateBoard();
	//restore members:
	m_startingSuperPacMan = 0;
	m_pacmanNum = 0;
	m_cakeNum = 0;
	m_keysNum = 0;
	m_doorNum = 0;
	m_elfsNum = 0;
	m_isSuper = 0;
	m_SuperSteps = 0;
	//get the \n after we got the dimensisons:
	file.get(tempChar);
	while (runRow < m_row)
	{
		file.get(tempChar);
		//run over the line until we get \n or EOF
		while (tempChar != '\n' && !file.eof())
		{

			//stor how many pacmas,cakes,keys and doors on the board:
			countSpecialChars(tempChar);
			//copy the board from the file into the private member:
			m_board[runRow][runCol] = tempChar;
			//move to the next char:
			runCol++;
			//get new char from the file:
			file.get(tempChar);
		}
		//start new line now:
		runCol = 0;
		runRow++;
	}
	//check if the Round's board is valid and handle it if not:
	handleInValidRound();
	//now we know that the round is valid and we want to set the objects locations:
	setObjects();
	//if the vectors are full then clear them:
	m_movable.clear();
	m_static.clear();
	//now store the board as sprites:
	convert2images();
}
//------------------------------------------------------
//set functions:
// =====================
//this function sets the current tile to the given tile
void Board::setTile(int col, int row, char tile)
{
	m_board[row][col] = tile;
}
//------------------------------------------------------
//this function sets the current key number to new number:
void Board::setKeyNum(int newNum)
{
	m_keysNum = newNum;
}
//------------------------------------------------------
//this function sets the current door number to new number:
void Board::setDoorNum(int newNum)
{
	m_doorNum = newNum;
}
//------------------------------------------------------
//this function set the current cake number to new number:
void Board::setCakesNum(int cakesNum)
{
	m_cakeNum = cakesNum;
}
//------------------------------------------------------
void Board::setRoundLost(int newnum)
{
	round_lost = newnum;
}
void Board::setRoundWon(int newnum)
{
	rounds_won = newnum;
}

//get functions:
// =====================
//this function returns the board's col:
int Board::getboardCol() const
{
	return(m_col);
}
//------------------------------------------------------
//this function returns the board's row:
int Board::getBoardRow() const
{
	return (m_row);
}
//------------------------------------------------------
// this function returns the tile:
char Board::getTile(int col, int row) const
{
	return m_board[row][col];
}
//------------------------------------------------------
//function that returns the number of keys:
int Board::getKeyNum() const
{
	return m_keysNum;
}
//------------------------------------------------------
//function that returns the number of doors:
int Board::getDoorNum() const
{
	return m_doorNum;
}
//------------------------------------------------------
//function that returs the number of cakes:
int Board::getCakesNum() const
{
	return m_cakeNum;
}
//------------------------------------------------------
int Board::getMin() const
{
	return min;
}
int Board::getsec() const
{
	return sec;
}
int Board::getRoundLost() const
{
	return round_lost;
}
int Board::getRoundWon() const
{
	return rounds_won;
}
int Board::getPacManPlace() const
{
	return pacman_place;
}

//Helping functions:
// =====================
//function that initiate the board with spaces:
void Board::initiateBoard()
{
	if (m_board.size() != 0)
	{
		m_board.clear();
	}
	// run over the board and initiate it with spaces ' ':
	for (int i = 0; i < m_row; i++)
	{
		//create temp vector:
		vector<char>temp;
		//run over the run vector and initate it with spaces:
		for (int j = 0; j < m_col; j++)
		{
			temp.push_back(' ');
		}
		//push back the space vector temp to the board:
		m_board.push_back(temp);
	}
}
//------------------------------------------------------
//check if the round is valid according to the 
//given conditions:
bool Board::validRound() const
{
	//if we have one packman and its in it's normal condition
	// and at least we have one cake, and the number of keys equals the doors:
	if ((m_pacmanNum == 1) && (m_startingSuperPacMan == 0)
		&& (m_cakeNum >= 1) && (m_keysNum == m_doorNum))
		return true;
	else
		return false;
}
//------------------------------------------------------
//this function gets a char and check if it is a pacman,superPacman,
//cake,key or door and if so increases the relevant private member:
void Board::countSpecialChars(char tempChar)
{
	
	if (tempChar == 'a')
		m_pacmanNum++;
	if (tempChar == '*')
		m_cakeNum++;
	if (tempChar == '%')
		m_keysNum++;
	if (tempChar == 'D')
		m_doorNum++;
	if (tempChar == '@')
		m_startingSuperPacMan++;
	if (tempChar == '&')
		m_elfsNum++;
}
//------------------------------------------------------
// this function check if the round is invalid and handles
// the error:
void Board::handleInValidRound() const
{
	if (validRound() == false)
	{
		cerr << "The Round Is Not Valid \n";
		exit(EXIT_FAILURE);
	}
}
//------------------------------------------------------
//this function runs over the member board and set each
// elf , door and the packman's locations on the board:
void Board::setObjects()
{
	int elfIndex = 0;
	//preparing memory for all the elfs:
	m_elfs_ch = new(nothrow) Elf[m_elfsNum];
	if (m_elfs_ch == NULL)
	{
		cerr << "cannot allocate memory\n";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			if (m_board[i][j] == 'a')
				m_pacman.setPacman(j, i);

			if (m_board[i][j] == '&')
			{
				if (elfIndex < m_elfsNum)
				{
					Elf temp = Elf(j, i);
					m_elfs_ch[elfIndex] = temp;
					elfIndex++;
				}
			}
			if (m_board[i][j] == 'D')
			{
				Door temp;
				temp.setDoorCol(j);
				temp.setDoorRow(i);
				//push back the door vector temp to the board:
				m_doors.push_back(temp);
			}
		}
	}
}
//------------------------------------------------------
//this function runs over the board filled with chars,
//convert the chars to sprites and store it new board of sprites:
void Board::convert2images()
{
	
	//the rectangle starting point:
	int current_row = 0, current_col = 0;
	// run over the board and convert it  to sprites in m_boardSprites:
	for (int i = 0; i < m_row; i++)
	{
		
		for (int j = 0; j < m_col; j++)
		{
			createObject((ObjectType)m_board[i][j],j,i,m_col,m_row);
		}
	}
}
//-------------------------------------------------------------------
//this function draws all the character on the given window:
void Board::drawCharacters(sf::RenderWindow* main_window)
{
	//draw statics:
	for (int i = 0; i < m_static.size(); i++)
	{
		m_static[i]->draw(main_window);
	}
	//draw movings:
	for (int i = 0; i < m_movable.size(); i++)
	{
		m_movable[i]->draw(main_window);
	}

}


static std::unique_ptr<MovingObject> createMovableObject(ObjectType type, int currentCol, int currentRow,
	int boardCol, int boardRow)
{
	std::unique_ptr<MovingObject> temp;
	switch (type)
	{
	case ObjectType::PacmanChar:
		temp = std::make_unique<Pacman>();
		temp->initObjectPac(currentCol, currentRow, boardCol, boardRow, m_database.pacmanSprite);

		return temp;

	case ObjectType::ElfChar :
		temp = std::make_unique<Elf>();
		temp->initObject(currentCol, currentRow, boardCol,boardRow, m_database.elfSprite);
		return temp;
	}

	return nullptr;
}

static std::unique_ptr<StaticObject> createStaticObject(ObjectType type, int currentCol, int currentRow,
	int boardCol, int boardRow)
{
	std::unique_ptr<StaticObject> temp;
	switch (type)
	{
	case ObjectType::WallChar:
		temp = std::make_unique<Wall>();
		temp->initObject(currentCol, currentRow, boardCol, boardRow, m_database.wallSprite);
		return temp;
	case ObjectType::CookieChar:
		temp = std::make_unique<Cookie>();
		temp->initObject(currentCol, currentRow, boardCol, boardRow,m_database.cookieSprite);
		return temp;
	case ObjectType::KeyChar:
		temp = std::make_unique<Key>();
		temp->initObject(currentCol, currentRow, boardCol, boardRow, m_database.keySprite);
		return temp;
	case ObjectType::DoorChar:
		temp = std::make_unique<Door>();
		temp->initObject(currentCol, currentRow, boardCol, boardRow, m_database.doorSprite);
		return temp;
	case ObjectType::GiftChar:
		temp = std::make_unique<Gift>();
		temp->generateRandomMode();

		// gift that adds 30 seconds
		if (temp->getGiftType() == 1)
		{
			temp->initObject(currentCol, currentRow, boardCol, boardRow, m_database.HourGlassSprite);
		}
		//gift that freezes the elfs:
		else if (temp->getGiftType() == 2)
		{
			temp->initObject(currentCol, currentRow, boardCol, boardRow, m_database.SnowFlakeSprite);
		}
		//gift that adds life:
		else if (temp->getGiftType() == 3)
		{
			temp->initObject(currentCol, currentRow, boardCol, boardRow, m_database.giftLifeSprite);
		}
		
		return temp;
	}
	
	return nullptr;
}
void Board::createObject(ObjectType type, int currentCol, int currentRow,
	int boardCol, int boardRow)
{
	std::unique_ptr<MovingObject> movable = createMovableObject(type,currentCol,currentRow,boardCol,boardRow);
	if (movable)
	{
		switch (type)
		{
		case ObjectType::PacmanChar:
			m_movable.push_back(std::move(movable));
			pacman_place = m_movable.size() - 1;
			return;
		case ObjectType::ElfChar:
			m_movable.push_back(std::move(movable));
			return;
		}
		m_movable.push_back(std::move(movable));
		return;
	}

	std::unique_ptr<StaticObject> unmovable = createStaticObject(type, currentCol, currentRow, boardCol, boardRow);
	if (unmovable)
	{
		m_static.push_back(std::move(unmovable));
		return;
	}
}


void Board::handleCollisions(GameObject& gameObject,Toolbar* toolbar)
{
	for (auto& unmovable : m_static)
	{
		if (gameObject.checkCollision(*unmovable))
		{
			gameObject.handleCollision(*unmovable, toolbar);
		}
	}

	for (auto& movable : m_movable)
	{
		if (gameObject.checkCollision(*movable))
		{
			gameObject.handleCollision(*movable, toolbar);
		}
	}
}

void Board::deleteDoor()
{
	for (auto& unmovable : m_static)
	{
		if (typeid(*unmovable) == typeid(Door))
		{
			unmovable->setEataen(true);
			break;
		}
	}
}

std::unique_ptr<MovingObject>&& Board::getPacmanObj()
{
	return std::move(m_movable[pacman_place]);
}