#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.4 rec/Lab_6.4 rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab64rec
{
	TEST_CLASS(UnitTestLab64rec)
	{
	public:
		
        TEST_METHOD(Test_GenerateRandomArray)
        {
            const int arraySize = 20; // ����� ������
            int randomArray[arraySize]; // ���������� ������
            int lowerBound = -20; // ����� ���� ��������
            int upperBound = 20; // ������ ���� ��������

            GenerateRandomArray(randomArray, arraySize, lowerBound, upperBound); // ������ ������� ��� ��������� ���������� �����

            // ��������, �� �� �������� ������ ����������� � �������� �������
            for (int i = 0; i < arraySize; i++)
            {
                Assert::IsTrue(randomArray[i] >= lowerBound && randomArray[i] <= upperBound);
            }
        }

        TEST_METHOD(Test_PrintArray)
        {
            const int arraySize = 20; // ����� ������
            int randomArray[arraySize]; // ���������� ������
            int lowerBound = -20; // ����� ���� ��������
            int upperBound = 20; // ������ ���� ��������

            GenerateRandomArray(randomArray, arraySize, lowerBound, upperBound); // ��������� ���������� �����

            PrintArray(randomArray, arraySize, lowerBound, upperBound); // ������ ������� ��� ������ ������ �� �����
        }

        TEST_METHOD(Test_ProductEvenElements)
        {
            int a[6] = { 1, 2, 3, 4, -5, -8 };

            int expected_prod = -15;
            int actual_prod = 1; // ����������� ����� ��� ������

            for (int i = 0; i < 6; i++)
            {
                if (i % 2 == 0)
                {
                    actual_prod *= a[i];
                }
            }
            Assert::AreEqual(expected_prod, actual_prod);
        }

        TEST_METHOD(Test_SumFirstLastZeroElements)
        {
            int a[10] = { -5, 0, -3, -2, -1, 4, 1, 2, 0, 4 };

            int ActualSum = 0; // ����������� ����� ��� ����
            int FirstZeroElement = -1; // ������ ������� ��������� ��������
            int SecondZeroElement = -1; // ������ ���������� ��������� ��������
            int ExpectedSum = 1;

            // ����� ������� ��������� ��������
            for (int i = 0; i < 10; i++) {
                if (a[i] == 0) {
                    FirstZeroElement = i;
                    break; // ���� ��������� ������ ����, ���������� �����
                }
            }

            // ����� ���������� ��������� ��������
            for (int k = 9; k >= 0; k--) {
                if (a[k] == 0) {
                    SecondZeroElement = k;
                    break; // ���� ��������� ������� ����, ���������� �����
                }
            }

            // ϳ��������� �������� �� ������ � ������� ��������� ����������
            for (int j = FirstZeroElement + 1; j < SecondZeroElement; j++) {
                ActualSum += a[j]; // ��������� �������� �� ����
            }

            Assert::AreEqual(ExpectedSum, ActualSum);
        }

        TEST_METHOD(Test_Sort)
        {
            const int n = 10;
            int A[n] = { -5, 0, -3, -2, -1, 4, 1, 2, 0, 4 };
            int ExpectedAPlus[n] = { 0, 4, 1, 2, 0, 4 };
            int ExpectedAMinus[n] = { -5, -3, -2, -1 };
            int ExpectedIndexPlus = 0;

            // �������� �������� �� ������ �������� ������
            for (int i = 0; i < n; i++) {
                if (A[i] >= 0) { // �������� �� ������� �������
                    Assert::AreEqual(ExpectedAPlus[ExpectedIndexPlus], A[i]); // ��������� ������� ��������
                    ExpectedIndexPlus++;
                }
            }
            int ExpectedIndexMinus = 0;
            // ���� �������� �� ��'��� �������� ������
            for (int j = 0; j < n; j++) {
                if (A[j] < 0) { // �������� �� ������� �������
                    Assert::AreEqual(ExpectedAMinus[ExpectedIndexMinus], A[j]); // ��������� ������� ��������
                    ExpectedIndexMinus++;
                }
            }
        }
	};
}
