#include "pch.h"
#include "CppUnitTest.h"
#include "../7.3_it/7.3_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest73it
{
    TEST_CLASS(UnitTest73it)
    {
    public:

        TEST_METHOD(TestRotateMatrixRight)
        {
            int size = 3;
            int** matrix = nullptr;
            CreateMatrix(matrix, size);

            int testMatrix[3][3] = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
            };

            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    matrix[i][j] = testMatrix[i][j];
                }
            }

            RotateMatrixRight(matrix, size, 1);

            int expectedMatrix[3][3] = {
                {2, 3, 6},
                {1, 5, 9},
                {1, 7, 8}
            };

            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    Assert::AreEqual(expectedMatrix[i][j], matrix[i][j], L"Матриця не збігається після одного переміщення вправо");
                }
            }

            for (int i = 0; i < size; i++)
                delete[] matrix[i];
            delete[] matrix;
        }

        TEST_METHOD(TestFindLastColumnWithMostZeros)
        {
            int size = 3;
            int** matrix = nullptr;
            CreateMatrix(matrix, size);

            int testMatrix[3][3] = {
                {1, 0, 3},
                {4, 0, 6},
                {0, 0, 9}
            };

            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    matrix[i][j] = testMatrix[i][j];
                }
            }

            int result = FindLastColumnWithMostZeros(matrix, size);

            Assert::AreEqual(1, result, L"Неправильний стовпець з найбільшою кількістю нулів");

            for (int i = 0; i < size; i++)
                delete[] matrix[i];
            delete[] matrix;
        }
    };
}
