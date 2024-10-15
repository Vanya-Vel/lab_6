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
// Рекурсивно заповнює масив випадковими числами в діапазоні [Low, High]
void GenerateRandomArray(int* array, const int size, const int Low, const int High, int i = 0)
{
    // Генерація випадкового числа для поточного індексу
    array[i] = Low + rand() % (High - Low + 1);

    // Якщо поточний індекс менший за розмір масиву, викликаємо рекурсивно для наступного елемента
    if (i < size - 1)
    {
        GenerateRandomArray(array, size, Low, High, i + 1);
    }
}

// Функція для виведення масиву на екран
// Рекурсивно виводить елементи масиву, які знаходяться в діапазоні [Low, High]
void PrintArray(int* array, const int size, const int Low, const int High, int i = 0)
{
    // Виведення заголовку для масиву
    if (i == 0)
    {
        cout << "Array elements within the range [" << Low << ", " << High << "]:" << endl;
    }

    // Виведення поточного елемента, якщо він знаходиться в діапазоні [Low, High]
    if (array[i] >= Low && array[i] <= High)
        cout << setw(4) << array[i];  // Виводимо елемент масиву

    // Якщо ще залишаються елементи в масиві, викликаємо функцію рекурсивно
    if (i < size - 1)
    {
        PrintArray(array, size, Low, High, i + 1);
    }
    else
        cout << endl;  // Після завершення рекурсії виводимо новий рядок
}

// Рекурсивна функція для знаходження індексу мінімального елемента
// Порівнює кожен елемент з поточним мінімальним та повертає індекс мінімального
int MinIndex(int* array, const int size, int current_index = 0, int min_index = 0) {
    // Базовий випадок: коли досягли кінця масиву
    if (current_index == size - 1)
        return min_index;

    // Якщо поточний елемент менший за мінімальний, оновлюємо індекс мінімуму
    if (array[current_index] < array[min_index])
        min_index = current_index;

    // Рекурсивний виклик для наступного елемента
    return MinIndex(array, size, current_index + 1, min_index);
}

// Рекурсивна функція для знаходження індексу максимального елемента
// Порівнює кожен елемент з поточним максимальним та повертає індекс максимального
int MaxIndex(int* array, const int size, int current_index = 0, int max_index = 0) {
    // Базовий випадок: коли досягли кінця масиву
    if (current_index == size - 1)
        return max_index;

    // Якщо поточний елемент більший за максимальний, оновлюємо індекс максимуму
    if (array[current_index] > array[max_index])
        max_index = current_index;

    // Рекурсивний виклик для наступного елемента
    return MaxIndex(array, size, current_index + 1, max_index);
}

// Функція для обчислення середнього значення індексів мінімального і максимального елемента
void CalculateAverage(int* array, const int size) {
    // Викликаємо рекурсивні функції для пошуку індексів мінімального та максимального елементів
    int min_index = MinIndex(array, size);  // Знаходимо індекс мінімуму
    int max_index = MaxIndex(array, size);  // Знаходимо індекс максимуму

    // Виводимо індекси мінімального та максимального елементів
    cout << "Min index: " << min_index << ", Max index: " << max_index << endl;

    // Обчислюємо середнє значення між індексами мінімального та максимального елементів
    int average_index = (max_index + min_index) / 2;

    // Виводимо середнє значення
    cout << "Average of the low and high index: " << average_index << endl;
}

int main()
{
    srand((unsigned)time(NULL)); // Ініціалізація генератора випадкових чисел

    const int n = 20; // Розмір масиву
    int a[n]; // Оголошення масиву
    int Low = -20; // Нижня межа діапазону
    int High = 20; // Верхня межа діапазону

    // Виклик функції для створення масиву випадкових чисел
    GenerateRandomArray(a, n, Low, High);

    // Виведення елементів масиву, які потрапляють в діапазон [Low, High]
    PrintArray(a, n, Low, High);

    // Обчислення та виведення середнього значення індексів мінімального та максимального елементів
    CalculateAverage(a, n);

    return 0;
}
