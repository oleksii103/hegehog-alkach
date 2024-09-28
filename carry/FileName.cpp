#include <iostream>
#include <cmath>  // для sqrt

using namespace std;

// Завдання №1: Шаблон функції для пошуку середнього арифметичного значень масиву
template<typename T>
T average(T* arr, int size) {
    T sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

// Завдання №2: Перевантажені шаблони функцій для знаходження коренів рівнянь

// Лінійне рівняння (a * x + b = 0)
template<typename T>
T solveLinearEquation(T a, T b) {
    if (a == 0) {
        cout << "Помилка: коефіцієнт 'a' не може дорівнювати нулю.\n";
        return 0;
    }
    return -b / a;
}

// Квадратне рівняння (a * x^2 + b * x + c = 0)
template<typename T>
void solveQuadraticEquation(T a, T b, T c, T& root1, T& root2) {
    T discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        cout << "Дискримінант менший за нуль, корені є уявними.\n";
        return;
    }
    T sqrtDiscriminant = sqrt(discriminant);
    root1 = (-b + sqrtDiscriminant) / (2 * a);
    root2 = (-b - sqrtDiscriminant) / (2 * a);
}

// Завдання №3: Шаблон функції для пошуку максимуму з двох параметрів
template<typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

// Завдання №4: Шаблон функції для пошуку мінімуму з двох параметрів
template<typename T>
T findMin(T a, T b) {
    return (a < b) ? a : b;
}

// Головна функція для демонстрації роботи
int main() {
    setlocale(LC_ALL, "ukr");
    // Демонстрація завдання №1
    int arr[] = { 1, 2, 3, 4, 5 };
    int size = 5;
    cout << "Середнє арифметичне: " << average(arr, size) << "\n";

    // Демонстрація завдання №2
    cout << "Корінь лінійного рівняння (2x + 3 = 0): " << solveLinearEquation(2.0, 3.0) << "\n";

    double root1, root2;
    solveQuadraticEquation(1.0, -3.0, 2.0, root1, root2);
    cout << "Корені квадратного рівняння (x^2 - 3x + 2 = 0): " << root1 << ", " << root2 << "\n";

    // Демонстрація завдання №3
    cout << "Максимум з 3 і 7: " << findMax(3, 7) << "\n";

    // Демонстрація завдання №4
    cout << "Мінімум з 3 і 7: " << findMin(3, 7) << "\n";

    return 0;
}
