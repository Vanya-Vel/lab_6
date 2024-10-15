#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.2 it/Lab_6.2 it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestlab62it
{
	TEST_CLASS(UnitTestlab62it)
	{
	public:
		
        TEST_METHOD(Test_GenerateRandomArray)
        {
            const int n = 20; // ����� ������
            int a[n]; // ���������� ������
            int Low = -20; // ����� ���� ��������
            int High = 20; // ������ ���� ��������

            GenerateRandomArray(a, n, Low, High); // ������ ������� ��� ��������� ���������� �����

            // ��������, �� �� �������� ������ ����������� � �������� �������
            for (int i = 0; i < n; i++)
            {
                Assert::IsTrue(a[i] >= Low && a[i] <= High);
            }
        }

        TEST_METHOD(Test_PrintArray)
        {
            const int n = 20; // ����� ������
            int a[n]; // ���������� ������
            int Low = -20; // ����� ���� ��������
            int High = 20; // ������ ���� ��������

            GenerateRandomArray(a, n, Low, High); // ��������� ���������� �����

            PrintArray(a, n, Low, High); // ������ ������� ��� ������ ������ �� �����

            Assert::IsTrue(true); // ���� �������, ������� ���� �� ����� �� �� ��������
        }

        TEST_METHOD(Test_MinIndex)
        {
            int a[6] = { 2, 5, 8, 9, -8, -5 }; // ���������� ������
            int min_index = 0;

            Assert::AreEqual(4, MinIndex(a, 6));
        }

        TEST_METHOD(Test_MaxIndex)
        {
            int a[6] = { 2, 5, 8, 9, -8, -5 }; // ���������� ������
            int max_index = 0;

            Assert::AreEqual(3, MaxIndex(a, 6));
        }

        TEST_METHOD(Test_CalculateAverage)
        {
            int a[6] = { 2, 5, 8, 9, -8, -5 }; // ���������� ������
            int max_index = 0;

            int average = (MaxIndex(a, 6) + MinIndex(a, 6)) / 2;
            Assert::AreEqual(3, average);
        }
	};
}
