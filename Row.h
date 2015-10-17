#ifndef ROW_H
#define ROW_H
/*****************************************************************************
*Class Row
*
*Constructors
*
*	Row(Array2D<a_type> & in_array, int in_row)
*		takes a reference to a Array2D object and sets m_array2D to it
*		sets m_row to in_row
*
*Mutators
*
*	a_type& operator[](int in_column)
*		calls m_array2D.Select() to return a value of a_type
******************************************************************************/
template<typename a_type> class Array2D;

template<typename a_type> class Row
{
	private:
		Array2D<a_type>& m_array2D;
		int m_row;
	public:
		Row(Array2D<a_type> & in_array, int in_row);
		a_type& operator[](int in_column);
};
#include "Row.cpp"
#endif
