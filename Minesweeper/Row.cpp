#include "Row.h"
#include "Array2D.h"

/******************************************************
*Constructor for Row object
*takes a reference to an Array2D object and sets m_array2D to it
*sets m_row to the passed in in_row
*******************************************************/
template<typename a_type>
Row<a_type>::Row(Array2D<a_type>& in_array, int in_row): m_array2D(in_array)
{
	m_row = in_row;
}

/******************************************************
*Operator [] overload
*checks for bounds if everything is ok then it calls m_array2D's Select function to return an a_type value
*******************************************************/
template<typename a_type>
a_type & Row<a_type>::operator[](int in_column)
{
		if (in_column < 0) {
			throw Exception("Index smaller than lower bounds");
		}
		else if (in_column >= m_array2D.getColumn()) {
			throw Exception("Index larger than upper bounds");
		}
		else
		{
			return m_array2D.Select(m_row, in_column);
		}
}
