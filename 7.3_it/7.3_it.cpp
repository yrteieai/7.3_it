#include <iostream>
#include <iomanip>
using namespace std;

// ������� ��� ��������� �������� ��������� �������
void CreateMatrix(int**& matrix, int size) {
    matrix = new int* [size];
    for (int i = 0; i < size; i++)
        matrix[i] = new int[size];
}

// ������� ��� �������� �������� �������
void InputMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "matrix[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }
}

// ������� ��� ��������� ������� �� �����
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

// �������� ������� ��� ��������� ���������� �������� �� ��������� �������
void RotatePerimeter(int** matrix, int size) {
    int temp = matrix[0][0]; // ��������� ������ �������
    int i = 0, j;

    // ���������� �� ������� �����
    for (j = 0; j < size - 1; j++)
        matrix[i][j] = matrix[i][j + 1];

    // ���������� �� ���������� ���������
    for (i = 0; i < size - 1; i++)
        matrix[i][size - 1] = matrix[i + 1][size - 1];

    // ���������� �� ���������� �����
    for (j = size - 1; j > 0; j--)
        matrix[size - 1][j] = matrix[size - 1][j - 1];

    // ���������� �� ������� ���������
    for (i = size - 1; i > 1; i--)
        matrix[i][0] = matrix[i - 1][0];

    matrix[1][0] = temp; // ��������� ���������� �������
}

// ������� ��� ��������� ���������� �������� ��������� ������� ������ �� k ��������
void RotateMatrixRight(int** matrix, int size, int k) {
    int numLayers = (size + 1) / 2;  // ʳ������ ����
    k = k % (4 * (size - 1));  // ���������� k, ��� �� ���� ������ �����

    for (int step = 0; step < k; step++) {
        for (int layer = 0; layer < numLayers; layer++) {
            RotatePerimeter(matrix + layer, size - 2 * layer);
        }
    }
}

// ������� ��� ������ ������� � ��������� ������� �������� ��������
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

    // �������� ���'��
    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}
