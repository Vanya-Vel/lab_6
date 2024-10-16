// Lab_06_3.cpp
// < ������� ���� >
// ����������� ������ � 6.3
// ����������� ����������� ������ �� ��������� ��������� ������� �� �������
// ������ 0.3

#include <iostream>
#include <iomanip>
#include <ctime> // ������������� <ctime> ��� ��������� ���������� �����

using namespace std;

// ������� ��� ��������� ������ ���������� ����� � �������� �������
void GenerateRandomArray(int* array, const int size, const int low, const int high, int index = 0) {
    array[index] = low + rand() % (high - low + 1); // ��������� ����������� ����� � �������

    // ���� ������ ������ �� ����� ������, ���������� ��������� ������� ��� ���������� �������
    if (index < size - 1) {
        GenerateRandomArray(array, size, low, high, index + 1);
    }
}

// ������� ��� ��������� ������ �� �����
void PrintArray(int* array, const int size, const int low, const int high, int index = 0) {
    // �������� ��������� ��� ������� �������
    if (index == 0) {
        cout << "Array elements within the range [" << low << ", " << high << "]:" << endl;
    }

    // �������� �������, ���� �� � ����� ��������
    if (array[index] >= low && array[index] <= high) {
        cout << setw(4) << array[index];
    }

    // ���������� ��������� ������� ��� ���������� �������, ���� �� ������� ���� ������
    if (index < size - 1) {
        PrintArray(array, size, low, high, index + 1);
    }
    else {
        cout << endl; // ���������� �� ����� ����� ���� ��������� ��� ��������
    }
}

// ������� ��� ���������� ���� ������ �������� ������
void SumEvenElements(int* array, const int size, int index = 0, int sum = 0) {
    if (index < size) {
        // ������ �� ����, ���� ������� ������
        if (array[index] % 2 == 0) {
            sum += array[index];
        }
        // ���������� ��������� ������� ��� ���������� �������
        SumEvenElements(array, size, index + 1, sum);
    }
    else {
        cout << "Sum of even elements: " << sum << endl; // �������� �������� ����
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr))); // ����������� ���������� ���������� �����

    const int n = 20; // ����� ������
    int a[n]; // ���������� ������
    int low = -20; // ����� ���� ��������
    int high = 20; // ������ ���� ��������

    GenerateRandomArray(a, n, low, high); // ��������� ������
    PrintArray(a, n, low, high); // ��������� ������
    SumEvenElements(a, n); // ���������� �� ��������� ���� ������ ��������

    return 0;
}
