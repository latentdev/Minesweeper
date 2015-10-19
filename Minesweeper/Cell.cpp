#include "Cell.h"

Cell::Cell()
{
	value = 0;
	revealed = false;
	flagged = false;
}
Cell::Cell(int x)
{
	value = x;
	revealed = false;
	flagged = false;
}
int Cell::getValue()
{
	return value;
}

void Cell::setValue(int x)
{
	value = x;
}
bool Cell::getRevealed()
{
	return revealed;
}

void Cell::setRevealed(bool x)
{
	revealed = x;
}

bool Cell::getFlagged()
{
	return flagged;
}

void Cell::setFlagged(bool x)
{
	flagged = x;
}