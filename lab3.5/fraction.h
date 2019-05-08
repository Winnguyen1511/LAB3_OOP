#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED
#include "cmath"
#include <iostream>
#include <string>
using namespace std;
class fraction
{
private:
    int numerator;
    int denominator;
    int gcd(int x, int y)
    {
        if(x%y == 0)
            return y;
        else
            return gcd(y, x%y);
    }
public:
    fraction()
    {
        this->numerator = 0;
        this->denominator = 1;
    }
    fraction(int n, int d)
    {
        this->numerator = n;
        this->denominator = d;
    }
    fraction(const fraction& that)
    {
        this->numerator = that.numerator;
        this->denominator = that.denominator;
    }
    fraction operator=(const fraction&);
    fraction operator+(const fraction&);
    fraction operator-(const fraction&);
    bool operator==(const fraction&);
    fraction operator*(const fraction&);
    void display(void);
    friend ostream& operator<<(ostream&, const fraction&);
    friend istream& operator>>(istream&, fraction&);
};
#endif // FRACTION_H_INCLUDED
