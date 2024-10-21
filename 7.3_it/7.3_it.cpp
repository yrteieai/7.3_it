#include <iostream>
#include <iomanip>
using namespace std;

// Функція для створення динамічної квадратної матриці
void CreateMatrix(int**& matrix, int size) {
    matrix = new int* [size];
    for (int i = 0; i < size; i++)
        matrix[i] = new int[size];
}

// Функція для введення елементів матриці
void InputMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "matrix[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }
}

// Функція для виведення матриці на екран
void PrintMatrix(int** matrix, int size) {
    cout << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

// Допоміжна функція для циклічного переміщення елементів по периметру матриці
void RotatePerimeter(int** matrix, int size) {
    int temp = matrix[0][0]; // Збережемо перший елемент
    int i = 0, j;

    // Переміщення по першому рядку
    for (j = 0; j < size - 1; j++)
        matrix[i][j] = matrix[i][j + 1];

    // Переміщення по останньому стовпчику
    for (i = 0; i < size - 1; i++)
        matrix[i][size - 1] = matrix[i + 1][size - 1];

    // Переміщення по останньому рядку
    for (j = size - 1; j > 0; j--)
        matrix[size - 1][j] = matrix[size - 1][j - 1];

    // Переміщення по першому стовпчику
    for (i = size - 1; i > 1; i--)
        matrix[i][0] = matrix[i - 1][0];

    matrix[1][0] = temp; // Повертаємо збережений елемент
}

// Функція для циклічного переміщення елементів квадратної матриці вправо на k елементів
void RotateMatrixRight(int** matrix, int size, int k) {
    int numLayers = (size + 1) / 2;  // Кількість шарів
    k = k % (4 * (size - 1));  // Нормалізуємо k, щоб не було зайвих циклів

    for (int step = 0; step < k; step++) {
        for (int layer = 0; layer < numLayers; layer++) {
            RotatePerimeter(matrix + layer, size - 2 * layer);
        }
    }
}

// Функція для пошуку стовпця з найбільшою кількістю нульових елементів
int FindLastColumnWithMostZeros(int** matrix, int size) {
    int maxZeroCount = -1;
    int lastColumn = -1;

    for (int j = 0; j < size; j++) {
        int zeroCount = 0;
        for (int i = 0; i < size; i++) {
            if (matrix[i][j] == 0)
                zeroCount++;
        }
        if (zeroCount >= maxZeroCount) {
            maxZeroCount = zeroCount;
            lastColumn = j;
        }
    }

    return lastColumn;
}

int main() {
    int n, k;
    cout << "Enter the size of matrix (n x n): ";
    cin >> n;

    int** matrix;
    CreateMatrix(matrix, n);

    InputMatrix(matrix, n);
    PrintMatrix(matrix, n);

    cout << "Enter the number of positions to rotate (k): ";
    cin >> k;

    RotateMatrixRight(matrix, n, k);
    cout << "Matrix after rotation:" << endl;
    PrintMatrix(matrix, n);

    int lastColumnWithZeros = FindLastColumnWithMostZeros(matrix, n);
    if (lastColumnWithZeros != -1)
        cout << "The last column with the most zeros is: " << lastColumnWithZeros << endl;
    else
        cout << "There are no zero elements in any column." << endl;

    // Очищення пам'яті
    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}
