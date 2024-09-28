#include <iostream>
#include <cmath>  // ��� sqrt

using namespace std;

// �������� �1: ������ ������� ��� ������ ���������� ������������� ������� ������
template<typename T>
T average(T* arr, int size) {
    T sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

// �������� �2: ������������ ������� ������� ��� ����������� ������ ������

// ˳���� ������� (a * x + b = 0)
template<typename T>
T solveLinearEquation(T a, T b) {
    if (a == 0) {
        cout << "�������: ���������� 'a' �� ���� ���������� ����.\n";
        return 0;
    }
    return -b / a;
}

// ��������� ������� (a * x^2 + b * x + c = 0)
template<typename T>
void solveQuadraticEquation(T a, T b, T c, T& root1, T& root2) {
    T discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        cout << "����������� ������ �� ����, ����� � �������.\n";
        return;
    }
    T sqrtDiscriminant = sqrt(discriminant);
    root1 = (-b + sqrtDiscriminant) / (2 * a);
    root2 = (-b - sqrtDiscriminant) / (2 * a);
}

// �������� �3: ������ ������� ��� ������ ��������� � ���� ���������
template<typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

// �������� �4: ������ ������� ��� ������ ������ � ���� ���������
template<typename T>
T findMin(T a, T b) {
    return (a < b) ? a : b;
}

// ������� ������� ��� ������������ ������
int main() {
    setlocale(LC_ALL, "ukr");
    // ������������ �������� �1
    int arr[] = { 1, 2, 3, 4, 5 };
    int size = 5;
    cout << "������ �����������: " << average(arr, size) << "\n";

    // ������������ �������� �2
    cout << "����� ������� ������� (2x + 3 = 0): " << solveLinearEquation(2.0, 3.0) << "\n";

    double root1, root2;
    solveQuadraticEquation(1.0, -3.0, 2.0, root1, root2);
    cout << "����� ����������� ������� (x^2 - 3x + 2 = 0): " << root1 << ", " << root2 << "\n";

    // ������������ �������� �3
    cout << "�������� � 3 � 7: " << findMax(3, 7) << "\n";

    // ������������ �������� �4
    cout << "̳���� � 3 � 7: " << findMin(3, 7) << "\n";

    return 0;
}
