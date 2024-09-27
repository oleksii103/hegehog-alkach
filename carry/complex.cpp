#include <iostream>
#include <math.h>

using namespace std;

class Complex {
private:
    int real;
    int imeg;
public:

    Complex(int real1, int imeg1) :real(real1), imeg(imeg1) {}
    Complex() {
        int real = 1;
        int imeg = 3;
    }

    int Real() {
        return this->real;
    }
    void Real(int R) {
        this->real = R;
    }
    int Imeg() {
        return this->imeg;
    }
    void Imeg(int I) {
        this->imeg = I;
    }

    void operator+(Complex C2) { //z1 + z2 = (1 + 3i) + (2 + i) = 3 + 4i
        this->real = Real() + C2.Real();
        this->imeg = Imeg() + C2.Imeg();
    }
    void operator-(Complex C2) {//z1 - z2 = (1 + 3i) - (2 + i) = -1 + 2i
        this->real = Real() - C2.Real();
        this->imeg = Imeg() - C2.Imeg();
    }
    void operator*(Complex C2) {//z1 * z2 = (1 + 3i) * (2 + i) = (2 - 3) + i(1 + 6) = -1 + 7i
        int R = Real();
        int I = Imeg();
        this->real = (R * C2.Real()) + -1 * (I * C2.Imeg());
        this->imeg = (I * C2.Real()) + (R * C2.Imeg());
    }
    /*
        z1   1 + 3i    (1 + 3i) * (2 - i)   2 - i + 6i + 3
        __ = ------- = ------------------ = -------------- = 1 + i
        z2   2 + i      (2 + i) * (2 - i)       4 + 1
    */
    void operator/(Complex C2) {
        int R = Real();
        int I = Imeg();
        this->real = ((R * C2.Real()) + (I * C2.Imeg())) / (pow(C2.Real(), 2) + pow(C2.Imeg(), 2));
        this->imeg = ((I * C2.Real()) + (R * C2.Imeg())) / (pow(C2.Real(), 2) + pow(C2.Imeg(), 2));
    }

};

int main()
{
    Complex C1(1, 3);
    Complex C2(2, 1);

    int choice;

    cout << "\n1)Addition\n2)Subtraction\n3)Multiplication\n4)Division\n";
    cout << "Enter an arithmetic operation:";
    cin >> choice;

    switch (choice)
    {
    case 1: C1 + C2;
        break;
    case 2: C1 - C2;
        break;
    case 3: C1 * C2;
        break;
    case 4: C1 / C2;
        break;
    default:
        break;
    }

    cout << C1.Real() << (C1.Imeg() >= 0 ? " + " : " - ") << abs(C1.Imeg()) << 'i';
}