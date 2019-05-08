#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include <iostream>
using namespace std;
class matrix
{
private:
	int row;
	int col;
	float** data;
public:
	int getRow(void)
	{
		return this->row;
	}
	int getCol(void)
	{
		return this->col;
	}
	matrix();
	matrix(int, int);
	matrix(float*a[], int ,int);
	bool isSameSize(const matrix&);
	matrix(const matrix&);
	void operator=(const matrix&);
	matrix operator+(const matrix&);
	matrix operator-(const matrix&);
	bool operator==(const matrix&);
	matrix operator*(const matrix&);
	void display();
	friend ostream& operator<<(ostream&, const matrix&);
};

#endif // MATRIX_H_INCLUDED
