#pragma once
#include "Board.h"
/*******************************************************************
class Minesweeper

Data Members:
	Board * board
		pointer to our board

	char diff_select
		char used to hold the difficulty select choice

	string input
		string used to handle all input for the game
Constructors:
	Minesweeper()
		creates an empty board and sets diff_select to null

Methods:
	void difficulty()
		handles difficulty select and creates a board the appropriate size for the difficulty
	
	void Input()
		displays a menu, handles the input and calls the appropriate function for the menu choice
	
	void Step()
		single step of the minesweeper game also checks to see if the game has been won. to be called in Loop() to create the game loop.

	void Loop()
		Recursive function
		this is the game loop. calls difficulty() then fills the board based on the difficulty then loops Step() till game_over == true. 
		calls itself at the end to repeate the cycle for a new game.
*******************************************************************/
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