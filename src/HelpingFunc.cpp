#include "HelpingFunc.h"


//-------------------------------------------------------
//this function gets input stream file as an input
//and checks if it is open, if not it will handle it:
void checkIfOpen(ifstream& file)
{
	if (!file.is_open())
	{
		cerr << "can not open the input file\n";
		exit(EXIT_FAILURE);
	}
}
//-------------------------------------------------------
//this function gets input stream file as an input
//and checks if it is open, if not it will handle it:
void CheckIfBoardExist(ifstream& file)
{
    if (!file.is_open())
    {
        cerr << "No Board.txt Found\n";
        exit(EXIT_FAILURE);
    }
}
//-------------------------------------------------------
//check if the board size is valid:
bool isValidBoardSize(int x, int y)
{
	if (x > 0 && y > 0)
		return true;
	else
		return false;
}
//-------------------------------------------------------
// this function checks if the 2d string allocated successfully:
void checkallocation2D(char** allocated_mem)
{
	if (allocated_mem == NULL)
	{
		cerr << "can not allocate memory";
		exit(EXIT_FAILURE);
	}
}
//-------------------------------------------------------
// this function checks if the string allocated successfully:
void checkallocation1D(char* allocated_mem)
{
	if (allocated_mem == NULL)
	{
		cerr << "can not allocate memory";
		exit(EXIT_FAILURE);
	}
}
//-------------------------------------------------------
// this function deletes all the allocated memories
void free(char** data)
{
	int i;
	for (i = 0; data[i] != NULL; i++) // runs over the allocated array and deletes each cell and cell
		delete[] data[i];
	delete[] data; // finally we delete the main allocated memory
}
//-------------------------------------------------------

bool handleRegularKey(int c)
{
    switch (c)
    {
    case 'A':
        std::cout << "A pressed\n";
        break;
    case 'a':
        std::cout << "a pressed\n";
        break;
    case KB_Escape:
        std::cout << "Escape pressed. Exiting...\n";
        return true;
    default:
        std::cout << "Unknown regular key pressed (code = " << c << ")\n";
        break;
    }

    return false;
}

void handleSpecialKey()
{
    auto c = _getch();
    switch (c)
    {
    case KB_Up:
        std::cout << "Arrow Up pressed\n";
        break;
    case KB_Down:
        std::cout << "Arrow Down pressed\n";
        break;
    case KB_Left:
        std::cout << "Arrow Left pressed\n";
        break;
    case KB_Right:
        std::cout << "Arrow Right pressed\n";
        break;
    case KB_Space:
        std::cout << "Space pressed. Turn Passed\n";
        break;
    default:
        std::cout << "Unknown special key pressed (code = " << c << ")\n";
        break;
    }
}


//-------------------------------------------------------
// function that gets the input key and the current col 
// returns the new col accordingly:
int getNextCol(int currentCol, int inputKey)
{
    if (inputKey == KB_Left)
        return (currentCol - 1);
    if (inputKey == KB_Right)
        return (currentCol + 1);
    else
        return currentCol;
}
//-------------------------------------------------------
// function that gets the input key and the current row 
// returns the new row accordingly:
int getNextRow(int currentRow, int inputKey)
{
    if (inputKey == KB_Up)
        return (currentRow - 1);
    if (inputKey == KB_Down)
        return (currentRow + 1);
    else
        return currentRow;
}
//-------------------------------------------------------
// this function checks if the next move is in the board and if so
// returns true , o.w returns false:
bool isInBoard(int nextCol, int nextRow, int boardCol, int boardRow)
{
    if (nextCol > 0 && nextCol < boardCol && nextRow > 0 && nextRow < boardRow)
        return true;
    else
        return false;
}
//-------------------------------------------------------
//this function gets the col of elf and col col of pacman
//and return one col closer to the pacman
int getNextColElf(int currentCol, int currentPacmanCol)
{
    //if the pacman and the elf has the same col:
    if (currentCol == currentPacmanCol)
        return currentCol;
    //the pacman on the right of the elf:
    if (currentCol < currentPacmanCol)
        return(currentCol + 1);
    //if the pacman on the left of the elf:
    if (currentCol > currentPacmanCol)
        return (currentCol - 1);
}
//-------------------------------------------------------
//this function gets the row of elf and row ofpacman
//and return one row closer to the pacman
int getNextRowElf(int currentRow, int currentpacmanRow)
{
    //the elf and the pacman on the same row:
    if (currentRow == currentpacmanRow)
        return currentRow;
    //if the elf is under the pacman:
    if (currentRow > currentpacmanRow)
        return (currentRow - 1);
    //if the elf is above the pacman:
    if (currentRow < currentpacmanRow)
        return (currentRow + 1);
}
//-------------------------------------------------------