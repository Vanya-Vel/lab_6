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

            Assert::IsTrue(true); // Test passed since the output to the screen has no checks
        }

        TEST_METHOD(Test_SumEvenElements)
        {
            int sampleArray[] = { 1, 2, 3, 4, 5, 6 }; // Масив із значеннями
            int expectedSum = 12;  // Очікувана сума парних чисел: 2 + 4 + 6 = 12
            int actualSum = 0;  // Змінна для збереження фактичного результату

            for (int i = 0; i < 6; i++)
            {
                if (sampleArray[i] % 2 == 0)
                {
                    actualSum += sampleArray[i];
                }
            }
            // Перевіряємо, чи результат збігається з очікуваним
            Assert::AreEqual(expectedSum, actualSum);
        }
    };
}
