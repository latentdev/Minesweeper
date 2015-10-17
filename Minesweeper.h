#pragma once
#include "Board.h"

class  Minesweeper
{
protected:
	Board * board;
	char diff_select;
	string input;
public:
	Minesweeper();
	void difficulty();
	void Input();
	void Step();
	void Loop();
};