#include "Minesweeper.h"
#include <iostream>
#include <sstream>

/******************************************************
*   Purpose:  default constructor for Minesweeper

*         Entry:  none

*         Exit: creates a new empty board and sets diff_select to false
*******************************************************/
Minesweeper::Minesweeper()
{
	board = new Board();
	diff_select = NULL;
}

/******************************************************
*   Purpose:  handles the difficulty select

*         Entry:  none

*         Exit: displays a menu for the user to pick from and creates a board that is set for the difficulty selected
*******************************************************/
void Minesweeper:: difficulty()
{
	cout << "b = beginner" << endl << "i = intermediate" << endl << "e = expert" << endl << "Please choose difficulty:";
	getline(cin,input);

	if (input.length() == 1)
		diff_select = input[0];

	if (diff_select == 'b' || diff_select == 'B')
		board = new Board(10, 10, 10);
	else if (diff_select == 'i' || diff_select == 'I')
		board = new Board(16, 16, 40);
	else if (diff_select == 'e' || diff_select == 'E')
		board = new Board(16, 30, 100);
}

/******************************************************
*   Purpose:  handles the input for the actual game

*         Entry:  none

*         Exit: displays menu for the user to select from then calls the appropriate function to deal with the input
*******************************************************/
void Minesweeper::Input()
{
	int x;
	int y;
	int choice;
	cout <<"1.Reveal a square"<<endl<<"2.Place a flag"<<endl << "3.Remove a flag" << endl << "4.Exit" <<endl << "Enter the number of your choice:" << endl;
	cin >> choice;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
	{
		throw Exception("Please enter a valid number");
		Input();
	}

	else if (choice == 1)
	{
		cout << "Please enter x coordinate:";
		getline(cin, input);
		istringstream(input) >> y;

		cout << "Please enter y coordinate:";
		getline(cin, input);
		istringstream(input) >> x;
		board->Click(x, y);
	}
	else if (choice == 2)
	{
		cout << "Please enter x coordinate of flag:";
		getline(cin, input);
		istringstream(input) >> y;

		cout << "Please enter y coordinate of flag:";
		getline(cin, input);
		istringstream(input) >> x;
		board->Flag(x, y);
	}
	else if (choice == 3)
	{
		cout << "Please enter x coordinate of flag you want to remove:";
		getline(cin, input);
		istringstream(input) >> y;

		cout << "Please enter y coordinate of flag you want to remove:";
		getline(cin, input);
		istringstream(input) >> x;
		board->RemoveFlag(x, y);
	}
	else if (choice == 4)
		exit(0);
}

/******************************************************
*   Purpose:  one step of the game of minesweeper

*         Entry:  none

*         Exit: outputs the board and displays a menu asking the user to input there choice
				call CheckIfWon() to determine if the game has been won
*******************************************************/
void Minesweeper::Step()
{
	board->Display();
	Input();
	if (board->CheckIfWon() == true)
	{
		cout << "You won!" << endl;
		board->setGame_Over(true);
	}
}

/******************************************************
*   Purpose:  main game loop for minesweeper

*         Entry:  none

*         Exit: call difficulty() then fills the board based on the chosen difficulty. loops till game_over = true. then calls itself to restart the game.
*******************************************************/
void Minesweeper::Loop()
{
	difficulty();
	board->Fill_Board();
	while (board->getGame_Over() != true)
	{
		try {
			Step();
		}
	catch (const Exception& e) {
		cout << e << endl;
	}
	
	}
	Loop();
}