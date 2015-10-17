#pragma once
#include "Array2D.h"
#include "Row.h"
#include "Cell.h"

class Board
{
protected:
	Array2D<Cell> board;
	int bombs;
	int x_size;
	int y_size;
	bool game_over;
public:
	Board();
	Board(int x, int y, int num_bombs);
	void Fill_Board();
	void Fill_Empty();
	void Click(int x, int y);
	void Flag(int x, int y);
	void Reveal(int x, int y);
	void Display();
	bool getGame_Over();
};