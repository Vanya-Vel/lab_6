// Lab_06_4.cpp
// < ������� ���� >
// ����������� ������ � 6.4
// ����������� �� ������������� ����������� ��������� ������
// ������ 0.3

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

// ������� ��� ��������� ������ ���������� ����� � �������� �������
void GenerateRandomArray(int* array, const int size, const int low, const int high, int i = 0) 
{
    // ��������� ���������� ����� ��� ������ � ������� �� low �� high
    if (i < size)
    {
        array[i] = low + rand() % (high - low + 1);
        GenerateRandomArray(array, size, low, high, i + 1);
    }
}

// ������� ��� ��������� ������ �� �����
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

// ������� ��� ���������� ������� ������ �������� ������
void ProductEvenElements(int* array, const int size, int prod = 1, int i = 0)
{
    if (i % 2 == 0) 
    { // �������� �� ������ ������
        prod *= array[i]; // ��������� �������� �� �������
    }

    if (i < size - 1)
    {
        ProductEvenElements(array, size, prod, i + 1);
    }
    else
        if(prod > 1)
            cout << "Product of even elements: " << prod << endl; // �������� �������
        else
            cout << "No even elements found." << endl; // ���� ������ �������� ����
}

// ���������� ������� ��� ������������� �������� �� ������ � ������� ��������� ����������
void SumFirstLastZeroElements(int* array, const int size, int firstZero = -1, int lastZero = -1, int i = 0, int sum = 0) {
    // ����� ������� ��������� ��������
    if (firstZero == -1 && i < size) 
    {
        if (array[i] == 0) 
        {
            firstZero = i; // �����'������� ������ �������� �������
        }
    }

    // ����� ���������� ��������� ��������
    if (i == size - 1 && lastZero == -1) 
    {
        if (array[i] == 0) 
        {
            lastZero = i; // �����'������� ������� �������� �������
        }
    }

    // ���� �� ������� ������ �������� ��������
    if (firstZero != -1 && lastZero != -1 && firstZero != lastZero)
    {
            // ���� �������� ������ ����� �� ������ �������� � ������ �� �������
            if (i > firstZero && i < lastZero) 
            {
                sum += array[i]; // ������ �������� �������� �� ����
            }
    }

    // ����������� ������
    if (i < size - 1) 
    {
        SumFirstLastZeroElements(array, size, firstZero, lastZero, i + 1, sum); // ���������� �� ���������� ��������
    }
    else 
    {
        // ��������� ���������� ���� ������
        if (firstZero != -1 && lastZero != -1 && firstZero != lastZero) 
        {
            cout << "Sum: " << sum << endl; // �������� ����
        }
        else 
        {
            cout << "In massif not zero elements" << endl; // ���� �������� �� �������� ��� ���� �������
        }
    }
}

// ������� ��� ���������� ������: �������� ������ ��������, ���� ��'���
void Sort(int* array, const int size, int index = 0)
{
    // ������� �������: ���� ������ ����� ���� ������
    if (index >= size)
        return;

    // �������� �������� �� ������ �������� ������ (��������� ���)
    if (array[index] >= 0) {
        cout << setw(4) << array[index];  // ��������� ��������� ��������
    }

    // ���������� ���������� ��������� �������
    Sort(array, size, index + 1);

    // ���� �������� �� ��'��� �������� ������
    if (array[index] < 0) {
        cout << setw(4) << array[index];  // ��������� ��'������ ��������
    }
}

// ������� �������
int main() {
    srand((unsigned)time(NULL)); // ����������� ���������� ���������� �����

    int n; // ����� ������

    cout << "to write a size: "; cin >> n; // �������� ����� ������

    int* a = new int[n]; // ���������� ������ ��������
    int low = -40; // ����� ���� ��������
    int high = 40; // ������ ���� ��������

    // ��������� ���������� ����� ��� ������
    GenerateRandomArray(a, n, low, high);

    // ��������� ������
    PrintArray(a, n, low, high);

    // ���������� �� ��������� ������� �������� � ������� ���������
    ProductEvenElements(a, n);

    // ���������� ���� �������� �� ������ � ������� �������� ����������
    SumFirstLastZeroElements(a, n);

    // ��������� ������, � ����� �������� ������ ��������, � ���� ��'���
    Sort(a, n);

    delete[] a; // ��������� �������� �������� �����

    return 0;
}
