#include <iostream>

namespace {
	long long matrix1[20][20] = {};
	long long matrix2[20][20] = {};
	long long matrixRes[20][20] = {};
}

static void readMatrix(long long matrix[][20], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cin >> matrix[i][j];
		}
	}
}

static void multiplyMatrices(long long matrix1[][20], long long matrix2[][20], long long matrixRes[][20], int rows1, int cols1, int cols2) {
	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < cols2; j++) {
			for (int s = 0; s < cols1; s++) {
				matrixRes[i][j] += matrix1[i][s] * matrix2[s][j];
			}
		}
	}
}

static void printMatrix(long long matrix[][20], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void matrixMultiplication() {
	int n, m, k;
	std::cin >> n >> m >> k;

	readMatrix(matrix1, n, m);
	readMatrix(matrix2, m, k);

	multiplyMatrices(matrix1, matrix2, matrixRes, n, m, k);

	printMatrix(matrixRes, n, k);
}