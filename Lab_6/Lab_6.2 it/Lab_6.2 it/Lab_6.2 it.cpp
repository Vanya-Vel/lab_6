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
void GenerateRandomArray(int* array, const int size, const int Low, const int High)
{
    // ������ ��� �������� ������
    for (int i = 0; i < size; i++)
    {
        // ��������� ����������� ����� � ����� �� Low �� High
        array[i] = Low + rand() % (High - Low + 1); // rand() ������ ��������� ����� � ������� [Low, High]
    }
}

// ������� ��� ��������� ������ �� �����
void PrintArray(int* array, const int size, const int Low, const int High)
{
    cout << "Array elements within the range [" << Low << ", " << High << "]:" << endl;

    // ������ ��� �������� ������
    for (int i = 0; i < size; i++)
    {
        // ���� ������� ����������� � ����� �������� [Low, High], �������� ����
        if (array[i] >= Low && array[i] <= High)
            cout << setw(4) << array[i];  // ��������� �������� ������
    }
    cout << endl;
}

// ������� ��� ����������� ������� ���������� �������� � �����
int MinIndex(int* array, const int size)
{
    int min_index = 0;  // ����������� ���������� ������� �� 0 (������ �������)

    // ������ ������, ��� ������ ������ ���������� ��������
    for (int j = min_index + 1; j < size; j++)
    {
        // ���� �������� ������� ������ �� �������, ���� ����� ��������� ���������
        if (array[j] < array[min_index])
        {
            min_index = j;  // ��������� ������ ���������� ��������
        }
    }
    return min_index;  // ��������� ������ ���������� ��������
}

// ������� ��� ����������� ������� ������������� �������� � �����
int MaxIndex(int* array, const int size)
{
    int max_index = size - 1;  // ����������� ������������� ������� �� ������� �������

    // ������ ������, ��� ������ ������ ������������� ��������
    for (int k = max_index - 1; k > 0; k--)
    {
        // ���� �������� ������� ������ �� �������, ���� ����� ��������� ������������
        if (array[k] > array[max_index])
        {
            max_index = k;  // ��������� ������ ������������� ��������
        }
    }
    return max_index;  // ��������� ������ ������������� ��������
}

// ������� ��� ���������� ���������� �������� ������� ���������� �� ������������� �������� ������
void CalculateAverage(int* array, const int size)
{
    // ��������� ������� ��� ����������� ������� ���������� �� ������������� ��������
    int f = (MaxIndex(array, size) + MinIndex(array, size)) / 2;

    // ��������� ������� ������������� �� ���������� ��������
    cout << "max index: " << MaxIndex(array, size) << "   min index: " << MinIndex(array, size) << endl;

    // ��������� ���������� �������� �������
    cout << "average: " << f;
}

int main()
{
    srand((unsigned)time(NULL)); // ����������� ���������� ���������� �����

    const int n = 20; // ����� ������
    int a[n]; // ���������� ������
    int Low = -20; // ����� ���� ��������
    int High = 20; // ������ ���� ��������

    // ������ ������� ��� ��������� ������ ���������� ����� � ����� [-20, 20]
    GenerateRandomArray(a, n, Low, High);

    // ��������� �������� ������, �� ����������� � ������� �������
    PrintArray(a, n, Low, High);

    // ���������� ���������� �������� ������� ���������� �� ������������� ��������
    CalculateAverage(a, n);

    return 0;
}
