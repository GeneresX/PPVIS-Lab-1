#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

using namespace std;

/**
\file
\brief A class that implements mathematical operations on matrices.
This class implements the following methods:

addition of two matrices.

addition of a matrix with a number.

subtraction of two matrices.

subtracting a number from a matrix.

product of two matrices.

matrix-number product.

dividing a matrix by a number.

exponentiation of a matrix.

calculation of the norm .
*/

class Matrix {
public:

	Matrix();

	Matrix(int row, int col);

	Matrix(vector<vector<int>> tmpCell);
	/**
	Sets the number of rows and columns.
	\param [in] row Number of lines.
	\param [in] col Number of columns.
	*/
	void setRowCol(int row, int col);

	/// Getting the number of lines.
	int getRow();

	/// Getting the number of columns.
	int getCol();

	/**
	Sets the number of rows and columns.
	\param [in] row The required line.
	\param [in] col The required column.
	\return Get the value of a cell in a matrix.
	*/
	int getCell(int row, int col);

	/**
	Changing the value of a cell in a matrix.
	\param [in] row The required line.
	\param [in] col The required column.
	\param [in] number The number by which to change the value of the cell.
	*/
	void setCell(int row, int col, int number);

	/** 
	\brief Filling the selected matrix with random numbers.
	Filling occurs from 1 to 11.
	*/
	void fillRandom();

	/// Display of the selected matrix on the screen.
	void view();

	/**
	A method that implements the addition of two matrices.
	\param [in] &other Link to the second matrix.
	\return The result of matrix addition.
	*/
	Matrix operator + (Matrix& other);

	/**
	A method that implements the addition of two matrices.
	\param [in] &other Link to the second matrix.
	\return Result of subtraction of matrices.
	*/
	Matrix operator - (Matrix& other);

	/**
	A method that implements matrix multiplication by a number.
	\param [in] number The number by which the matrix is multiplied.
	\return Matrix multiplied by a number.
	*/
	Matrix operator * (int number);

	/**
	A method that allows you to add a number to a matrix.
	\param [in] number The number that is added to the matrix.
	\return Matrix increased by a number.
	*/
	Matrix operator + (int number);

	/**
	A method that allows you to subtract a number from the matrix.
	\param [in] number The number that is subtracted from the matrix.
	\return The matrix is reduced by a number.
	*/
	Matrix operator - (int number);

	/**
	A method that allows you to multiply matrices.
	\param [in] &other Link to the second matrix.
	\return The multiplied matrix.
	*/
	Matrix operator * (Matrix& other);


	void makeMinor(Matrix& minor, Matrix originalMatrix, int size, int rowDelete, int colDelete);

	int determinant(Matrix originMatrix);

	/**
	A method to raise a matrix to a power.
	\param [in] number A number indicating the degree to which the matrix should be raised.
	\return Matrix raised to a power.
	*/
	Matrix operator ^ (int number);

	/// Calculation of the matrix norm by the first method.
	/// \return The maximum value of the sum among all columns.
	int firstNorm();

	/// Calculation of the matrix norm by the second method.
	/// \return The root of the sum of the squares of all matrix cells.
	int secondNorm();

	/// Calculation of the matrix norm by the third method.
	/// \return The maximum value of the sum among all lines.
	int thirdNorm();

private:
	int row, col;
	vector<vector<int>> cell;

	/**
Helper method for implementing exponentiation of a matrix. Multiplies matrices.
\param [in] matrix1 Depending on the situation.
Either the original matrix, or multiplied by itself (n - 1) times.
\param [in] matrix2 The original matrix.
\return The matrix is multiplied by itself.
*/
	Matrix power(Matrix matrix1, Matrix matrix2);
};

#endif //MATRIX_H