#include "Minesweeper.h"
#include <iostream>
//#include <string>
#include <sstream>

Minesweeper::Minesweeper()
{
	board = new Board();
	diff_select = NULL;
}

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

void Minesweeper::Input()
{
	int x;
	int y;
	//char temp;
	int choice;
	cout <<"1.Reveal a square"<<endl<<"2.Place a flag"<<endl << "3.Exit" << endl << "Enter the number of your choice:" << endl;
	cin >> choice;
	//choice = temp - '0';
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (choice != 1 && choice != 2 && choice != 3)
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
		exit(0);
}

void Minesweeper::Step()
{
	//difficulty();
	//board->Fill_Board();
	board->Display();
	Input();
}

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
}