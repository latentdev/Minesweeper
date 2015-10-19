#include "Board.h"
#include <time.h>
#include <sstream>

Board::Board()
{
	//board = NULL;
	bombs = 0;
}

Board::Board(int x, int y, int num_bombs)
{
	board = *(new Array2D<Cell>(x, y));
	bombs = num_bombs;
	x_size = x;
	y_size = y;
	game_over = false;
}
void Board::Fill_Board()
{
	//Fill_Empty();
	int num_bombs = bombs;
	srand(time(NULL));
	while (num_bombs > 0)
	{
		
		int x = rand() % x_size;
		int y = rand() % y_size;
		//Cell*temp = board[x][y];
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

void Board::Click(int x,int y)
{
	if (board[x][y].getValue() != 9 && board[x][y].getFlagged()!=true)
	{
		//board[x][y].setRevealed(true);
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

void Board::Flag(int x, int y)
{
	board[x][y].setFlagged(true);
}

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

bool Board::getGame_Over()
{
	return game_over;
}