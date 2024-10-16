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
void GenerateRandomArray(int* array, const int size, const int low, const int high) {
    for (int i = 0; i < size; i++) {
        // Генерація випадкового числа в межах від low до high
        array[i] = low + rand() % (high - low + 1);
    }
}

// Функція для виведення масиву на екран
void PrintArray(int* array, const int size, const int low, const int high) {
    cout << "Array elements within the range [" << low << ", " << high << "]:" << endl;
    for (int i = 0; i < size; i++) {
        // Виводимо елементи масиву, які в межах [low, high]
        if (array[i] >= low && array[i] <= high) {
            cout << setw(4) << array[i];
        }
    }
    cout << endl; // Переходимо на новий рядок
}

// Функція для обчислення суми парних елементів масиву
void SumEvenElements(int* array, const int size) {
    int sum = 0; // Ініціалізація змінної для суми
    for (int i = 0; i < size; i++) {
        // Додаємо до суми, якщо елемент парний
        if (array[i] % 2 == 0) {
            sum += array[i];
        }
    }
    cout << "Sum of even elements: " << sum << endl; // Виводимо результат
}

int main() {
    srand((unsigned)time(NULL)); // Ініціалізація генератора випадкових чисел

    const int n = 20; // Розмір масиву
    int a[n]; // Оголошення масиву
    int low = -20; // Нижня межа діапазону
    int high = 20; // Верхня межа діапазону

    GenerateRandomArray(a, n, low, high); // Виклик функції для генерації масиву
    PrintArray(a, n, low, high); // Виведення масиву
    SumEvenElements(a, n); // Обчислення та виведення суми парних елементів

    return 0;
}
