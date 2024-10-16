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
void GenerateRandomArray(int* array, const int size, const int low, const int high) {
    // ��������� ���������� ����� ��� ������ � ������� �� low �� high
    for (int i = 0; i < size; i++) {
        array[i] = low + rand() % (high - low + 1); // ��������� ����������� ����� � �������� �������
    }
}

// ������� ��� ��������� ������ �� �����
void PrintArray(int* array, const int size, const int low, const int high) {
    cout << "Array elements within the range [" << low << ", " << high << "]:" << endl;
    // ��������� �������� ������, �� ����������� � �������� ������� [low, high]
    for (int i = 0; i < size; i++) {
        if (array[i] >= low && array[i] <= high) {
            cout << setw(4) << array[i]; // ��������� ��������
        }
    }
    cout << endl;
}

// ������� ��� ���������� ������� ������ �������� ������
void ProductEvenElements(int* array, const int size)
{
    int prod = 1; // ����������� ����� ��� �������

    // �������� ��� �������� ������ �� ������� �� ���������
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) { // �������� �� ������ ������
            prod *= array[i]; // ��������� �������� �� �������
        }
    }

    // ���� ������� ����� 1 (����� ���� �������� �������), �������� ����
    if (prod > 1)
        cout << "Product of even elements: " << prod << endl; // �������� �������
    else
        cout << "No even elements found." << endl; // ���� ������ �������� ����
}

// ������� ��� ���������� ���� �������� �� ������ � ������� ��������� ����������
void SumFirstLastZeroElements(int* array, const int size)
{
    int Sum = 0; // ����������� ����� ��� ����
    int FirstZeroElement = -1; // ������ ������� ��������� ��������
    int SecondZeroElement = -1; // ������ ���������� ��������� ��������

    // ����� ������� ��������� ��������
    for (int i = 0; i < size; i++) {
        if (array[i] == 0) {
            FirstZeroElement = i;
            break; // ���� ��������� ������ ����, ���������� �����
        }
    }

    // ����� ���������� ��������� ��������
    for (int k = size - 1; k >= 0; k--) {
        if (array[k] == 0) {
            SecondZeroElement = k;
            break; // ���� ��������� ������� ����, ���������� �����
        }
    }

    // ���� ������ �������� �������� �������� � ���� �� ����������
    if (FirstZeroElement != -1 && SecondZeroElement != -1 && FirstZeroElement != SecondZeroElement)
    {
        // ϳ��������� �������� �� ������ � ������� ��������� ����������
        for (int j = FirstZeroElement + 1; j < SecondZeroElement; j++) {
            Sum += array[j]; // ��������� �������� �� ����
        }
        cout << "Sum: " << Sum << endl; // ��������� ���� ��������
    }
    else
        cout << "In massif not zero elements"; // ���� �������� �������� ���� ��� ���� �������
    cout << endl;
}

// ������� ��� ���������� ������: �������� ������ ��������, ���� ��'���
void Sort(int* array, const int size)
{
    cout << "Sort array: " << endl;
    // �������� �������� �� ������ �������� ������
    for (int i = 0; i < size; i++) {
        if (array[i] >= 0) { // �������� �� ������� �������
            cout << setw(4) << array[i]; // ��������� ������� ��������
        }
    }

    // ���� �������� �� ��'��� �������� ������
    for (int j = 0; j < size; j++) {
        if (array[j] < 0) { // �������� �� ��'����� �������
            cout << setw(4) << array[j]; // ��������� ��'����� ��������
        }
    }
}

// ������� �������
int main() {
    srand(static_cast<unsigned>(time(nullptr))); // ����������� ���������� ���������� �����

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
