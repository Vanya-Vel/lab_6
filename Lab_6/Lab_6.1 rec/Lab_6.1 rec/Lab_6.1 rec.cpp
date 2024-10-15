#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// ������� ��� ��������� ������ ���������� ����� � �������� �������
void CreateArray(int* array, const int size, const int Low, const int High, int i)
{
    if (i < size)
    {
        array[i] = Low + rand() % (High - Low + 1); // ��������� ����������� �����
        CreateArray(array, size, Low, High, i + 1);
    }
}


// ������� ��� ��������� ������ �� �����
void PrintArray(int* array, const int size, int i)
{
    if (i < size)
    {
        cout << setw(4) << array[i]; // ���� ������� ��������
        PrintArray(array, size, i + 1);
    }
    if(i == size -1)
        cout << endl;
}

// ������� ��� ���������� ���� ��� �������� ������
void CalculateSum(int* array, const int size, int i, int sum)
{
    if (i < size)
    {
        sum += array[i];
        CalculateSum(array, size, i + 1, sum);
    }
    if(i == size - 1)
        cout << sum << endl; // ���� ����
}

// ������� ��� ��������� ������ ������
void CountNumbers(int* array, const int size, int i, int count)
{
    if (i < size)
    {
        count++; // ��������� ���������
        CountNumbers(array, size, i + 1, count);
    }
    if (i == size - 1)
    cout << count << endl; // ���� �������
}

// ������� ��� ��������� �������������� ������ (�������� < 0 ��� � ��������� ���������)
void PrintModifiedArray(int* array, const int size, int i)
{
    if (i < size) // �������� �� ����� ������
    {
        if (array[i] < 0 || i % 2 != 0) // �������� ����
        {
            cout << setw(4) << array[i]; // ���� ��������
        }
        else
            cout << setw(4) << 0;
        PrintModifiedArray(array, size, i + 1); // ����������� ������
    }

    if (i == size - 1) // ������ ����� ����� ���� ���� ���������� ������
        cout << endl; // ���� ������ �����
    
}

// ������� ��� ���������� ���� ������������� �������
void CalculateModifiedSum(int* array, const int size, int i, int sum)
{
    if (i < size)
    {
        if (array[i] < 0 || i % 2 != 0) // �������� ����
        {
            sum += array[i]; // ��������� �������� �� ����
        }
        CalculateModifiedSum(array, size, i + 1, sum); // ����������� ������ �� ��������� ����
    }
    if (i == size - 1)
        cout << sum << endl; // ���� ����
    
}

// ������� ��� ��������� ������� ������������� ��������
void CountModifiedNumbers(int* array, const int size, int i, int count)
{
    if (i < size)
    {
        if (array[i] < 0 || i % 2 != 0) // �������� ����
        {
            count++; // ��������� ���������
        }
        CountModifiedNumbers(array, size, i + 1, count);
    }
    if (i == size - 1)
        cout << count << endl;
}

int main() {
    srand((unsigned)time(NULL)); // ����������� ���������� ���������� �����

    const int n = 24; // ����� ������
    int a[n]; // ���������� ������
    int Low = -40; // ����� ���� ��������
    int High = 15; // ������ ���� ��������

    CreateArray(a, n, Low, High, 0); // ������ ������� ��� ��������� ������

    cout << "Original array:" << endl;
    PrintArray(a, n, 0); // ���� ������������ ������
    cout << "Modified array:" << endl;
    PrintModifiedArray(a, n, 0); // ���� �������������� ������
    cout << "Sum of numbers:" << endl;
    CalculateSum(a, n, 0, 0); // ���������� �� ���� ����
    cout << "Count of elements:" << endl;
    CountNumbers(a, n, 0, 0); // ���� ������ ������
    
    cout << "Sum of modified numbers:" << endl;
    CalculateModifiedSum(a, n, 0, 0); // ���������� �� ���� ���� ������������� �������
    cout << "Count of modified numbers:" << endl;
    CountModifiedNumbers(a, n, 0, 0); // ϳ�������� �� ���� ������� ������������� ��������

    return 0;
}
