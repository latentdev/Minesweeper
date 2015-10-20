#pragma once
/***************************************************************
class Cell

data members
	int value
		holds value from 0-9, 0-8 represents # of bombs around the cell and 9 is a bomb
	
	bool revealed
		holds whether the cell has been revealed or not

	bool flagged
		holds whether the cell has been flagged or not

constructors
	Cell()
		default constructor

	Cell(int x)
		sets value to the passed in int and sets revealed and flagged to false

	int getValue()
		returns value

	void setValue(int x)
		sets value to the passed in x

	bool getRevealed()
		returns revealed

	void setRevealed(bool x)
		sets revealed to the passed in x

	bool getFlagged()
		returns flagged

	void setFlagged(bool x)
		sets flagged to the passed in x

*****************************************************************/
class Cell
{
protected:
	int value;
	bool revealed;
	bool flagged;
public:
	Cell();
	Cell(int x);
	int getValue();
	void setValue(int x);
	bool getRevealed();
	void setRevealed(bool x);
	bool getFlagged();
	void setFlagged(bool x);
};