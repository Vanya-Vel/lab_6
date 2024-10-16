// Lab_06_3.cpp
// < Величко Іван >
// Лабораторна робота № 6.3
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів
// Варіант 0.3

#include <iostream>
#include <iomanip>
#include <ctime> // Використовуємо <ctime> для генерації випадкових чисел

using namespace std;

// Функція для створення масиву випадкових чисел в заданому діапазоні
void GenerateRandomArray(int* array, const int size, const int low, const int high, int index = 0) {
    array[index] = low + rand() % (high - low + 1); // Генерація випадкового числа в діапазоні

    // Якщо індекс менший за розмір масиву, рекурсивно викликаємо функцію для наступного індексу
    if (index < size - 1) {
        GenerateRandomArray(array, size, low, high, index + 1);
    }
}

// Функція для виведення масиву на екран
void PrintArray(int* array, const int size, const int low, const int high, int index = 0) {
    // Виводимо заголовок при першому виклику
    if (index == 0) {
        cout << "Array elements within the range [" << low << ", " << high << "]:" << endl;
    }

    // Виводимо елемент, якщо він в межах діапазону
    if (array[index] >= low && array[index] <= high) {
        cout << setw(4) << array[index];
    }

    // Рекурсивно викликаємо функцію для наступного індексу, якщо не досягли кінця масиву
    if (index < size - 1) {
        PrintArray(array, size, low, high, index + 1);
    }
    else {
        cout << endl; // Переходимо на новий рядок після виведення всіх елементів
    }
}

// Функція для обчислення суми парних елементів масиву
void SumEvenElements(int* array, const int size, int index = 0, int sum = 0) {
    if (index < size) {
        // Додаємо до суми, якщо елемент парний
        if (array[index] % 2 == 0) {
            sum += array[index];
        }
        // Рекурсивно викликаємо функцію для наступного індексу
        SumEvenElements(array, size, index + 1, sum);
    }
    else {
        cout << "Sum of even elements: " << sum << endl; // Виводимо загальну суму
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr))); // Ініціалізація генератора випадкових чисел

    const int n = 20; // Розмір масиву
    int a[n]; // Оголошення масиву
    int low = -20; // Нижня межа діапазону
    int high = 20; // Верхня межа діапазону

    GenerateRandomArray(a, n, low, high); // Генерація масиву
    PrintArray(a, n, low, high); // Виведення масиву
    SumEvenElements(a, n); // Обчислення та виведення суми парних елементів

    return 0;
}
