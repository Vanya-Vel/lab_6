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
    // Перебір всіх елементів масиву
    for (int i = 0; i < size; i++)
    {
        // Генерація випадкового числа в межах від Low до High
        array[i] = Low + rand() % (High - Low + 1); // rand() генерує випадкове число в діапазоні [Low, High]
    }
}

// Функція для виведення масиву на екран
void PrintArray(int* array, const int size, const int Low, const int High)
{
    cout << "Array elements within the range [" << Low << ", " << High << "]:" << endl;

    // Перебір всіх елементів масиву
    for (int i = 0; i < size; i++)
    {
        // Якщо елемент знаходиться в межах діапазону [Low, High], виводимо його
        if (array[i] >= Low && array[i] <= High)
            cout << setw(4) << array[i];  // Виведення елементу масиву
    }
    cout << endl;
}

// Функція для знаходження індексу мінімального елемента в масиві
int MinIndex(int* array, const int size)
{
    int min_index = 0;  // Ініціалізація мінімального індексу як 0 (перший елемент)

    // Перебір масиву, щоб знайти індекс мінімального елемента
    for (int j = min_index + 1; j < size; j++)
    {
        // Якщо поточний елемент менший за елемент, який зараз вважається мінімальним
        if (array[j] < array[min_index])
        {
            min_index = j;  // Оновлюємо індекс мінімального елемента
        }
    }
    return min_index;  // Повертаємо індекс мінімального елемента
}

// Функція для знаходження індексу максимального елемента в масиві
int MaxIndex(int* array, const int size)
{
    int max_index = size - 1;  // Ініціалізація максимального індексу як останній елемент

    // Перебір масиву, щоб знайти індекс максимального елемента
    for (int k = max_index - 1; k > 0; k--)
    {
        // Якщо поточний елемент більший за елемент, який зараз вважається максимальним
        if (array[k] > array[max_index])
        {
            max_index = k;  // Оновлюємо індекс максимального елемента
        }
    }
    return max_index;  // Повертаємо індекс максимального елемента
}

// Функція для обчислення середнього значення індексів мінімального та максимального елементів масиву
void CalculateAverage(int* array, const int size)
{
    // Викликаємо функції для знаходження індексів мінімального та максимального елементів
    int f = (MaxIndex(array, size) + MinIndex(array, size)) / 2;

    // Виведення індексів максимального та мінімального елементів
    cout << "max index: " << MaxIndex(array, size) << "   min index: " << MinIndex(array, size) << endl;

    // Виведення середнього значення індексів
    cout << "average: " << f;
}

int main()
{
    srand((unsigned)time(NULL)); // Ініціалізація генератора випадкових чисел

    const int n = 20; // Розмір масиву
    int a[n]; // Оголошення масиву
    int Low = -20; // Нижня межа діапазону
    int High = 20; // Верхня межа діапазону

    // Виклик функції для генерації масиву випадкових чисел в межах [-20, 20]
    GenerateRandomArray(a, n, Low, High);

    // Виведення елементів масиву, які потрапляють в заданий діапазон
    PrintArray(a, n, Low, High);

    // Обчислення середнього значення індексів мінімального та максимального елементів
    CalculateAverage(a, n);

    return 0;
}
