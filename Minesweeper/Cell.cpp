#include "Cell.h"

/******************************************************
*Default Constructor
*Fills the members with null
*******************************************************/
Cell::Cell()
{
	value = 0;
	revealed = false;
	flagged = false;
}

/******************************************************
*Parameterized Constructor
*sets value to x  and revealed and flagged to false
*******************************************************/
Cell::Cell(int x)
{
	value = x;
	revealed = false;
	flagged = false;
}

/******************************************************
*   Purpose:  getter for value

*         Entry:  none

*         Exit: returns data member value
*******************************************************/
int Cell::getValue()
{
	return value;
}

/******************************************************
*   Purpose:  setter for value

*         Entry:  the value to set data member value is passed in as x

*         Exit: sets data member value to the passed in x
*******************************************************/
void Cell::setValue(int x)
{
	value = x;
}

/******************************************************
*   Purpose:  getter for revealed

*         Entry:  none

*         Exit: returns data member revealed
*******************************************************/
bool Cell::getRevealed()
{
	return revealed;
}

/******************************************************
*   Purpose:  setter for revealed

*         Entry:  the value to set data member revealed is passed in as x

*         Exit: sets data member revealed to the passed in x
*******************************************************/
void Cell::setRevealed(bool x)
{
	revealed = x;
}

/******************************************************
*   Purpose:  getter for flagged

*         Entry:  none

*         Exit: returns data member flagged
*******************************************************/
bool Cell::getFlagged()
{
	return flagged;
}

/******************************************************
*   Purpose:  setter for flagged

*         Entry:  the value to set data member flagged is passed in as x

*         Exit: sets data member flagged to the passed in x
*******************************************************/
void Cell::setFlagged(bool x)
{
	flagged = x;
}