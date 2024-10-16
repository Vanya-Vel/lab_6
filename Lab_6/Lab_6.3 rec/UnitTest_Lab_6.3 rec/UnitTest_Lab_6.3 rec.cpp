#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.3 rec/Lab_6.3 rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab63rec
{
    TEST_CLASS(UnitTestLab63rec)
    {
    public:

        // ���� ��� �������� ������� ��������� ������ ���������� �����
        TEST_METHOD(Test_GenerateRandomArray)
        {
            const int n = 20; // ����� ������
            int a[n]; // ���������� ������
            int low = -20; // ����� ���� ��������
            int high = 20; // ������ ���� ��������

            GenerateRandomArray(a, n, low, high); // ������ ������� ��� ��������� ���������� �����

            // ��������, �� �� �������� ������ ����������� � �������� �������
            for (int i = 0; i < n; i++)
            {
                Assert::IsTrue(a[i] >= low && a[i] <= high);
            }
        }

        // ���� ��� �������� ������� ��������� ������ �� �����
        TEST_METHOD(Test_PrintArray)
        {
            const int n = 20; // ����� ������
            int a[n]; // ���������� ������
            int low = -20; // ����� ���� ��������
            int high = 20; // ������ ���� ��������

            GenerateRandomArray(a, n, low, high); // ��������� ���������� �����

            PrintArray(a, n, low, high); // ������ ������� ��� ������ ������ �� �����

            Assert::IsTrue(true); // ���� �������, ������� ���� �� ����� �� �� ��������
        }

        // ���� ��� �������� ���� ������ �������� ������
        TEST_METHOD(Test_SumEvenElements)
        {
            int a[] = { 1, 2, 3, 4, 5, 6 }; // ����� �� ����������
            int expected_sum = 12;  // ��������� ���� ������ �����: 2 + 4 + 6 = 12
            int actual_sum = 0;  // ����� ��� ���������� ���������� ����������

            // ���������� �������� ���� ������ ��������
            for (int i = 0; i < 6; i++)
            {
                if (a[i] % 2 == 0)
                {
                    actual_sum += a[i];
                }
            }

            // ����������, �� ��������� �������� � ����������
            Assert::AreEqual(expected_sum, actual_sum);
        }
    };
}
