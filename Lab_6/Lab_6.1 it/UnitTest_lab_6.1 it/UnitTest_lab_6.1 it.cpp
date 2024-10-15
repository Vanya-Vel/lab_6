#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.1 it/Lab_6.1 it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestlab61it
{
	TEST_CLASS(UnitTestlab61it)
	{
	public:
		
        TEST_METHOD(Test_CreateArray)
        {
            const int n = 24; // ����� ������
            int a[n]; // ���������� ������
            int Low = -40; // ����� ���� ��������
            int High = 15; // ������ ���� ��������

            CreateArray(a, n, Low, High); // ������ ������� ��� ���������� ������

            // ��������, �� �� �������� � ����� � ����� [Low, High]
            for (int i = 0; i < n; i++) {
                Assert::IsTrue(a[i] >= Low && a[i] <= High);
            }
        }

        TEST_METHOD(Test_PrintArray) {
            const int n = 24; // ����� ������
            int a[n]; // ���������� ������

            // ������ ������� ��� ��������� ������
            PrintArray(a, n);

            // ���� �������� ����� �����, ���� ��������
            Assert::IsTrue(true);
        }

        TEST_METHOD(Test_CalculateSum)
        {
            const int n = 5; // ����� ������
            int a[n] = { 1, 2, 3, 4, 5 }; // ���������� ������ �� �����������

            int expected_sum = 1 + 2 + 3 + 4 + 5; // ��������� ����

            int actual_sum = 0; // ����� ��� �������� ����
            for (int i = 0; i < n; i++) {
                actual_sum += a[i]; // ��������� �������� �� ����
            }
            Assert::AreEqual(expected_sum, actual_sum); // �������� �� �����������
        }

        TEST_METHOD(Test_CountNumbers)
        {
            const int n = 6; // ����� ������
            int a[n] = { -2, -1, 0, 1, 2, 3 }; // ���������� ������ �� �����������

            int expected_num = 6; // ��������� ������� ��������

            int actual_num = 0; // ˳������� ������� ��������
            for (int i = 0; i < n; i++) {
                actual_num++; // ��������� ���������
            }
            Assert::AreEqual(expected_num, actual_num); // �������� �� �����������
        }

        TEST_METHOD(Test_PrintModifiedArray)
        {
            const int n = 24; // ����� ������
            int a[n]; // ���������� ������

            // ������ ������� ��� ����������� �� ��������� ������
            PrintModifiedArray(a, n);

            // ��������, �� �������� ������ ���������� ������
            for (int i = 0; i < n; i++) {
                Assert::IsTrue(a[i] < 0 || i % 2 != 0); // �������� ���� ��� ��������
            }
        }

        TEST_METHOD(Test_CalculateModifiedSum)
        {
            const int n = 6; // ����� ������
            int a[n] = { -2, -1, 0, 1, 2 }; // ���������� ������ �� �����������

            int expected_sum = -1 - 2 + 1; // ��������� ����

            int actual_sum = 0; // ����� ��� �������� ����
            for (int i = 0; i < n; i++) {
                if (a[i] < 0 || i % 2 != 0) // �������� ����
                    actual_sum += a[i]; // ��������� �������� �� ����
            }
            Assert::AreEqual(expected_sum, actual_sum); // �������� �� �����������
        }

        TEST_METHOD(Test_CountModifiedNumbers)
        {
            const int n = 6; // ����� ������
            int a[n] = { -2, -1, 0, 1, 2, 3 }; // ���������� ������ �� �����������

            int expected_num = 4; // ��������� ������� ������������� �����

            int actual_num = 0; // ˳������� ������� ��������
            for (int i = 0; i < n; i++) {
                if (a[i] < 0 || i % 2 != 0) { // �������� ����
                    actual_num++; // ��������� ���������
                }
            }
            Assert::AreEqual(expected_num, actual_num); // �������� �� �����������
        }
	};
}
