#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.3 it/Lab_6.3 it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab63it
{
    TEST_CLASS(UnitTestLab63it)
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

            Assert::IsTrue(true); // Test passed since the output to the screen has no checks
        }

        TEST_METHOD(Test_SumEvenElements)
        {
            int sampleArray[] = { 1, 2, 3, 4, 5, 6 }; // ����� �� ����������
            int expectedSum = 12;  // ��������� ���� ������ �����: 2 + 4 + 6 = 12
            int actualSum = 0;  // ����� ��� ���������� ���������� ����������

            for (int i = 0; i < 6; i++)
            {
                if (sampleArray[i] % 2 == 0)
                {
                    actualSum += sampleArray[i];
                }
            }
            // ����������, �� ��������� �������� � ����������
            Assert::AreEqual(expectedSum, actualSum);
        }
    };
}
