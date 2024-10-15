// Lab_06_2.cpp
// < Величко Іван >
// Лабораторна робота № 6.2
// Опрацювання одновимірних масивів ітераційними та рекурсивними способами
// Варіант 0.4


#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Функція для створення масиву випадкових чисел в заданому діапазоні
void GenerateRandomArray(int* array, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
    {
        // Генерація випадкового числа в межах від Low до High
        array[i] = Low + rand() % (High - Low + 1);
    }
}

// Функція для виведення масиву на екран
void PrintArray(int* array, const int size, const int Low, const int High)
{
    cout << "Array elements within the range [" << Low << ", " << High << "]:" << endl;
    for (int i = 0; i < size; i++)
    {
        // Виводимо елементи масиву, які в межах [Low, High]
        if (array[i] >= Low && array[i] <= High)
            cout << setw(4) << array[i];
    }
    cout << endl;
}

int MinIndex(int* array, const int size)
{
    int min_index = 0;

    // Знаходимо індекс мінімального елемента в масиві
    for (int j = min_index + 1; j < size; j++)
    {
        if (array[j] < array[min_index])
        {
            min_index = j;
        }
    }
    return min_index;
}

int MaxIndex(int* array, const int size)
{
    int max_index = size - 1;

    // Знаходимо індекс максимального елемента в масиві
    for (int k = max_index - 1; k > 0; k--)
    {
        if (array[k] > array[max_index])
        {
            max_index = k;
        }
    }
    return max_index;
}

void CalculateAverage(int* array, const int size)
{
    int f = (MaxIndex(array, size) + MinIndex(array, size)) / 2;
    cout << "max index: " << MaxIndex(array, size) << "   min index: " << MinIndex(array, size) << endl;
    cout << "average: " << f;
}

int main()
{
    srand((unsigned)time(NULL)); // Ініціалізація генератора випадкових чисел

    const int n = 20; // Розмір масиву
    int a[n]; // Оголошення масиву
    int Low = -20; // Нижня межа діапазону
    int High = 20; // Верхня межа діапазону

    GenerateRandomArray(a, n, Low, High); // Виклик функції для створення масивуPrintArray(a, n, Low, High); // Виводимо оригінальний масив
    PrintArray(a, n, Low, High);
    CalculateAverage(a, n); // Сортуємо масив

    return 0;
}
