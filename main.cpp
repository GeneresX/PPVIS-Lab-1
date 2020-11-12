#define CATCH_CONFIG_RUNNER
#include "lab1.cpp"

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Menu.h"
#include "Matrix.h"
/// \file
using namespace std;

int main()
{
	Catch::Session().run();
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	Matrix matrix1, matrix2, matrix3;
	int res1, res2, res3, buf1, buf2, power;

	do {
		menu();
		cin >> res1;
		system("cls");
		switch (res1)
		{
		case 1:
			cout << "Матрица 1:" << endl << "Введите число строк: "; cin >> buf1; cout << "Введите число столбцов: "; cin >> buf2;
			matrix1.setRowCol(buf1, buf2);
			cout << "Матрица 2:" << endl << "Введите число строк: "; cin >> buf1; cout << "Введите число столбцов: "; cin >> buf2;
			matrix2.setRowCol(buf1, buf2);
			cout << endl << endl;
			break;
		case 2:
			cout << "Матрицы будут заполнены случайными значениями от 1 до 10:" << endl << endl << "Матрица 1:";
			matrix1.fillRandom();
			matrix1.view();
			cout << endl << endl;
			cout << endl << "Матрица 2:";
			matrix2.fillRandom();
			matrix2.view();
			cout << endl << endl;
			system("pause");
			break;
		case 3:
			cout << "Первая матрица: \n";
			matrix1.view();
			cout << endl << endl << "Вторая матрица: \n";
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
					try {
						matrix3 = matrix1 + matrix2;	//сложение матриц
					}
					catch (const char* exception) {
						cout << exception;
						abort();
					}
					matrix1.view(); cout << "\n\n	+	" << endl;  matrix2.view(); cout << "\n\n	=	"; matrix3.view();
					cout << "\n\n";
					system("pause");
					break;
				case 2: cout << "1. M1 - M2" << endl << "2. M2 - M1" << endl << endl;	//вычитание матриц
					cin >> buf1;
					switch (buf1) {
					case 1:
						try {
							matrix3 = matrix1 - matrix2;
						}
						catch (const char* exception) {
							cout << exception;
							abort();
						}
						matrix1.view(); cout << "\n\n	-	" << endl;  matrix2.view(); cout << "\n\n	=	";
						break;
					case 2:
						try {
							matrix3 = matrix2 - matrix1;
						}
						catch (const char* exception) {
							cout << exception;
							abort();
						}
						matrix2.view(); cout << "\n\n	-	" << endl;  matrix1.view(); cout << "\n\n	=	";
						break;
					}
					matrix3.view();
					cout << "\n\n";
					system("pause");
					break;
				case 3:
					cout << "Введите первое слагаемое: ";	//сумма матрицы и числа
					cin >> buf1;
					cout << "\nВыберите второе слагаемое: " << endl << "1.Первая матрица" << endl << "2.Вторая матрица" << endl << endl;
					cin >> res3;
					switch (res3)
					{
					case 1:
						matrix1.view(); cout << "\n\n	+	" << endl << buf1 << "\n\n	=	";
						matrix1 + buf1;
						matrix1.view();
						cout << "\n\n";
						break;
					case 2:
						matrix2.view(); cout << "\n\n	+	" << endl << buf1 << "\n\n	=	";
						matrix2 + buf1;
						matrix2.view();
						cout << "\n\n";
						break;
					}
					system("pause");
					break;
				case 4:
					cout << "Введите вычитаемое: ";		/**
														*\brief разность матрицы и числа
														*/
					cin >> buf1;
					cout << "Выберите матрциу: " << endl << "1.Первая" << endl << "2.Вторая" << endl << endl;
					cin >> buf2;
					switch (buf2) {
					case 1:
						matrix1.view(); cout << "\n\n	-	" << endl << buf1 << "\n\n	=	";
						matrix1 - buf1;
						matrix1.view();
						break;
					case 2:
						matrix2.view(); cout << "\n\n	-	" << endl << buf1 << "\n\n	=	";
						matrix2 - buf2;
						matrix2.view();
						break;
					}
					system("pause");
					break;
				case 5:
					cout << "Введите число: "; cin >> buf1;		//матрица на число
					cout << "Выберите матрицу: " << endl << "1.Первая" << endl << "2.Вторая" << endl << endl;
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
				case 6:  cout << "1. M1 * M2" << endl << "2. M2 * M1" << endl << endl;	//произведение матриц
					cin >> buf1;
					switch (buf1) {
					case 1:
						try {
							matrix3 = matrix1 * matrix2;
						}
						catch (const char* exception) {
							cout << exception;
							abort();
						}
						matrix1.view(); cout << "\n\n	*	" << endl;  matrix2.view(); cout << "\n\n	=	"; matrix3.view(); cout << "\n\n";
						system("pause");
						break;
					case 2:
						try {
							matrix3 = matrix2 * matrix1;
						}
						catch (const char* exception) {
							cout << exception;
							abort();
						}
						matrix2.view(); cout << "\n\n	*	" << endl;  matrix1.view(); cout << "\n\n	=	"; matrix3.view(); cout << "\n\n";
						system("pause");
						break;
					}
					break;
				case 7:
					//возведение в степень матрицы
					cout << "Введите степень в которую желаете возвести матрицу: ";
					cin >> power;
					cout << "С какой матрицей произвести действие?\n\n1."; matrix1.view(); cout << "\n\n\n2."; matrix2.view(); cout << "\n\n";
					cin >> buf1;
					switch (buf1) {
					case 1:
						try {
							matrix3 = matrix1 ^ power;
						}
						catch (const char* exception) {
							cout << exception;
							abort();
						}
						matrix1.view(); cout << "\n\n	^	\n" << power << "\n\n	=	";
						matrix3.view();
						system("pause");
						break;

					case 2:
						try {
							matrix3 = matrix2 ^ power;
						}
						catch (const char* exception) {
							cout << exception;
							abort();
						}
						matrix2.view(); cout << "\n\n	^	\n" << power << "\n\n	=	";
						matrix3.view();
						system("pause");
						break;
					}
					break;
				case 8:
					//детерменант
					cout << "С какой матрицей произвести действие?\n\n1."; matrix1.view(); cout << "\n\n\n2."; matrix2.view(); cout << "\n\n";
					cin >> buf1;
					switch (buf1) {
					case 1:
						cout << "Определитель = " << matrix1.determinant(matrix1) << endl;
						system("pause");
						break;
					case 2:
						cout << "Определитель = " << matrix2.determinant(matrix2) << endl;
						system("pause");
						break;
					}
					break;
				case 9:
					//Норма
					cout << "Нахождение нормы матрицы:\n1.\n"; matrix1.view(); cout << "\n\n2.\n"; matrix2.view(); cout << "\n\n";
					cin >> buf1;
					switch (buf1)
					{
					case 1:
						matrix1.view();
						cout << "\n\n";
						cout << "Первая норма матрицы: " << matrix1.firstNorm() << endl;
						cout << "Вторая норма матрицы: " << matrix1.secondNorm() << endl;
						cout << "Третья норма матрицы: " << matrix1.thirdNorm() << endl;
						system("pause");
						break;
					case 2:
						matrix2.view();
						cout << "\n\n";
						cout << "Первая норма матрицы: " << matrix2.firstNorm() << endl;
						cout << "Вторая норма матрицы: " << matrix2.secondNorm() << endl;
						cout << "Третья норма матрицы: " << matrix2.thirdNorm() << endl;
						system("pause");
						break;
					}
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
	} while (res1 != 0);
}