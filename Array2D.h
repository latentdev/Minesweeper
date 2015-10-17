#ifndef ARRAY2D_H
#define ARRAY2D_H
#include "Row.h"

/************************************************************************
*Class: Array2D
*
*Constructors:
*	Array2D()
*		default constructor
*
*	Array2D(int in_row,int in_col)
*		creates a 2d array named m_array using the passed in variables for size
*		sets m_row to in_row
*		sets m_col to in_col
*
*	Array2D(const Array2D& in_rhs)
*		copy constructor
*		creates a new 2d array and does a deep copy of in_rhs
*
*	~Array2D()
*		iterates through m_array to delete each of the arrays stored in it then deletes m_array;
*
*
*Mutators:
*	void setRow(int in_rows)
*		creates a temp ** array of new row number
*		deep copies m_array into temp with respect to the new row number
*		deep deletes m_array
*		points m_array at temp
* 
*	void setColumn(int in_columns)	
*		creates a temp ** array of m_row length
*		deep copies m_array into temp with respect to the new in_columns
*		deep deletes m_array
*		points m_array at temp
*
*	Array& operator=(const Array2D& in_rhs)
*		operator overload =
*		checks to make sure there is no memory allocated to m_array. If there is it deletes it.
*		creates new 2d array and does a deep copy of in_rhs
*
*	Row<a_type>& operator[](int in_index)
*		operator[] overload
*		checks for out of bounds
*		Returns a Row Object that is created passing in *this and in_index
*
*	Row<a_type>& operator[](int in_index) const
*		operator[] overload of the const variety
*		checks for out of bounds
*		creates a dummy Array2D to store the const objects data in
*		Returns a Row Object that is created passing in dummy Array2D and in_index
*	
*Methods:
*	int getRow()
*		returns m_row
*
*	int getColumn()
*		returns m_col
*
*	a_type& Select(int in_row,int in_column)
*		returns the data stored at specified location of m_array
*
*
*************************************************************************/
template<class a_type> class Array2D
{
private:
	a_type** m_array;
	int m_row;
	int m_col;
public:
	Array2D();
	Array2D(int in_row, int in_col);
	Array2D(const Array2D& in_copy);
	~Array2D();
	Array2D& operator=(const Array2D& in_rhs);
	Row<a_type>& operator[](int in_index);
	Row<a_type>& operator[](int in_index) const;
	int getRow() const;
	void setRow(int in_rows);
	int getColumn() const;
	void setColumn(int in_columns);
	a_type& Select(int in_row, int in_column);

};
#include "Array2D.cpp"
#endif
