#include "Board.h"
#include <time.h>
#include <sstream>

/******************************************************
*   Purpose:  default constructor

*         Entry:  none

*         Exit: sets bombs to 0
*******************************************************/
Board::Board()
{
	bombs = 0;
}

/******************************************************
*   Purpose:  constructor

*         Entry:  passed in a number of row and columns and a number of bombs

*         Exit: creates a board with the passed in rows and columns.
				sets the number of bombs to the passed in number
				then sets the boundry data members
				and sets game_over to the default false
*******************************************************/
Board::Board(int x, int y, int num_bombs)
{
	board = *(new Array2D<Cell>(x, y));
	bombs = num_bombs;
	x_size = x;
	y_size = y;
	game_over = false;
}

/******************************************************
*   Purpose:  fills the board up with bombs and numbers

*         Entry:  none

*         Exit: places bombs based on an x and y that are chosen randomly. then increments the value around the bomb by one as long as it's in bounds

*******************************************************/
void Board::Fill_Board()
{
	int num_bombs = bombs;
	srand(time(NULL));
	while (num_bombs > 0)
	{
		int x = rand() % x_size;
		int y = rand() % y_size;

		if (board[x][y].getValue() != 9)
		{
			board[x][y].setValue(9);
			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					//Bounds checking
					if ((x + i < x_size && x + i >= 0) && (y + j < y_size && y + j >= 0)) {
						if ((i != 0 || j != 0) && (board[x+i][y+j].getValue() != 9)) {
							board[x + i][y + j].setValue(board[x + i][y + j].getValue() + 1);
						}
					}
				}
			}
		}
		num_bombs -- ;
	}
}

/******************************************************
*   Purpose:  fills the board with zeroes

*         Entry:  none

*         Exit: goes through the array filling it with zeroes. not used in final game
*******************************************************/
void Board::Fill_Empty()
{
	for (int i = 0; i < x_size; i++)
	{
		for (int m = 0; m < y_size; m++)
		{
			board[i][m].setValue(0);
		}
	}

}

/******************************************************
*   Purpose:  reveals the spot chosen by the user

*         Entry:  none

*         Exit: checks to see if its a bomb or flag. if it's a bomb end the game. if it's a flag do nothing. else call Reveal()
*******************************************************/
void Board::Click(int x,int y)
{
	if (board[x][y].getValue() != 9 && board[x][y].getFlagged()!=true)
	{
		Reveal(x, y);
	}
	else if (board[x][y].getFlagged() == true)
	{
		cout << "Cannot reveal because of flag" << endl;
	}
	else
	{
		string a;
		game_over = true;
		cout << "Game Over! You hit a bomb!" << endl<<"Press any key to continue:";
		getline(cin, a);
		system("cls");
	}
}

/******************************************************
*   Purpose:  sets the specific cell as flagged

*         Entry:  passes in an x and y

*         Exit: sets the cell's flagged at x and y equal to true;
*******************************************************/
void Board::Flag(int x, int y)
{
	board[x][y].setFlagged(true);
}

/******************************************************
*   Purpose:  sets the specific cell as not flagged

*         Entry:  passes in an x and y

*         Exit: sets the cell's flagged at x and y equal to false;
*******************************************************/
void Board::RemoveFlag(int x, int y)
{
	board[x][y].setFlagged(false);
}

/******************************************************
*   Purpose:  checks if the game is in a win state

*         Entry:  none

*         Exit: walks through the board counting up bombs and unrevealed cells. if they are equal than the game is won.
*******************************************************/
bool Board::CheckIfWon()
{
	int num_unrevealed = 0;
	int num_bombs = 0;
	for (int i = 0; i < x_size; i++)
		for (int m = 0; m < y_size;m++)
		{
			if (board[i][m].getRevealed() == false)
				num_unrevealed++;
			if (board[i][m].getValue() == 9)
				num_bombs++;
		}
	if (num_unrevealed == num_bombs)
		return true;
	else
		return false;
}

/******************************************************
*   Purpose:  recursive function that reveals the cell and all cells around it that arent a bomb

*         Entry:  passes in an x and y

*         Exit: sets the cell at x and y as revealed and then counts the number of bombs around the cell.
				if the number of bombs around the cell are 0 and teh cells are greater than zero only reveal them.
				if the number of bombs around the cell are 0 and there are cells that are equal to 0 then call Reveal() on them
*******************************************************/
void Board::Reveal(int x, int y)
{
	int num_bombs = 0;
	if (board[x][y].getRevealed() == true)
		return;
	board[x][y].setRevealed(true);

		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				if ((x + i < x_size && x + i >= 0) && (y + j < y_size && y + j >= 0)) {
					if ((i != 0 || j != 0) && (board[x + i][y + j].getValue() == 9))
					{
						num_bombs++;
					}
					if (num_bombs == 0 && board[x + i][y + j].getValue()>0)
						board[x + i][y + j].setRevealed(true);
					else if (num_bombs == 0)
					{
						Reveal(x + i, y + j);
					}
				}
			}
		}

}

/******************************************************
*   Purpose:  output the board's current layout

*         Entry:  none

*         Exit: walks through the board putting out a square if the cell is not revealed and the value if it's not a bomb. if a cell has been flagged then a flag is output
*******************************************************/
void Board::Display()
{
	system("cls");
	char blank = 254;
	char flag = 173; //'\u2691';
	for (int i = 0; i < x_size; i++)
	{
		for (int m = 0; m < y_size; m++)
		{
			if (board[i][m].getFlagged() == true)
				cout << flag;
			else if (board[i][m].getRevealed() == true)
				cout << board[i][m].getValue();
			else
				cout <<blank;
		}
		cout << endl;
	}
}

/******************************************************
*   Purpose:  outputs the board as their values

*         Entry:  none

*         Exit: walks through the board outputting each cells value.
				Only used for quick debugging
*******************************************************/
void Board::DisplayValue()
{
	for (int i = 0; i < x_size; i++)
	{
		for (int m = 0; m < y_size; m++)
			cout << board[i][m].getValue();
		cout << endl;
	}
}

/******************************************************
*   Purpose:  getter for game_over

*         Entry:  none

*         Exit: returns game_over
*******************************************************/
bool Board::getGame_Over()
{
	return game_over;
}

/******************************************************
*   Purpose:  setter for game_over

*         Entry:  passed in bool

*         Exit: sets game_over to the passed in bool
*******************************************************/
void Board::setGame_Over(bool x)
{
	game_over = x;
}
