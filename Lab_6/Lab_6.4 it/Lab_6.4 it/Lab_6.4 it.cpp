// Lab_06_4.cpp
// < Величко Іван >
// Лабораторна робота № 6.4
// Опрацювання та впорядкування одновимірних динамічних масивів
// Варіант 0.3

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

// Функція для створення масиву випадкових чисел в заданому діапазоні
void GenerateRandomArray(int* array, const int size, const int low, const int high) {
    // Генерація випадкових чисел для масиву в діапазоні від low до high
    for (int i = 0; i < size; i++) {
        array[i] = low + rand() % (high - low + 1); // Генерація випадкового числа в заданому діапазоні
    }
}

// Функція для виведення масиву на екран
void PrintArray(int* array, const int size, const int low, const int high) {
    cout << "Array elements within the range [" << low << ", " << high << "]:" << endl;
    // Виведення елементів масиву, які знаходяться в заданому діапазоні [low, high]
    for (int i = 0; i < size; i++) {
        if (array[i] >= low && array[i] <= high) {
            cout << setw(4) << array[i]; // Виведення елемента
        }
    }
    cout << endl;
}

// Функція для обчислення добутку парних елементів масиву
void ProductEvenElements(int* array, const int size)
{
    int prod = 1; // Ініціалізація змінної для добутку

    // Перевірка всіх елементів масиву на парність за індексами
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) { // Перевірка на парний індекс
            prod *= array[i]; // Додавання елементу до добутку
        }
    }

    // Якщо добуток більше 1 (тобто парні елементи існують), виводимо його
    if (prod > 1)
        cout << "Product of even elements: " << prod << endl; // Виводимо добуток
    else
        cout << "No even elements found." << endl; // Якщо парних елементів немає
}

// Функція для обчислення суми елементів між першим і останнім нульовими елементами
void SumFirstLastZeroElements(int* array, const int size)
{
    int Sum = 0; // Ініціалізація змінної для суми
    int FirstZeroElement = -1; // Індекс першого нульового елементу
    int SecondZeroElement = -1; // Індекс останнього нульового елементу

    // Пошук першого нульового елемента
    for (int i = 0; i < size; i++) {
        if (array[i] == 0) {
            FirstZeroElement = i;
            break; // Якщо знайдений перший нуль, припиняємо пошук
        }
    }

    // Пошук останнього нульового елемента
    for (int k = size - 1; k >= 0; k--) {
        if (array[k] == 0) {
            SecondZeroElement = k;
            break; // Якщо знайдений останній нуль, припиняємо пошук
        }
    }

    // Якщо обидва нульових елементи знайдено і вони не співпадають
    if (FirstZeroElement != -1 && SecondZeroElement != -1 && FirstZeroElement != SecondZeroElement)
    {
        // Підсумовуємо елементи між першим і останнім нульовими елементами
        for (int j = FirstZeroElement + 1; j < SecondZeroElement; j++) {
            Sum += array[j]; // Додавання елементу до суми
        }
        cout << "Sum: " << Sum << endl; // Виведення суми елементів
    }
    else
        cout << "In massif not zero elements"; // Якщо елементів нульових немає або вони однакові
    cout << endl;
}

// Функція для сортування масиву: спочатку додатні елементи, потім від'ємні
void Sort(int* array, const int size)
{
    cout << "Sort array: " << endl;
    // Спочатку виводимо всі додатні елементи масиву
    for (int i = 0; i < size; i++) {
        if (array[i] >= 0) { // Перевірка на додатній елемент
            cout << setw(4) << array[i]; // Виведення додатніх елементів
        }
    }

    // Потім виводимо всі від'ємні елементи масиву
    for (int j = 0; j < size; j++) {
        if (array[j] < 0) { // Перевірка на від'ємний елемент
            cout << setw(4) << array[j]; // Виведення від'ємних елементів
        }
    }
}

// Головна функція
int main() {
    srand(static_cast<unsigned>(time(nullptr))); // Ініціалізація генератора випадкових чисел

    int n; // Розмір масиву

    cout << "to write a size: "; cin >> n; // Запитуємо розмір масиву

    int* a = new int[n]; // Оголошення масиву динамічно
    int low = -40; // Нижня межа діапазону
    int high = 40; // Верхня межа діапазону

    // Генерація випадкових чисел для масиву
    GenerateRandomArray(a, n, low, high);

    // Виведення масиву
    PrintArray(a, n, low, high);

    // Обчислення та виведення добутку елементів з парними індексами
    ProductEvenElements(a, n);

    // Обчислення суми елементів між першим і останнім нульовим елементами
    SumFirstLastZeroElements(a, n);

    // Виведення масиву, в якому спочатку додатні елементи, а потім від'ємні
    Sort(a, n);

    delete[] a; // Видаляємо динамічно виділений масив

    return 0;
}
