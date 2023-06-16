#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include "Macros.h"
// ---- usings ------
using namespace std;


//Global Helping Functions:
//------------------------------------
void checkIfOpen(ifstream& file);
void CheckIfBoardExist(ifstream& file);
bool isValidBoardSize(int x, int y);
void checkallocation2D(char** allocated_mem);
void checkallocation1D(char* allocated_mem);
void free(char** data);
int getNextCol(int currentCol, int inputKey);
int getNextRow(int currentRow, int inputKey);
bool isInBoard(int nextCol, int nextRow, int boardCol, int boradRow);
int getNextColElf(int currentCol, int currentPacmanCol);
int getNextRowElf(int currentRow, int currentpacmanRow);

bool handleRegularKey(int c);
void handleSpecialKey();