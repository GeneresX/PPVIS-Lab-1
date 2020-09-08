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
	void fill_rand()
	{
		int tmp;
		for (int i = 0; i < row; i++) {
			cell.push_back(vector<int>()); 
			for (int j = 0; j < col; j++) {
				tmp = rand() % 10 + 1;
				cell[i].push_back(tmp); 
			}
		}
	}
	void view()
	{
		for (int i = 0; i < this->row; i++)
		{
			cout << endl << endl;
			for (int j = 0; j < this->col; j++)
			{
				cout << this->cell[i][j] << "\t";
			}
		}
		cout << endl << endl;
	}

	matrixs operator + (matrixs & other) 	//сложение двух матриц
	{
		matrixs tmpm;  //создание буферной матрицы

		if ( row == other.row & col == other.col)
		{
			tmpm = other;  //копирование в буферную матрицу одну из слагаемых матриц
			for (int i = 0; i < this-> row; i++)
			{
				for (int j = 0; j < this->col; j++)
				{
					tmpm.cell[i][j] = this->cell[i][j] + other.cell[i][j]; //замена значений ячеек на сумму
				}
			}
		}
		return tmpm; //возрат буферной матрицы как результата суммы
	} 
	matrixs operator - (matrixs& other) 	//разность двух матриц
	{
		matrixs tmpm = other;   //копируем матрицу в буферную 
		if (this->row == other.row & this->col == other.col)  //проверка на соотношение размеров
		{
			for (int i = 0; i < this->row; i++)
			{
				for (int j = 0; j < this->col; j++)
				{
					tmpm.cell[i][j] = this->cell[i][j] - other.cell[i][j];  //суммирование
				}
			}
		}
		return tmpm;  //возрат матрицы- суммы
	}
	matrixs operator * (int number) //умножение матрцы на число
	{
		int tmp;   //временная переменная
		matrixs tmpm;	//буферная матрица
		tmpm.setrc(this->row, this->col);	//задание размеров буферной матрицы  

		for (int i = 0; i < this->row; i++) {
			tmpm.cell.push_back(vector<int>());		//добавление строки в буферную матрицу
			for (int j = 0; j < this->col; j++) {
				tmp = cell[i][j] * number;		//запись в временную переменную значения произведения
				tmpm.cell[i].push_back(tmp);	//запись в буферную матрицу значения временной переменной
			}
		}
		return tmpm;	//возрат результата произведения
	}
	matrixs operator + (int number) 	//сложение матрицы и числа
	{
		int tmp;   //временная переменная
		matrixs tmpm;	//буферная матрица
		tmpm.setrc(this->row, this->col);	//задание размеров буферной матрицы  

		for (int i = 0; i < this->row; i++) {
			tmpm.cell.push_back(vector<int>());		//добавление строки в буферную матрицу
			for (int j = 0; j < this->col; j++) {
				tmp = cell[i][j] + number;		//запись в временную переменную значения суммы
				tmpm.cell[i].push_back(tmp);	//запись в буферную матрицу значения временной переменной
			}
		}
		return tmpm;	//возрат результата суммы
	} 
	matrixs operator - (int number) //разность матрицы и числа
	{
		int tmp;   //временная переменная
		matrixs tmpm;	//буферная матрица
		tmpm.setrc(this->row, this->col);	//задание размеров буферной матрицы  

		for (int i = 0; i < this->row; i++) {
			tmpm.cell.push_back(vector<int>());		//добавление строки в буферную матрицу
			for (int j = 0; j < this->col; j++) {
				tmp = cell[i][j] - number;		//запись в временную переменную значения разности
				tmpm.cell[i].push_back(tmp);	//запись в буферную матрицу значения временной переменной
			}
		}
		return tmpm;	//возрат результата произведения
	}

	//перемножение матриц
	//возведение в степень матрицы 
    //детерминант
	//норма
};

void menu();

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	matrixs matrix1, matrix2, matrix3;
	int res, buf1, buf2;
	
	do {
		menu();
		cin >> res;
		switch (res)
		{
		case 1:
			cout << "Матрица 1:" << endl << "Введите число строк: "; cin >> buf1; cout << "Введите число столбцов: ";
			cin >> buf2;
			matrix1.setrc(buf1, buf2);w
			cout << "Матрица 2:" << endl << "Введите число строк: "; cin >> buf1; cout << "Введите число столбцов: ";
			cin >> buf2;
			matrix2.setrc(buf1, buf2);
			cout << endl << endl;
			break;
		case 2:
			cout << "Матрицы будут заполнены случайными значениями от 1 до 10:" << endl << endl << "Матрица 1:";
			matrix1.fill_rand();
			matrix1.view();
			cout << endl << "Матрица 2:";
			matrix2.fill_rand();
			matrix2.view();
			break;
		case 3:
			matrix1.view(); matrix2.view();
			break;
		case 4:
			cout << "Выбирете математтическое действие:" << endl << "1. М + М " << endl << "2. М - М " << endl << "3. М + число "
				<< endl << "4. М - число " << endl << "5. M * M " << endl << "6. M * число " << endl << "7. M ^ степень" << endl <<
				"8. Детерменант" << endl << "9. Норма" << endl << endl;
			break;
		case 0:
			return 0;
			break;
		}
	} while (res != 0);
}

void menu()
{
	cout << "1.Создать матрицы" << endl << "2.Заполнить матрицы" << endl
		<< "3.Просмотр матриц" << endl << "4.Математические действия" << endl << "0.Выход" << endl << endl;
}
