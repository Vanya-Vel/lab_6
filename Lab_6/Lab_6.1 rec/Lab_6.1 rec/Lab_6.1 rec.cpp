#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Функція для створення масиву випадкових чисел в заданому діапазоні
void CreateArray(int* array, const int size, const int Low, const int High, int i)
{
    if (i < size)
    {
        array[i] = Low + rand() % (High - Low + 1); // Генерація випадкового числа
        CreateArray(array, size, Low, High, i + 1);
    }
}


// Функція для виведення масиву на екран
void PrintArray(int* array, const int size, int i)
{
    if (i < size)
    {
        cout << setw(4) << array[i]; // Вивід кожного елемента
        PrintArray(array, size, i + 1);
    }
    if(i == size -1)
        cout << endl;
}

// Функція для обчислення суми всіх елементів масиву
void CalculateSum(int* array, const int size, int i, int sum)
{
    if (i < size)
    {
        sum += array[i];
        CalculateSum(array, size, i + 1, sum);
    }
    if(i == size - 1)
        cout << sum << endl; // Вивід суми
}

// Функція для виведення розміру масиву
void CountNumbers(int* array, const int size, int i, int count)
{
    if (i < size)
    {
        count++; // Збільшення лічильника
        CountNumbers(array, size, i + 1, count);
    }
    if (i == size - 1)
    cout << count << endl; // Вивід кількості
}

// Функція для виведення модифікованого масиву (значення < 0 або з непарними індексами)
void PrintModifiedArray(int* array, const int size, int i)
{
    if (i < size) // Перевірка на розмір масиву
    {
        if (array[i] < 0 || i % 2 != 0) // Перевірка умов
        {
            cout << setw(4) << array[i]; // Вивід значення
        }
        else
            cout << setw(4) << 0;
        PrintModifiedArray(array, size, i + 1); // Рекурсивний виклик
    }

    if (i == size - 1) // Додати новий рядок лише після завершення виводу
        cout << endl; // Вивід нового рядка
    
}

// Функція для обчислення суми модифікованих значень
void CalculateModifiedSum(int* array, const int size, int i, int sum)
{
    if (i < size)
    {
        if (array[i] < 0 || i % 2 != 0) // Перевірка умов
        {
            sum += array[i]; // Додавання значення до суми
        }
        CalculateModifiedSum(array, size, i + 1, sum); // Рекурсивний виклик із передачею суми
    }
    if (i == size - 1)
        cout << sum << endl; // Вивід суми
    
}

// Функція для підрахунку кількості модифікованих елементів
void CountModifiedNumbers(int* array, const int size, int i, int count)
{
    if (i < size)
    {
        if (array[i] < 0 || i % 2 != 0) // Перевірка умов
        {
            count++; // Збільшення лічильника
        }
        CountModifiedNumbers(array, size, i + 1, count);
    }
    if (i == size - 1)
        cout << count << endl;
}

int main() {
    srand((unsigned)time(NULL)); // Ініціалізація генератора випадкових чисел

    const int n = 24; // Розмір масиву
    int a[n]; // Оголошення масиву
    int Low = -40; // Нижня межа діапазону
    int High = 15; // Верхня межа діапазону

    CreateArray(a, n, Low, High, 0); // Виклик функції для створення масиву

    cout << "Original array:" << endl;
    PrintArray(a, n, 0); // Вивід оригінального масиву
    cout << "Modified array:" << endl;
    PrintModifiedArray(a, n, 0); // Вивід модифікованого масиву
    cout << "Sum of numbers:" << endl;
    CalculateSum(a, n, 0, 0); // Обчислення та вивід суми
    cout << "Count of elements:" << endl;
    CountNumbers(a, n, 0, 0); // Вивід розміру масиву
    
    cout << "Sum of modified numbers:" << endl;
    CalculateModifiedSum(a, n, 0, 0); // Обчислення та вивід суми модифікованих значень
    cout << "Count of modified numbers:" << endl;
    CountModifiedNumbers(a, n, 0, 0); // Підрахунок та вивід кількості модифікованих елементів

    return 0;
}
