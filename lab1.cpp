#ifndef TESTSM_H
#define TESTSM_H

#include "Matrix.h"
//#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <cstdio>
#include <vector>

using namespace std;

TEST_CASE() {
	SECTION("Testing setting row and col.") {
		Matrix matrix;
		matrix.setRowCol(3, 3);
		REQUIRE(matrix.getCol() == 3);
		REQUIRE(matrix.getRow() == 3);
	}

	SECTION("Checking the change in the value of the matrix cell.") {
		vector<vector<int>> testCell = { {1, 2},
										 {4, 8}
		};
		Matrix matrix(testCell);		
		REQUIRE(matrix.getCell(1, 1) == 1);
		REQUIRE(matrix.getCell(1, 2) == 2);
		REQUIRE(matrix.getCell(2, 1) == 4);
		REQUIRE(matrix.getCell(2, 2) == 8);		
	}

	SECTION("Checking the addition of a matrix by a number.") {
		vector<vector<int>> testCell = { {1, 2},
										 {4, 8}
		};
		Matrix matrix(testCell);
		matrix = matrix + 5;
		REQUIRE(matrix.getCell(1, 1) == 6);
		REQUIRE(matrix.getCell(1, 2) == 7);
		REQUIRE(matrix.getCell(2, 1) == 9);
		REQUIRE(matrix.getCell(2, 2) == 13);
	}
	SECTION("Checking the difference between a matrix and a number.") {
		vector<vector<int>> testCell = { {1, 2},
										 {4, 8}
		};
		Matrix matrix(testCell);
		matrix = matrix - 5;
		REQUIRE(matrix.getCell(1, 1) == -4);
		REQUIRE(matrix.getCell(1, 2) == -3);
		REQUIRE(matrix.getCell(2, 1) == -1);
		REQUIRE(matrix.getCell(2, 2) == 3);
	}
	SECTION("Checking the addition of a matrix with a matrix.") {
		vector<vector<int>> testCell1 = { {1, 2},
										  {4, 8}
		};
		vector<vector<int>> testCell2 = { {5, 3},
										  {1, 9}
		};
		Matrix matrix1(testCell1);
		Matrix matrix2(testCell2);
		Matrix matrix3(2, 2);

		matrix3 = matrix1 + matrix2;
		REQUIRE(matrix3.getCell(1, 1) == 6);
		REQUIRE(matrix3.getCell(1, 2) == 5);
		REQUIRE(matrix3.getCell(2, 1) == 5);
		REQUIRE(matrix3.getCell(2, 2) == 17);
	}

	SECTION("Checking the difference between a matrix and a matrix.") {
		vector<vector<int>> testCell1 = { {1, 2},
										  {4, 8}
		};
		vector<vector<int>> testCell2 = { {5, 3},
										  {1, 9}
		};
		Matrix matrix1(testCell1);
		Matrix matrix2(testCell2);
		Matrix matrix3(2, 2);

		matrix3 = matrix1 - matrix2;
		REQUIRE(matrix3.getCell(1, 1) == -4);
		REQUIRE(matrix3.getCell(1, 2) == -1);
		REQUIRE(matrix3.getCell(2, 1) == 3);
		REQUIRE(matrix3.getCell(2, 2) == -1);
	}
	SECTION("Checking the multiplication of a matrix by a number.") {
		vector<vector<int>> testCell = { {1, 2},
										 {4, 8}										
		};
		Matrix matrix(testCell);
	
		matrix = matrix * 5;
		REQUIRE(matrix.getCell(1, 1) == 5);
		REQUIRE(matrix.getCell(1, 2) == 10);
		REQUIRE(matrix.getCell(2, 1) == 20);
		REQUIRE(matrix.getCell(2, 2) == 40);
	}
	SECTION("Checking multiplication of two matrices.") {
		vector<vector<int>> testCell1 = { {1, 2, 3},
										  {4, 8, 3},
										  {12, 0, 7}
		};

		vector<vector<int>> testCell2 = { {1, 8, 14},
										  {4, 2, 3},
										  {5, 0, 7}
		};
		Matrix matrix1(testCell1);
		Matrix matrix2(testCell2);
		Matrix matrix3(3, 3);

		matrix3 = matrix1 * matrix2;
		REQUIRE(matrix3.getCell(2, 2) == 48);

	}
	SECTION("Checking the exponentiation of a matrix.") {
		vector<vector<int>> testCell = { {1, 2, 3},
										 {4, 8, 3},
										 {12, 0, 7}
		};
		Matrix matrix1(testCell);
		Matrix matrix2(3, 3);
		matrix2 = matrix1 ^ 2;
		REQUIRE(matrix2.getCell(2, 2) == 72);
	}
	SECTION("Verification of finding the determinant of the matrix.") {
		vector<vector<int>> testCell = { {1, 2, 3},
										 {4, 8, 3},
										 {12, 0, 7}
		};
		Matrix matrix(testCell);
		REQUIRE(matrix.determinant(matrix) == -216);
	}
	SECTION("Checking the finding of the first norm.") {
		vector<vector<int>> testCell = { {1, 2, 3},
										 {4, 8, 3},
										 {12, 0, 7}
		};
		Matrix matrix(testCell);
		REQUIRE(matrix.firstNorm() == 17);
	}
	SECTION("Checking the finding of the second norm.") {
		vector<vector<int>> testCell = { {1, 2, 3},
										 {4, 8, 3},
										 {5, 0, 7}
		};
		Matrix matrix(testCell);
		REQUIRE(matrix.secondNorm() == 177);
	}
	SECTION("Checking the finding of the third norm.") {
		vector<vector<int>> testCell = { {1, 2, 3},
										 {4, 8, 3},
										 {2, 0, 7}
		};
		Matrix matrix(testCell);
		REQUIRE(matrix.thirdNorm() == 15);
	}
	SECTION("Checking for negative tests for exponentiation of the matrix.") {
		vector<vector<int>> testCell = { {1, 2, 3},
										 {4, 8, 3},
										 {2, 0, 7} };
		Matrix matrix(testCell);
		REQUIRE_THROWS(matrix^(-1)); // неправильная степень

		vector<vector<int>> testCell1 = { {1, 2, 3},
										 {4, 8, 3}
										 };
		Matrix matrix1(testCell1); 
		REQUIRE_THROWS(matrix1 ^2); // проверка размерности
	}

	SECTION("Checking for negative tests for matrix multiplication.") {
		vector<vector<int>> testCell = { {1, 2, 3},
										 {4, 8, 3},
										 {2, 0, 7} };
		Matrix matrix(testCell);
		
		vector<vector<int>> testCell1 = { {1, 2, 3},
										 {4, 8, 3}
		};
		Matrix matrix1(testCell1);
		REQUIRE_THROWS(matrix * matrix1); // проверка размерности
	}

	SECTION("Checking for negative tests for matrix subtraction.") {
		vector<vector<int>> testCell = { {1, 2, 3},
										 {4, 8, 3},
										 {2, 0, 7} };
		Matrix matrix(testCell);

		vector<vector<int>> testCell1 = { {1, 2, 3},
										  {4, 8, 3}
		};
		Matrix matrix1(testCell1);
		REQUIRE_THROWS(matrix - matrix1); // проверка размерности
	}

	SECTION("Checking for negative tests for matrix addition.") {
		vector<vector<int>> testCell = { {1, 2, 3},
										 {4, 8, 3},
										 {2, 0, 7} };
		Matrix matrix(testCell);

		vector<vector<int>> testCell1 = { {1, 2, 3},
										  {4, 8, 3}
		};
		Matrix matrix1(testCell1);
		REQUIRE_THROWS(matrix + matrix1); // проверка размерности
	}


}




















#endif //TESTSM_H