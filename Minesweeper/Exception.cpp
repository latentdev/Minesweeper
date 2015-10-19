#include "Exception.h"
/************************************
*Default Constructor
*Does nothing
*************************************/
Exception::Exception()
{
}

/************************************
*Parameterized Constructor
*stores the size of in_msg in bytes in length
*creates a new array of size length+1
*does a deep copy of in_msg into m_msg
*adds a null to the end of m_msg
*************************************/
Exception::Exception(char * in_msg)
{
	size_t length = strlen(in_msg);
	m_msg = new char[length+1];

	for(int i = 0; i < length; i++) {
		m_msg[i] = in_msg[i];
	}
	m_msg[length] = '\0';
}

/**************************************************************
*Copy Constructor
*copy constructor
*creates a new array for m_msg and does a deep copy of in_copy
***************************************************************/
Exception::Exception(const Exception & in_copy)
{
	m_msg = new char[strlen(in_copy.m_msg)];

	for (int i = 0; i < strlen(in_copy.m_msg); i++) {
		m_msg[i] = in_copy.m_msg[i];
	}
}
/**************************************************************
*default destructor
***************************************************************/
Exception::~Exception()
{
	delete m_msg;
}

/*************************************************************
*overloaded = operator
*creates a new array for m_msg
*does a deep copy of in_rhs.m_msg into m_msg
*returns this object
**************************************************************/
Exception & Exception::operator=(const Exception & in_rhs)
{
	m_msg = new char[strlen(in_rhs.m_msg)];
	for (int i = 0; i < strlen(in_rhs.m_msg); i++)
	{
		m_msg[i] = in_rhs.m_msg[i];
	}
	return *this;
}

/*************************************************************
*Getter for m_msg
* returns m_msg
**************************************************************/
char * Exception::getMessage()
{
	return m_msg;
}

/************************************************************
*Setter for m_msg
*Deletes current m_msg
*creates a new character array for m_msg the length of in_msg
*does a deep copy of in_msg to m_msg
*************************************************************/
void Exception::setMessage(char * in_msg)
{
	delete m_msg;
	m_msg = new char[strlen(in_msg)];

	for (int i = 0; i < strlen(in_msg); i++) {
		m_msg[i] = in_msg[i];
	}
}
/**********************************************************
*operator overload for <<
*allows us to pass a an exception to the ostream to be outputted
*returns the passed in exceptions message
***********************************************************/
ostream & operator<<(ostream & in_stream, const Exception& in_except)
{
	return in_stream << in_except.m_msg;
}
