#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class matrixs {
public:
	int row, col;
	vector<vector<int>> cell;

	matrixs() {		//конструктор по умолчанию
		row = 0; col = 0;
	}
	matrixs(int r, int c) {		//конструктор класса с параметрами
		row = r; col = c;
	}

	void setrc(int r, int c) {		//изменение значений row и col
		row = r; col = c;
	}
	void fill_rand()	//заполнение рандомными числами
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
	void view()		//просмотр матрицы
	{
		for (int i = 0; i < this->row; i++)
		{
			cout << endl << endl;
			for (int j = 0; j < this->col; j++)
			{
				cout << this->cell[i][j] << "\t";
			}
		}
	}

	matrixs operator + (matrixs & other) 	//сложение двух матриц
	{
		matrixs tmpm = other;    //копирование в буферную матрицу одну из слагаемых матриц

		if ( row == other.row & col == other.col)
		{
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
		matrixs tmpm(this->row, this->col);	//буферная матрица

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
		matrixs tmpm(this->row, this->col);	//буферная матрица  

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
		matrixs tmpm(this->row, this->col);	//буферная матрица
		
		for (int i = 0; i < this->row; i++) {
			tmpm.cell.push_back(vector<int>());		//добавление строки в буферную матрицу
			for (int j = 0; j < this->col; j++) {
				tmp = cell[i][j] - number;		//запись в временную переменную значения разности
				tmpm.cell[i].push_back(tmp);	//запись в буферную матрицу значения временной переменной
			}
		}
		return tmpm;	//возрат результата произведения
	}
	
	//Илья делает все ниже:
	//перемножение матриц
	//возведение в степень матрицы 
    //детерминант
	//норма
};

void menu();
void menu_math();

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	matrixs matrix1, matrix2, matrix3;
	int res, res2, res3, buf1, buf2;
	
	do {
		menu();
		cin >> res;
		system("cls");
		switch (res)
		{
		case 1:
			cout << "Матрица 1:" << endl << "Введите число строк: "; cin >> buf1; cout << "Введите число столбцов: ";
			cin >> buf2;
			matrix1.setrc(buf1, buf2);
			cout << "Матрица 2:" << endl << "Введите число строк: "; cin >> buf1; cout << "Введите число столбцов: ";
			cin >> buf2;
			matrix2.setrc(buf1, buf2);
			cout << endl << endl;
			break;
		case 2:
			cout << "Матрицы будут заполнены случайными значениями от 1 до 10:" << endl << endl << "Матрица 1:";
			matrix1.fill_rand();
			matrix1.view();
			cout << endl << endl;
			cout << endl << "Матрица 2:";
			matrix2.fill_rand();
			matrix2.view();
			cout << endl << endl;
			system("pause");
			break;
		case 3:
			cout << "Первая матрица: " << endl << endl;
			matrix1.view(); 
			cout << endl << endl << "Вторая матрица: " << endl << endl;
			matrix2.view();
			system("pause");
			break;
		case 4:
			do {
				menu_math();
				cin >> res2;
				system("cls");
				switch (res2)
				{
				case 1:
					matrix3 = matrix1 + matrix2;	//сложение матриц
					matrix1.view(); cout <<"\n\n	+	" << endl;  matrix2.view(); cout << "\n\n	=	"; matrix3.view();
					cout << "\n\n";
					system("pause");
					break;
				case 2: cout << "1. M1 - M2" << endl << "2. M2 - M1" << endl << endl;
					cin >> buf1;
					switch (buf1) {
					case 1:	matrix3 = matrix1 - matrix2;
						matrix1.view(); cout << "\n\n	-	" << endl;  matrix2.view(); cout << "\n\n	=	"; 
						break;
					case 2:	matrix3 = matrix2 - matrix1;
						matrix2.view(); cout << "\n\n	-	" << endl;  matrix1.view(); cout << "\n\n	=	"; 
						break;
					}
				    matrix3.view();
					cout << "\n\n";
					system("pause");
					break;
				case 3:
					cout << "Введите первое слогаемое: ";	//сумма матрицы и числа
					cin >> buf1;
					cout << "\nВыберите второе слагаемое: " << endl << "1.Первая матрица" << endl << "2.Вторая матрица" << endl << endl;
					cin >> res3;
					switch (res3)
					{
					case 1: 
						matrix3 = matrix1 + buf1;
						matrix1.view(); cout << "\n\n	+	" << endl << buf1 << "\n\n	=	"; matrix3.view();
						cout << "\n\n";
						break;
					case 2:
						matrix3 = matrix2 + buf1;
						matrix2.view(); cout << "\n\n	+	" << endl << buf1 << "\n\n	=	"; matrix3.view();
						cout << "\n\n";
						break;
					}
					matrix3.view(); cout << "\n\n";
					system("pause");
					break;
				case 4:
					cout << "Введите вычитаемое: ";		//разность матрицы и числа
					cin >> buf1;
					cout << "Выберите матрциу: " << endl << "1.Первая" << endl << "2.Вторая" << endl << endl;
					cin >> buf2;
					switch (buf2) {
					case 1: matrix3 = matrix1 + buf1;
						matrix1.view(); cout << "\n\n	-	" << endl << buf1 << "\n\n	=	"; 
						break;
					case 2: matrix3 = matrix2 + buf2;
						matrix2.view(); cout << "\n\n	-	" << endl << buf1 << "\n\n	=	";
						break;
					}
					matrix3.view();
					system("pause");
					break;
				case 5:
					//произведение матриц
					break;
				case 6:
					cout << "Введите число: "; cin >> buf1;		//матрица на число
					cout << "Выберите матрциу: " << endl << "1.Первая" << endl << "2.Вторая" << endl << endl;
					cin >> buf2;
					switch (buf2) {
					case 1: matrix3 = matrix1 * buf1;
						matrix1.view(); cout << "\n\n	*	" << endl << buf1 << "\n\n	=	"; 
						break;
					case 2: matrix3 = matrix2 * buf1;
						matrix2.view(); cout << "\n\n	*	" << endl << buf1 << "\n\n	=	";
						break;
					}
					matrix3.view();
					system("pause");
					break;
				case 7:
					//возведение в степень матрциы
					break;
				case 8:
					//детерменант
					break;
				case 9:
					//Норма
					break;
				case 0:
					res2 = 0;
					break;
				}
				system("cls");
			} while (res2 != 0);
			break;
		case 0:
			return 0;
			break;
		}
		system("cls");
	} while (res != 0);
}

void menu_math() {
	cout << "Выбирете математтическое действие:" << endl << "1. Матрица + Матрица " << endl << "2. Матрица - Матрица " 
		<< endl << "3. Матрица + число " << endl << "4. Матрица - число " << endl << "5. Mатрица * Mатрциа " 
		<< endl << "6. Mатрица * число " << endl << "7. Mатрица ^ степень" << endl <<"8. Детерменант"
		<< endl << "9. Норма" << endl << endl;
}

void menu(){
	cout << "1.Создать матрицы" << endl << "2.Заполнить матрицы" << endl
		<< "3.Просмотр матриц" << endl << "4.Математические действия" << endl << "0.Выход" << endl << endl;
}
