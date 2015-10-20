#pragma once
#include "Array2D.h"
#include "Row.h"
#include "Cell.h"
/***************************************************************
class Board

Data Members:
	Array2D<Cell> board
		this will store all the cells needed to build our board

	int bombs
		stores the number of bombs based on the difficulty

	int x_size
		width of board

	int y_size;
		height of board

	bool game_over;
		holds whether the game is over. used to break the game loop

Constructors:
	Board()
		default constructor

	Board(int x, int y, int num_bombs)
		takes a width and height and creates the board sets bombs to num_bombs

Methods:
	void Fill_Board()
		fills the board with the right number of bombs then fills in the surrounding squares with the right values

	void Fill_Empty()
		fills the board with 0's. not used in final program

	void Click(int x, int y);
		if the selected cell is not a bomb or flag it sets the cell to revealed.
		if the cell is flagged it throws and exception and doesn't reveal the cell
		if the cell is a bomb it reveals the cell and sets game_over to true

	void Flag(int x, int y);
		sets the selected cell's flagged to true

	void RemoveFlag(int x, int y);
		sets the selected cell's flagged to false

	bool CheckIfWon();
		moves through the board counting bombs and number of unrevealed tiles if they equal each other then the game is over

	void Reveal(int x, int y);
		Recursive function
		this is a cascading reveal. it reveals the selected cell then counts the number of bombs around the cell. 
		if the number of bombs = 0 and cell next the cells around this cell are larger than 0 then it reveals only them other wise if there ar only no bombs it calls the function again on the cell next to it

	void Display();
		displays the board using a square character if the cell is not revealed yet or a flag if the cell is flagged else it displays the value at the cell

	void DisplayValue()
		displays the board with all the values revealed. was used for easy debugging.

	bool getGame_Over();
		returns game_over

	void setGame_Over(bool x);
		sets game_over to the passed in x
****************************************************************/
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
	void RemoveFlag(int x, int y);
	bool CheckIfWon();
	void Reveal(int x, int y);
	void Display();
	void DisplayValue();
	bool getGame_Over();
	void setGame_Over(bool x);
};