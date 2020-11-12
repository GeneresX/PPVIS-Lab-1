#include "Matrix.h"
#include <iostream>
/// \file
using namespace std;

Matrix::Matrix() {		//����������� �� ���������
	row = 0; col = 0;
}

Matrix::Matrix(int row, int col) {		//����������� ������ � �����������
	this->row = row; 
	this->col = col;
	this->cell.resize(row);
	for (int i = 0; i < row; i++) {
		this->cell[i].resize(col);
		for (int j = 0; j < col; j++) {
			this->cell[i][j] = 0;
		}
	}
}

Matrix::Matrix(vector<vector<int>> tmpCell) {

	this->row = tmpCell.size();
	this->col = tmpCell[0].size();
	this->cell.resize(tmpCell.size());

	for (int i = 0; i < row; i++) {
		this->cell[i].resize(col);
		for (int j = 0; j < col; j++) {
			this->cell[i][j] = 0;
		}
	}

	for (int i = 0; i < tmpCell.size(); i++)	{
		for (int j = 0; j < tmpCell[0].size(); j++)
		{
			this->cell[i][j] = tmpCell[i][j];
		}
	}
}






void Matrix::setRowCol(int row, int col) {		//��������� �������� row � col
	this->row = row; this->col = col;
}

int Matrix::getRow() { return this->row; }

int Matrix::getCol() { return this->col; }

int Matrix::getCell(int row, int col) { return this->cell[row-1][col-1]; }

void Matrix::setCell(int row, int col, int number) { this->cell[row-1][col-1] = number; }

void Matrix::fillRandom() {						//���������� ���������� �������
	int tmp;
	for (int i = 0; i < this->row; i++) {
		cell.push_back(vector<int>());
		for (int j = 0; j < this->col; j++) {
			tmp = rand() % 10 + 1;
			cell[i].push_back(tmp);
		}
	}
}

void Matrix::view()							//�������� �������
{
	for (int i = 0; i < row; i++)
	{
		cout << endl << endl;
		for (int j = 0; j < col; j++)
		{
			cout << cell[i][j] << "\t";
		}
	}
}

Matrix Matrix::power(Matrix matrix1, Matrix matrix2) {
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->row; j++) {
			matrix1.cell[i][j] = 0;
			for (int t = 0; t < this->row; t++) {
				matrix1.cell[i][j] += this->cell[i][t] * matrix2.cell[t][j];
			}
		}
	}
	return matrix1;
}

Matrix Matrix::operator + (Matrix& secondMatrix) 													//�������� ���� ������
{
	Matrix tmpMatrix(this->row, this->col);															//����������� � �������� ������� ���� �� ��������� ������

	if (row != secondMatrix.row || col != secondMatrix.col) { throw "������ ������� �������."; }
	else {
		for (int i = 0; i < this->row; i++) {
			for (int j = 0; j < this->col; j++) {
				tmpMatrix.cell[i][j] = this->cell[i][j] + secondMatrix.cell[i][j];					//������ �������� ����� �� �����
			}
		}
	}
	return tmpMatrix;
}

Matrix Matrix::operator - (Matrix& secondMatrix) 														//�������� ���� ������
{
	Matrix tmpMatrix(this->row, this->col);																	 //����������� � �������� ������� ���� �� ��������� ������

	if (row != secondMatrix.row || col != secondMatrix.col) { throw "������ ������ �������."; }
	else {
		for (int i = 0; i < this->row; i++) {
			for (int j = 0; j < this->col; j++) {
				tmpMatrix.cell[i][j] = this->cell[i][j] - secondMatrix.cell[i][j];									//������ �������� ����� �� �����
			}
		}
	}
	return tmpMatrix;
}

Matrix Matrix::operator * (int number)							//��������� ������� �� �����
{
	Matrix result = *this;
	for (int i = 0; i < result.row; i++) {
		for (int j = 0; j < result.col; j++) {
			result.cell[i][j] = result.cell[i][j] * number;
		}
	}
	return result;
}

Matrix Matrix::operator + (int number) 							//�������� ������� � �����
{
	Matrix result = *this;
	for (int i = 0; i < result.row; i++) {
		for (int j = 0; j < result.col; j++) {
			result.cell[i][j] = result.cell[i][j] + number;
		}
	}
	return result;
}

Matrix Matrix::operator - (int number)							//�������� ������� � �����
{
	Matrix result = *this;
	for (int i = 0; i < result.row; i++) {
		for (int j = 0; j < result.col; j++) {
			result.cell[i][j] = result.cell[i][j] - number;
		}
	}
	return result;
}

Matrix Matrix::operator * (Matrix& secondMatrix) { 																		// ������������ ���� ������
	if (this->col != secondMatrix.row) 
		throw "��������� ������ ����������. ������� ����� � ������� �� ���������.";

	Matrix tmpMatrix(this->row, secondMatrix.col);

	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < secondMatrix.col; j++) {
			tmpMatrix.cell[i][j] = 0;
			for (int t = 0; t < this->col; t++) {
				tmpMatrix.cell[i][j] += this->cell[i][t] * secondMatrix.cell[t][j];
			}
		}
	}
	return tmpMatrix;																			 //������ �������� ������� ��� ���������� �����
}

Matrix Matrix::operator ^ (int number) { 															// ���������� ������� � �������

	if (number < 1) throw "���������� � ������� ����������, ������� ������ ���� >= 1";
	if (this->col != this->row) throw "���������� � ������� ����������, ������� �� ����������.";

	Matrix originalMatrix = *this; 
	Matrix tmpMatrix(this->row, this->col);

	tmpMatrix = originalMatrix;
	for (int degree = 1; degree < number; degree++) {
		tmpMatrix = tmpMatrix.power(tmpMatrix, originalMatrix);
	}
	return tmpMatrix;
}

void Matrix::makeMinor(Matrix &minor, Matrix originalMatrix, int size, int rowDelete, int colDelete) {
	for (int i = 0, iminor = 0; i < size; ++i) {
		if (i == rowDelete) continue;
		for (int j = 0, jminor = 0; j < size; ++j) {
			if (j == colDelete) continue;
			minor.cell[iminor][jminor] = originalMatrix.cell[i][j];
			++jminor;
		}
		++iminor;
	}
}

int Matrix::determinant(Matrix matrix) {

	if (matrix.row == 1) return matrix.cell[0][0];
	if (matrix.row == 2) 
		return matrix.cell[0][0] * matrix.cell[1][1] - matrix.cell[0][1] * matrix.cell[1][0];	// ������� ������
	int det = 0;																								 // ��� �����������
	Matrix tmpMatrix(matrix.row - 1, matrix.row - 1);																// ������� ���������� ������ ��� ������
	for (int l = 0; l < matrix.row; l++) {
		makeMinor(tmpMatrix, matrix, matrix.row, 0, l);
		det += (l % 2 ? -1 : 1) * matrix.cell[0][l] * determinant(tmpMatrix);											// ��������� ������������
	}
	return det;
}

int Matrix::firstNorm() {
	int sum;
	int* array = new int[this->col];
	for (int i = 0; i < this->col; i++) {
		sum = 0;
		for (int j = 0; j < this->row; j++) {
			sum += this->cell[j][i];
		}
		array[i] = sum;
	}
	int max = array[0];
	for (int i = 0; i < this->col; ++i) {
		if (array[i] > max) {
			max = array[i];
		}
	}
	delete[] array;
	return max;
}

int Matrix::secondNorm() {
	int x = 0, sum = 0;
	int* array = new int[this->col * this->row];
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->col; j++) {
			array[x] = this->cell[i][j] * this->cell[i][j];
			x++;
		}
	}
	for (int i = 0; i < this->col * this->row; i++) {
		sum += array[i];
	}
	delete[] array;
	return sum;
}

int Matrix::thirdNorm() {
	int sum;
	int* array = new int[this->row];
	for (int i = 0; i < this->row; i++) {
		sum = 0;
		for (int j = 0; j < this->col; j++) {
			sum += this->cell[i][j];
		}
		array[i] = sum;
	}
	int max = array[0];
	for (int i = 0; i < this->col; ++i) {
		if (array[i] > max) {
			max = array[i];
		}
	}
	delete[] array;
	return max;
}
