#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;

class Fraction
{
public:
    Fraction();
    Fraction(int whole);
    Fraction(int top, int bottom);
    Fraction(int whole, int top, int bottom);
    Fraction(const Fraction &fraction); //copy constructor
    ~Fraction();

    Fraction& operator=(Fraction &other);
    Fraction& operator=(Fraction other);

    friend ostream& operator<<(ostream &out, const Fraction &x);
    friend istream& operator>>(istream &in, Fraction &x);
    friend Fraction operator+(const Fraction &x, const Fraction &y);
    friend Fraction operator-(const Fraction &x, const Fraction &y);
    friend Fraction operator*(const Fraction &x, const Fraction &y);
    friend Fraction operator/(const Fraction &x, const Fraction &y);
    friend bool operator>(const Fraction &x, const Fraction &y);
    friend bool operator<(const Fraction &x, const Fraction &y);
    friend bool operator>=(const Fraction &x, const Fraction &y);
    friend bool operator<=(const Fraction &x, const Fraction &y);
    friend bool operator==(const Fraction &x, const Fraction &y);
    friend bool operator!=(const Fraction &x, const Fraction &y);

private:
    int mixed, num, denom;

    void reduce();
    int gcd(int p, int q);
    void copy(const Fraction &other);
};

#endif // FRACTION_H
