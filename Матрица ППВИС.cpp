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
	//сложение двух матриц
	//сложение матрицы с числом
	//вычитание двух матриц
	//вычитание и матрицы числа
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