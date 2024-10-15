// Lab_06_2.cpp
// < ������� ���� >
// ����������� ������ � 6.2
// ����������� ����������� ������ ������������ �� ������������ ���������
// ������ 0.4

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// ������� ��� ��������� ������ ���������� ����� � �������� �������
// ���������� �������� ����� ����������� ������� � ������� [Low, High]
void GenerateRandomArray(int* array, const int size, const int Low, const int High, int i = 0)
{
    // ��������� ����������� ����� ��� ��������� �������
    array[i] = Low + rand() % (High - Low + 1);

    // ���� �������� ������ ������ �� ����� ������, ��������� ���������� ��� ���������� ��������
    if (i < size - 1)
    {
        GenerateRandomArray(array, size, Low, High, i + 1);
    }
}

// ������� ��� ��������� ������ �� �����
// ���������� �������� �������� ������, �� ����������� � ������� [Low, High]
void PrintArray(int* array, const int size, const int Low, const int High, int i = 0)
{
    // ��������� ��������� ��� ������
    if (i == 0)
    {
        cout << "Array elements within the range [" << Low << ", " << High << "]:" << endl;
    }

    // ��������� ��������� ��������, ���� �� ����������� � ������� [Low, High]
    if (array[i] >= Low && array[i] <= High)
        cout << setw(4) << array[i];  // �������� ������� ������

    // ���� �� ����������� �������� � �����, ��������� ������� ����������
    if (i < size - 1)
    {
        PrintArray(array, size, Low, High, i + 1);
    }
    else
        cout << endl;  // ϳ��� ���������� ������ �������� ����� �����
}

// ���������� ������� ��� ����������� ������� ���������� ��������
// ������� ����� ������� � �������� ��������� �� ������� ������ ����������
int MinIndex(int* array, const int size, int current_index = 0, int min_index = 0) {
    // ������� �������: ���� ������� ���� ������
    if (current_index == size - 1)
        return min_index;

    // ���� �������� ������� ������ �� ���������, ��������� ������ ������
    if (array[current_index] < array[min_index])
        min_index = current_index;

    // ����������� ������ ��� ���������� ��������
    return MinIndex(array, size, current_index + 1, min_index);
}

// ���������� ������� ��� ����������� ������� ������������� ��������
// ������� ����� ������� � �������� ������������ �� ������� ������ �������������
int MaxIndex(int* array, const int size, int current_index = 0, int max_index = 0) {
    // ������� �������: ���� ������� ���� ������
    if (current_index == size - 1)
        return max_index;

    // ���� �������� ������� ������ �� ������������, ��������� ������ ���������
    if (array[current_index] > array[max_index])
        max_index = current_index;

    // ����������� ������ ��� ���������� ��������
    return MaxIndex(array, size, current_index + 1, max_index);
}

// ������� ��� ���������� ���������� �������� ������� ���������� � ������������� ��������
void CalculateAverage(int* array, const int size) {
    // ��������� ��������� ������� ��� ������ ������� ���������� �� ������������� ��������
    int min_index = MinIndex(array, size);  // ��������� ������ ������
    int max_index = MaxIndex(array, size);  // ��������� ������ ���������

    // �������� ������� ���������� �� ������������� ��������
    cout << "Min index: " << min_index << ", Max index: " << max_index << endl;

    // ���������� ������ �������� �� ��������� ���������� �� ������������� ��������
    int average_index = (max_index + min_index) / 2;

    // �������� ������ ��������
    cout << "Average of the low and high index: " << average_index << endl;
}

int main()
{
    srand((unsigned)time(NULL)); // ����������� ���������� ���������� �����

    const int n = 20; // ����� ������
    int a[n]; // ���������� ������
    int Low = -20; // ����� ���� ��������
    int High = 20; // ������ ���� ��������

    // ������ ������� ��� ��������� ������ ���������� �����
    GenerateRandomArray(a, n, Low, High);

    // ��������� �������� ������, �� ����������� � ������� [Low, High]
    PrintArray(a, n, Low, High);

    // ���������� �� ��������� ���������� �������� ������� ���������� �� ������������� ��������
    CalculateAverage(a, n);

    return 0;
}
