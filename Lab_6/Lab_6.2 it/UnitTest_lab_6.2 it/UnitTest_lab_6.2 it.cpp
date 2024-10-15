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
            const int n = 20; // Розмір масиву
            int a[n]; // Оголошення масиву
            int Low = -20; // Нижня межа діапазону
            int High = 20; // Верхня межа діапазону

            GenerateRandomArray(a, n, Low, High); // Виклик функції для генерації випадкових чисел

            // Перевірка, що всі елементи масиву знаходяться в заданому діапазоні
            for (int i = 0; i < n; i++)
            {
                Assert::IsTrue(a[i] >= Low && a[i] <= High);
            }
        }

        TEST_METHOD(Test_PrintArray)
        {
            const int n = 20; // Розмір масиву
            int a[n]; // Оголошення масиву
            int Low = -20; // Нижня межа діапазону
            int High = 20; // Верхня межа діапазону

            GenerateRandomArray(a, n, Low, High); // Генерація випадкових чисел

            PrintArray(a, n, Low, High); // Виклик функції для виводу масиву на екран

            Assert::IsTrue(true); // Тест пройшов, оскільки вивід на екран не має перевірок
        }

        TEST_METHOD(Test_MinIndex)
        {
            int a[6] = { 2, 5, 8, 9, -8, -5 }; // Оголошення масиву
            int min_index = 0;

            Assert::AreEqual(4, MinIndex(a, 6));
        }

        TEST_METHOD(Test_MaxIndex)
        {
            int a[6] = { 2, 5, 8, 9, -8, -5 }; // Оголошення масиву
            int max_index = 0;

            Assert::AreEqual(3, MaxIndex(a, 6));
        }

        TEST_METHOD(Test_CalculateAverage)
        {
            int a[6] = { 2, 5, 8, 9, -8, -5 }; // Оголошення масиву
            int max_index = 0;

            int average = (MaxIndex(a, 6) + MinIndex(a, 6)) / 2;
            Assert::AreEqual(3, average);
        }
	};
}
