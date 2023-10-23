#include <iostream>
#include <fstream>
#include <iomanip>

const int MAX_SIZE = 100;

void readMatrixFromFile(int matrix[MAX_SIZE][MAX_SIZE], int &matrixSize, const char *filename) {
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        inputFile >> matrixSize; 
        for (int i = 0; i < matrixSize; i++) {
            for (int j = 0; j < matrixSize; j++) {
                inputFile >> matrix[i][j]; 
            }
        }
        inputFile.close();
    } else {
        std::cerr << "Error: Could not open the file." << std::endl;
    }
}

void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int matrixSize) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            std::cout << std::setw(4) << matrix[i][j]; 
        }
        std::cout << std::endl;
    }
}

void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int matrixSize) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int matrixSize) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            result[i][j] = 0;
            for (int k = 0; k < matrixSize; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int matrixSize) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE];
    int matrix2[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int matrixSize;

    readMatrixFromFile(matrix1, matrixSize, "matrix_input.txt");
    readMatrixFromFile(matrix2, matrixSize, "matrix_input.txt");

    std::cout << "Jorge Trujillo" << std::endl;
    std::cout << "Lab #6: Matrix manipulation" << std::endl;

    std::cout << "Matrix 1:" << std::endl;
    printMatrix(matrix1, matrixSize);

    std::cout << "Matrix 2:" << std::endl;
    printMatrix(matrix2, matrixSize);

    addMatrices(matrix1, matrix2, result, matrixSize);
    std::cout << "Matrix Sum (1 + 2):" << std::endl;
    printMatrix(result, matrixSize);

    multiplyMatrices(matrix1, matrix2, result, matrixSize);
    std::cout << "Matrix Product (1 * 2):" << std::endl;
    printMatrix(result, matrixSize);

    subtractMatrices(matrix1, matrix2, result, matrixSize);
    std::cout << "Matrix Difference (1 - 2):" << std::endl;
    printMatrix(result, matrixSize);

    return 0;
}


