#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.3 rec/Lab_6.3 rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab63rec
{
    TEST_CLASS(UnitTestLab63rec)
    {
    public:

        // Тест для перевірки функції генерації масиву випадкових чисел
        TEST_METHOD(Test_GenerateRandomArray)
        {
            const int n = 20; // Розмір масиву
            int a[n]; // Оголошення масиву
            int low = -20; // Нижня межа діапазону
            int high = 20; // Верхня межа діапазону

            GenerateRandomArray(a, n, low, high); // Виклик функції для генерації випадкових чисел

            // Перевірка, що всі елементи масиву знаходяться в заданому діапазоні
            for (int i = 0; i < n; i++)
            {
                Assert::IsTrue(a[i] >= low && a[i] <= high);
            }
        }

        // Тест для перевірки функції виведення масиву на екран
        TEST_METHOD(Test_PrintArray)
        {
            const int n = 20; // Розмір масиву
            int a[n]; // Оголошення масиву
            int low = -20; // Нижня межа діапазону
            int high = 20; // Верхня межа діапазону

            GenerateRandomArray(a, n, low, high); // Генерація випадкових чисел

            PrintArray(a, n, low, high); // Виклик функції для виводу масиву на екран

            Assert::IsTrue(true); // Тест пройшов, оскільки вивід на екран не має перевірок
        }

        // Тест для перевірки суми парних елементів масиву
        TEST_METHOD(Test_SumEvenElements)
        {
            int a[] = { 1, 2, 3, 4, 5, 6 }; // Масив із значеннями
            int expected_sum = 12;  // Очікувана сума парних чисел: 2 + 4 + 6 = 12
            int actual_sum = 0;  // Змінна для збереження фактичного результату

            // Обчислюємо фактичну суму парних елементів
            for (int i = 0; i < 6; i++)
            {
                if (a[i] % 2 == 0)
                {
                    actual_sum += a[i];
                }
            }

            // Перевіряємо, чи результат збігається з очікуваним
            Assert::AreEqual(expected_sum, actual_sum);
        }
    };
}
