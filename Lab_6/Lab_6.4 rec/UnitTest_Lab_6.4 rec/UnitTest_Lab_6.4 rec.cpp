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
            const int arraySize = 20; // Розмір масиву
            int randomArray[arraySize]; // Оголошення масиву
            int lowerBound = -20; // Нижня межа діапазону
            int upperBound = 20; // Верхня межа діапазону

            GenerateRandomArray(randomArray, arraySize, lowerBound, upperBound); // Виклик функції для генерації випадкових чисел

            // Перевірка, що всі елементи масиву знаходяться в заданому діапазоні
            for (int i = 0; i < arraySize; i++)
            {
                Assert::IsTrue(randomArray[i] >= lowerBound && randomArray[i] <= upperBound);
            }
        }

        TEST_METHOD(Test_PrintArray)
        {
            const int arraySize = 20; // Розмір масиву
            int randomArray[arraySize]; // Оголошення масиву
            int lowerBound = -20; // Нижня межа діапазону
            int upperBound = 20; // Верхня межа діапазону

            GenerateRandomArray(randomArray, arraySize, lowerBound, upperBound); // Генерація випадкових чисел

            PrintArray(randomArray, arraySize, lowerBound, upperBound); // Виклик функції для виводу масиву на екран
        }

        TEST_METHOD(Test_ProductEvenElements)
        {
            int a[6] = { 1, 2, 3, 4, -5, -8 };

            int expected_prod = -15;
            int actual_prod = 1; // Ініціалізація змінної для добутк

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

            int ActualSum = 0; // Ініціалізація змінної для суми
            int FirstZeroElement = -1; // Індекс першого нульового елементу
            int SecondZeroElement = -1; // Індекс останнього нульового елементу
            int ExpectedSum = 1;

            // Пошук першого нульового елемента
            for (int i = 0; i < 10; i++) {
                if (a[i] == 0) {
                    FirstZeroElement = i;
                    break; // Якщо знайдений перший нуль, припиняємо пошук
                }
            }

            // Пошук останнього нульового елемента
            for (int k = 9; k >= 0; k--) {
                if (a[k] == 0) {
                    SecondZeroElement = k;
                    break; // Якщо знайдений останній нуль, припиняємо пошук
                }
            }

            // Підсумовуємо елементи між першим і останнім нульовими елементами
            for (int j = FirstZeroElement + 1; j < SecondZeroElement; j++) {
                ActualSum += a[j]; // Додавання елементу до суми
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

            // Спочатку виводимо всі додатні елементи масиву
            for (int i = 0; i < n; i++) {
                if (A[i] >= 0) { // Перевірка на додатній елемент
                    Assert::AreEqual(ExpectedAPlus[ExpectedIndexPlus], A[i]); // Виведення додатніх елементів
                    ExpectedIndexPlus++;
                }
            }
            int ExpectedIndexMinus = 0;
            // Потім виводимо всі від'ємні елементи масиву
            for (int j = 0; j < n; j++) {
                if (A[j] < 0) { // Перевірка на додатній елемент
                    Assert::AreEqual(ExpectedAMinus[ExpectedIndexMinus], A[j]); // Виведення додатніх елементів
                    ExpectedIndexMinus++;
                }
            }
        }
	};
}
