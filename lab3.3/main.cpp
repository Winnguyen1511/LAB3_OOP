// Lab3_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "matrix.h"
using namespace std;
int main()
{
	srand(time(0));
	float** tmp, **tmp2;
	tmp = new float* [3];
	for (int i = 0; i < 3; i++)
		tmp[i] = new float[2];
	tmp2 = new float* [2];
	for (int i = 0; i < 2; i++)
		tmp2[i] = new float[3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			tmp[i][j] = (rand() % (10 - 1)) + 1;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tmp2[i][j] = (rand() % (10 - 1)) + 1;
		}
	}
	matrix A(tmp, 3, 2), B(tmp2, 2, 3);
	cout << "Here are 2 example matrixes: ";
	cout << ">matrix A: \n";
	cout << A;
	cout << endl<<">matrix B: \n";
	cout << B;
	cout << ">>Testing the multiply operation: \n";
	cout << "A*B = \n" << A * B;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
