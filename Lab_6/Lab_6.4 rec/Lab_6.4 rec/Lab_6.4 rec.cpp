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
void GenerateRandomArray(int* array, const int size, const int low, const int high, int i = 0) 
{
    // Генерація випадкових чисел для масиву в діапазоні від low до high
    if (i < size)
    {
        array[i] = low + rand() % (high - low + 1);
        GenerateRandomArray(array, size, low, high, i + 1);
    }
}

// Функція для виведення масиву на екран
void PrintArray(int* array, const int size, const int low, const int high, int i = 0)
{
    if (i == 0)
    {
        cout << "Array elements within the range [" << low << ", " << high << "]:" << endl;
    }

    if (i < size)
    {
        cout << setw(4) << array[i];
        PrintArray(array, size, low, high, i + 1);
    }
    else
        cout << endl;
}

// Функція для обчислення добутку парних елементів масиву
void ProductEvenElements(int* array, const int size, int prod = 1, int i = 0)
{
    if (i % 2 == 0) 
    { // Перевірка на парний індекс
        prod *= array[i]; // Додавання елементу до добутку
    }

    if (i < size - 1)
    {
        ProductEvenElements(array, size, prod, i + 1);
    }
    else
        if(prod > 1)
            cout << "Product of even elements: " << prod << endl; // Виводимо добуток
        else
            cout << "No even elements found." << endl; // Якщо парних елементів немає
}

// Рекурсивна функція для підсумовування елементів між першим і останнім нульовими елементами
void SumFirstLastZeroElements(int* array, const int size, int firstZero = -1, int lastZero = -1, int i = 0, int sum = 0) {
    // Пошук першого нульового елемента
    if (firstZero == -1 && i < size) 
    {
        if (array[i] == 0) 
        {
            firstZero = i; // Запам'ятовуємо перший нульовий елемент
        }
    }

    // Пошук останнього нульового елемента
    if (i == size - 1 && lastZero == -1) 
    {
        if (array[i] == 0) 
        {
            lastZero = i; // Запам'ятовуємо останній нульовий елемент
        }
    }

    // Якщо ми знайшли обидва нульових елемента
    if (firstZero != -1 && lastZero != -1 && firstZero != lastZero)
    {
            // Якщо поточний індекс більше за перший нульовий і менший за останній
            if (i > firstZero && i < lastZero) 
            {
                sum += array[i]; // Додаємо значення елемента до суми
            }
    }

    // Рекурсивний виклик
    if (i < size - 1) 
    {
        SumFirstLastZeroElements(array, size, firstZero, lastZero, i + 1, sum); // Переходимо до наступного елементу
    }
    else 
    {
        // Виведення результату після рекурсії
        if (firstZero != -1 && lastZero != -1 && firstZero != lastZero) 
        {
            cout << "Sum: " << sum << endl; // Виводимо суму
        }
        else 
        {
            cout << "In massif not zero elements" << endl; // Якщо елементи не знайдено або вони однакові
        }
    }
}

// Функція для сортування масиву: спочатку додатні елементи, потім від'ємні
void Sort(int* array, const int size, int index = 0)
{
    // Базовий випадок: якщо індекс досяг кінця масиву
    if (index >= size)
        return;

    // Спочатку виводимо всі додатні елементи масиву (включаючи нулі)
    if (array[index] >= 0) {
        cout << setw(4) << array[index];  // Виведення додатного елемента
    }

    // Рекурсивно обробляємо наступний елемент
    Sort(array, size, index + 1);

    // Потім виводимо всі від'ємні елементи масиву
    if (array[index] < 0) {
        cout << setw(4) << array[index];  // Виведення від'ємного елемента
    }
}

// Головна функція
int main() {
    srand((unsigned)time(NULL)); // Ініціалізація генератора випадкових чисел

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
