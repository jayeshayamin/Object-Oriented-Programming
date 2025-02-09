#include<iostream>
using namespace std;

int** allocateMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) 
        matrix[i] = new int[cols];
    return matrix;
}

void inputMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < cols; j++) 
            cin >> matrix[i][j];
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) 
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int** addMatrices(int** matrix1, int** matrix2, int rows, int cols) {
    if (!matrix1 || !matrix2) {
        cout << "Matrix addition not possible." << endl;
        return nullptr;
    }
    int** result = allocateMatrix(rows, cols);
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < cols; j++) 
            result[i][j] = matrix1[i][j] + matrix2[i][j];
    return result;
}

int** subtractMatrices(int** matrix1, int** matrix2, int rows, int cols) {
    if (!matrix1 || !matrix2) {
        cout << "Matrix subtraction not possible." << endl;
        return nullptr;
    }
    int** result = allocateMatrix(rows, cols);
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < cols; j++) 
            result[i][j] = matrix1[i][j] - matrix2[i][j];
    return result;
}

int** multiplyMatrices(int** matrix1, int** matrix2, int rows1, int cols1, int rows2, int cols2) {
    if (!matrix1 || !matrix2 || cols1 != rows2) {
        cout << "Matrix multiplication not possible." << endl;
        return nullptr;
    }
    int** result = allocateMatrix(rows1, cols2);
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) 
        delete[] matrix[i];
    delete[] matrix;
}

int main() {
    int rowsa, colsa, rowsb, colsb;
    cout << "Enter rows and columns for matrix A: ";
    cin >> rowsa >> colsa;
    cout << "Enter rows and columns for matrix B: ";
    cin >> rowsb >> colsb;

    int** matrix1 = allocateMatrix(rowsa, colsa);
    int** matrix2 = allocateMatrix(rowsb, colsb);

    cout << "Enter elements of matrix A:" << endl;
    inputMatrix(matrix1, rowsa, colsa);

    cout << "Enter elements of matrix B:" << endl;
    inputMatrix(matrix2, rowsb, colsb);

    if (rowsa == rowsb && colsa == colsb) {
        int** sumMatrix = addMatrices(matrix1, matrix2, rowsa, colsa);
        if (sumMatrix) {
            cout << "Sum of matrices:" << endl;
            printMatrix(sumMatrix, rowsa, colsa);
            freeMatrix(sumMatrix, rowsa);
        }
    }

    if (rowsa == rowsb && colsa == colsb) {
        int** diffMatrix = subtractMatrices(matrix1, matrix2, rowsa, colsa);
        if (diffMatrix) {
            cout << "Difference of matrices:" << endl;
            printMatrix(diffMatrix, rowsa, colsa);
            freeMatrix(diffMatrix, rowsa);
        }
    }

    if (colsa == rowsb) {
        int** productMatrix = multiplyMatrices(matrix1, matrix2, rowsa, colsa, rowsb, colsb);
        if (productMatrix) {
            cout << "Product of matrices:" << endl;
            printMatrix(productMatrix, rowsa, colsb);
            freeMatrix(productMatrix, rowsa);
        }
    }

    freeMatrix(matrix1, rowsa);
    freeMatrix(matrix2, rowsb);

    return 0;
}