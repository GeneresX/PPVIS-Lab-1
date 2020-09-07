#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class matrixs {
public:
	int row, col;
	vector<vector<int>> cell;

	void setrc(int r, int c) {
		row = r;
		col = c;
	}
	void fill_rand(){
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cell[i][j] = rand() % 10 + 1;
			}
		}
	}
	void view()
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

	matrixs operator + (matrixs & other) 	//сложение двух матриц
	{
		matrixs tmp;
		if (this-> row == other.row & this-> col == other.col)
		{
			for (int i = 0; i < this-> row; i++)
			{
				for (int j = 0; j < this->col; j++)
				{
					tmp.cell[i][j] = this->cell[i][j] + other.cell[i][j];
				}
			}
		}
		return tmp;
	}
	
	matrixs operator + (int number) 	//сложение матрицы и числа
	{
		matrixs tmp;
		for (int i = 0; i < this->row; i++)
		{
			for (int j = 0; j < this->col; j++)
			{
				tmp.cell[i][j] = this->cell[i][j] + number;
			}
		}
		return tmp;
	}
	
	matrixs operator - (matrixs & other) 	//разность двух матриц
	{
		matrixs tmp;
		if (this->row == other.row & this->col == other.col)
		{
			for (int i = 0; i < this->row; i++)
			{
				for (int j = 0; j < this->col; j++)
				{
					tmp.cell[i][j] = this->cell[i][j] - other.cell[i][j];
				}
			}
		}
		return tmp;
	}

	matrixs operator - (int number) //разность матрицы и числа
	{
		matrixs tmp;
		for (int i = 0; i < this->row; i++)
		{
			for (int j = 0; j < this->col; j++)
			{
				tmp.cell[i][j] = this->cell[i][j] - number;
			}
		}
		return tmp;
	}

	matrixs operator * (matrixs & other) 
	{
		if (this->col == other.row) 
		{

		}
	}
    //произведение матриц
	//произведение матрицы и числа
	//возведение в степень матрицы 
    //детерминант
	//норма
};

int main()
{
	matrixs matrix;
	int buf1, buf2;
	cout << "pls, set matrix sizes: row, then col :" << endl;
	cin >> buf1 >> buf2;
	matrix.setrc(buf1, buf2);
	cout << matrix.row << matrix.col;
}
