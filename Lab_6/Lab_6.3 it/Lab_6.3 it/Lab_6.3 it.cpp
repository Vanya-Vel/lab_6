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
void GenerateRandomArray(int* array, const int size, const int low, const int high) {
    for (int i = 0; i < size; i++) {
        // ��������� ����������� ����� � ����� �� low �� high
        array[i] = low + rand() % (high - low + 1);
    }
}

// ������� ��� ��������� ������ �� �����
void PrintArray(int* array, const int size, const int low, const int high) {
    cout << "Array elements within the range [" << low << ", " << high << "]:" << endl;
    for (int i = 0; i < size; i++) {
        // �������� �������� ������, �� � ����� [low, high]
        if (array[i] >= low && array[i] <= high) {
            cout << setw(4) << array[i];
        }
    }
    cout << endl; // ���������� �� ����� �����
}

// ������� ��� ���������� ���� ������ �������� ������
void SumEvenElements(int* array, const int size) {
    int sum = 0; // ����������� ����� ��� ����
    for (int i = 0; i < size; i++) {
        // ������ �� ����, ���� ������� ������
        if (array[i] % 2 == 0) {
            sum += array[i];
        }
    }
    cout << "Sum of even elements: " << sum << endl; // �������� ���������
}

int main() {
    srand((unsigned)time(NULL)); // ����������� ���������� ���������� �����

    const int n = 20; // ����� ������
    int a[n]; // ���������� ������
    int low = -20; // ����� ���� ��������
    int high = 20; // ������ ���� ��������

    GenerateRandomArray(a, n, low, high); // ������ ������� ��� ��������� ������
    PrintArray(a, n, low, high); // ��������� ������
    SumEvenElements(a, n); // ���������� �� ��������� ���� ������ ��������

    return 0;
}
