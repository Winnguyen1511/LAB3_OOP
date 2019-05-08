#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class complex
{
private :
    float real, image;
public:
    complex()
    {
        this->real = this->image = 0;
    }
    //complex()
    complex(const complex& that)
    {
        this->real = that.real;
        this->image = that.image;
    }
    complex operator=(const complex&);
    complex operator+(const complex&);
    complex operator-(const complex&);
    bool operator==(const complex&);
    complex operator*(const complex&);
    void display(void);
    friend ostream &operator<<(ostream&, const complex &);
    friend istream &operator>>(istream&, complex &);
};

#endif // COMPLEX_H_INCLUDED
