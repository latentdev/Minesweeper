#include "Array2D.h"
#include "Exception.h"
#include "Row.h"
/******************************************************
*Default Constructor
*Fills the members with null
*******************************************************/
template<typename a_type>
inline Array2D<a_type>::Array2D()
{
	m_array = 0;
	m_row = 0;
	m_col = 0;
}

/******************************************************
*Parameterized Constructor
*creates an array of pointers for m_array
*iterates through array creating a_type arrays for each pointer
*sets m_row to in_row
*sets m_col to in_col
*******************************************************/
template<typename a_type>
inline Array2D<a_type>::Array2D(int in_row, int in_col)
{
	m_array = new a_type*[in_row];
	for (int i = 0; i < in_row; i++)
		m_array[i] = new a_type[in_col];
	m_row = in_row;
	m_col = in_col;
}

/******************************************************
*Copy Constructor
*Takes a reference to an Array2D object and does a deep copy into m_array
*sets m_row to in_copy's row
*sets m_col to in_copy's col
*******************************************************/
template<typename a_type>
inline Array2D<a_type>::Array2D(const Array2D& in_copy)
{
	m_array = new a_type*[in_copy.getRow()];
	for (int i = 0; i < (in_copy.getRow()); i++)
	{
		m_array[i] = new a_type[in_copy.getColumn()];
		for (int m = 0; m < in_copy.getColumn(); m++)
			m_array[i][m] = in_copy[i][m];
	}
	m_row = in_copy.getRow();
	m_col = in_copy.getColumn();
}

/******************************************************
*Default Destructor
*iterates through m_array deleting each a_type array
*deletes m_array
*******************************************************/
template<typename a_type>
inline Array2D<a_type>::~Array2D()
{
	for (int i = 0; i < m_row; ++i)
		delete[] m_array[i];

	delete[] m_array;
}

/******************************************************
*Operator = Overload
* checks to make sure m_array is not already allocated memory. If it is it deletes it.
* does the same as the copy constructor
*******************************************************/
template<typename a_type>
Array2D<a_type> & Array2D<a_type>::operator=(const Array2D & in_rhs)
{
	if(m_array!=0)
	{
		for (int i = 0; i < m_row; ++i)
			delete[] m_array[i];

		delete[] m_array;
	}
	
	m_array = new a_type*[in_rhs.getRow()];
	for (int i = 0; i < (in_rhs.getRow()); i++)
	{
		m_array[i] = new a_type[in_rhs.getColumn()];
		for (int m = 0; m < in_rhs.getColumn(); m++)
			m_array[i][m] = in_rhs[i][m];
	}
	m_row = in_rhs.getRow();
	m_col = in_rhs.getColumn();
	return *this;
}

/******************************************************
*Operator [] overload
*checks bounds and throws the appropriate exception
*if no exception creates a new row using this and the passed in in_index
*returns row
*******************************************************/
template<typename a_type>
Row<a_type>& Array2D<a_type>::operator[](int in_index)
{
	if (in_index < 0) {
		throw Exception("Index smaller than lower bounds");
	}
	else if (in_index >= m_row) {
		throw Exception("Index larger than upper bounds");
	}
	else
	{
		Row<a_type>* row = new Row<a_type>(*this, in_index);
		return *row;
	}
}

/******************************************************
*Operator [] overload of the const variety
*checks bounds and throws the appropriate exception
*if no exception creates a dummy Array2D filled with the const Array2D's values
*creates a row object using the dummy Array2D and in_index
*returns row
*******************************************************/
template<typename a_type>
Row<a_type>& Array2D<a_type>::operator[](int in_index) const
{
	if (in_index < 0) {
		throw Exception("Index smaller than lower bounds");
	}
	else if (in_index >= m_row) {
		throw Exception("Index larger than upper bounds");
	}
	else
	{
		Array2D<a_type>* temp = new Array2D<a_type>(m_row, m_col);
		Row<a_type>* row = new Row<a_type>(*temp, in_index);
		for (int i = 0; i < m_row; i++) {
			(*row)[i] = m_array[in_index][i];
		}
		return *row;
	}
}
/******************************************************
*Getter for m_row
*Returns m_row
*******************************************************/
template<typename a_type>
int Array2D<a_type>::getRow() const
{
	return m_row;
}

/******************************************************
*Setter for row
*creates a temp**pointer array of the passed in size of row
*compares in_rows to m_row to determine which is shorter so we only need to iterate as many times as needed
*iterates through temp creating new a_type arrays
*fills a_type arrays with data from m_array till we hit the shorter value
*thoroughly delete m_array point m_array at temp
*set m_row to the new row number
*******************************************************/
template<typename a_type>
void Array2D<a_type>::setRow(int in_rows)
{
	int shorter = 0;
	a_type** m_array_temp = new a_type*[in_rows];

	if (in_rows > m_row)
		shorter = m_row;
	else
		shorter = in_rows;
	for (int i = 0; i < in_rows; i++) {
		m_array_temp[i] = new a_type[m_col];
	}
	for (int i = 0; i < shorter; i++)
	{
		for (int m = 0; m < m_row; m++)
			m_array_temp[i][m] = m_array[i][m];
	}
	for (int x = 0; x < m_row; x++)
		delete[] m_array[x];

	delete[] m_array;
	m_array = m_array_temp;
	m_row = in_rows;
}

/******************************************************
*Getter for m_col
*Returns m_col
*******************************************************/
template<typename a_type>
int Array2D<a_type>::getColumn() const
{
	return m_col;
}

/******************************************************
*Setter for columns
*creates a temp**pointer array size row
*compares in_columns to m_col to determine which is shorter so we only need to iterate as many times as needed
*iterates through temp creating new a_type arrays
*fills a_type arrays with data from m_array till we hit the shorter value
*thoroughly delete m_array point m_array at temp
*set m_col to the new column number
*******************************************************/
template<typename a_type>
void Array2D<a_type>::setColumn(int in_columns)
{
	int shorter = 0;
	a_type** m_array_temp = new a_type*[m_row];

	if (in_columns > m_col)
		shorter = m_col;
	else
		shorter = in_columns;

	for (int i = 0; i < m_row; i++)
	{
		m_array_temp[i] = new a_type[m_col];
		for (int m = 0; m < shorter; m++)
			m_array_temp[i][m] = m_array[i][m];
	}
	for (int x = 0; x < m_row; ++x)
		delete[] m_array[x];

	delete[] m_array;
	m_array = m_array_temp;
	m_col = in_columns;
}

/******************************************************
*Select lets us actually get the data stored in our 2d array
*Returns the data at the specified location of our 2d array
*******************************************************/
template<typename a_type>
a_type& Array2D<a_type>::Select(int in_row, int in_column)
{
	return m_array[in_row][in_column];
}
