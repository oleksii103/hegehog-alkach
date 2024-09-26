#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
private:
    int numerator;
    int denominator;
    void reduce(); 
    int gcd(int a, int b);

public:
    Fraction(int num = 0, int denom = 1);

    int getNumerator() const;
    int getDenominator() const;

    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    void print() const;
};

#endif
