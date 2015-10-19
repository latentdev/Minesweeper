#pragma once
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