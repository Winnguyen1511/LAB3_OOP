#include "fraction.h"
fraction fraction::operator=(const fraction& that)
{
    fraction tmp;
    tmp.numerator = that.numerator;
    tmp.denominator = that.numerator;
    return tmp;
}
fraction fraction::operator+(const fraction& that)
{
    fraction tmp;
    tmp.denominator = abs(this->denominator*that.denominator)/
                        (gcd(this->denominator,that.denominator));
    tmp.numerator = (this->numerator)*(tmp.denominator/this->denominator)
                    +(that.numerator)*(tmp.denominator/that.denominator);
    return tmp;
}
fraction fraction::operator-(const fraction& that)
{
    fraction tmp;
    tmp.denominator =   abs(this->denominator*that.denominator)/
                        (gcd(this->denominator,that.denominator));
    tmp.numerator = (this->numerator)*(tmp.denominator/this->denominator)
                    -(that.numerator)*(tmp.denominator/that.denominator);
    return tmp;
}
bool fraction::operator==(const fraction& that)
{
    return this->numerator / this->denominator
            == that.numerator / that.denominator;
}
fraction fraction::operator*(const fraction& that)
{
    fraction tmp;
    int tmpNum, tmpDen, tmpDiv;
    tmpNum = this->numerator * that.numerator;
    tmpDen = this->denominator * that.denominator;
    tmpDiv = gcd(tmpNum, tmpDen);
    tmp.numerator = tmpNum / tmpDiv;
    tmp.denominator = tmpDen / tmpDiv;
    return tmp;
}
void fraction::display(void)
{

}
ostream& operator<<(ostream& out, const fraction& that)
{
    out<<that.numerator<<"/"<<that.denominator;
    return out;
}
istream& operator>>(istream& in, fraction& that)
{
    string tmp;
    in>>tmp;
    int fpos = tmp.find_first_of('/');
    that.numerator = tmp[0] - '0';
    for(int i = 1; i < fpos; i++)
        that.numerator = that.numerator*10 + (tmp[i] - '0');
    that.denominator = tmp[fpos+1] - '0';
    for(int i = fpos+2; i < tmp.size(); i++)
        that.denominator = that.denominator*10 +(tmp[i] = '0');
    return in;
}
