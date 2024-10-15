// Lab_06_1.cpp
// < ������� ���� >
// ����������� ������ � 6.1
// ����� �������� ������������ ������ ����������� �� ����������� ��������
// ������ 0.4

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// ������� ��� ��������� ������ ���������� ����� � �������� �������
void CreateArray(int* array, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        array[i] = Low + rand() % (High - Low + 1); // ��������� ����������� �����
}

// ������� ��� ��������� ������ �� �����
void PrintArray(int* array, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << array[i]; // ���� ������� ��������
    cout << endl;
}

// ������� ��� ���������� ���� ��� �������� ������
void CalculateSum(int* array, const int size)
{
    int sum = 0; // ����� ��� ��������� ����
    for (int i = 0; i < size; i++) {
        sum += array[i]; // ��������� �������� �� ����
    }
    cout << sum << endl; // ���� ����
}

// ������� ��� ��������� ������ ������
void CountNumbers(int* array, const int size)
{
    cout << size << endl; // ���� ������
}

// ������� ��� ��������� �������������� ������ (�������� < 0 ��� � ��������� ���������)
void PrintModifiedArray(int* array, const int size)
{
    for (int i = 0; i < size; i++) {
        if (array[i] < 0 || i % 2 != 0) // �������� ����
            cout << setw(4) << array[i]; // ���� ��������
        else
            cout << setw(4) << 0;
    }
    cout << endl;
}

// ������� ��� ���������� ���� ������������� �������
void CalculateModifiedSum(int* array, const int size)
{
    int sum = 0; // ����� ��� ��������� ����
    for (int i = 0; i < size; i++) {
        if (array[i] < 0 || i % 2 != 0) // �������� ����
            sum += array[i]; // ��������� �������� �� ����
    }
    cout << sum << endl; // ���� ���� ������������� �������
}

// ������� ��� ��������� ������� ������������� ��������
void CountModifiedNumbers(int* array, const int size)
{
    int count = 0; // ˳������� ������� ��������
    for (int i = 0; i < size; i++) {
        if (array[i] < 0 || i % 2 != 0) { // �������� ����
            count++; // ��������� ���������
        }
    }
    cout << count << endl; // ���� �������
}

int main() {
    srand((unsigned)time(NULL)); // ����������� ���������� ���������� �����

    const int n = 24; // ����� ������
    int a[n]; // ���������� ������
    int Low = -40; // ����� ���� ��������
    int High = 20; // ������ ���� ��������

    CreateArray(a, n, Low, High); // ������ ������� ��� ��������� ������

    cout << "Original array:" << endl;
    PrintArray(a, n); // ���� ������������ ������
    cout << "Modified array:" << endl;
    PrintModifiedArray(a, n); // ���� �������������� ������
    cout << "Sum of numbers:" << endl;
    CalculateSum(a, n); // ���������� �� ���� ����
    cout << "Count of elements:" << endl;
    CountNumbers(a, n); // ���� ������ ������
    cout << "Sum of modified numbers:" << endl;
    CalculateModifiedSum(a, n); // ���������� �� ���� ���� ������������� �������
    cout << "Count of modified numbers:" << endl;
    CountModifiedNumbers(a, n); // ϳ�������� �� ���� ������� ������������� ��������

    return 0;
}
