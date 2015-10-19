#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>
/************************************************************************
*Class: Exception
*
*Constructors:
*	Exception()
*		default constructor
*
*	Exception(char * in_msg)
*		stores the size of in_msg in bytes in length 
*		creates a new array of size length+1
*		does a deep copy of in_msg into m_msg
*		adds a null to the end of m_msg
*
*	Exception(const Excepion& in_copy)
*		copy constructor
*		creates a new array for m_msg and does a deep copy of in_copy
*
*	~Exception()
*		deletes m_msg;
*
*
*Mutators:
*	void setMessage(char* in_msg)
*		deletes current m_msg
*		takes an takes a char pointer and does a deep copy of it into m_msg.
*
*
*	Array& operator=(Array& rhs)
*		operator overload =
*		Pulls m_length and m_start_index and stores them in this instances m_length and m_start_index
*		Frees up current space allocated by m_array and then does a deep copy from rhs.m_array
*
*	a_type& operator<<(int index)
*		returns ostream of index.m_msg
*
*
*Methods:
*	int getMessage()
*		returns m_msg.
*
*
*************************************************************************/
using namespace std;
class Exception
{
	private:
		char * m_msg;
	public:
		Exception();
		Exception(char*in_msg);
		Exception(const Exception& in_copy);
		~Exception();

		Exception& operator=(const Exception& in_rhs);

		char* getMessage();
		void setMessage(char* in_msg);
		friend ostream& operator<<(ostream & in_stream, const Exception&);
};
#endif

