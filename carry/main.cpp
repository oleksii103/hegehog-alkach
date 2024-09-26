#include "fraction.h"
#include <iostream>

int main() {
    Fraction frac1(3, 4);
    Fraction frac2(2, 5);

    Fraction result = frac1 + frac2;
    std::cout << "3/4 + 2/5 = ";
    result.print();

    result = frac1 - frac2;
    std::cout << "3/4 - 2/5 = ";
    result.print();

    result = frac1 * frac2;
    std::cout << "3/4 * 2/5 = ";
    result.print();

    result = frac1 / frac2;
    std::cout << "3/4 / 2/5 = ";
    result.print();

    return 0;
}
