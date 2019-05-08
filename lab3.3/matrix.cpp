#include "matrix.h"


matrix::matrix()
{

}
matrix::matrix(int n, int m)
{
	this->row = n;
	this->col = m;
	this->data = new float* [n];
	for (int i = 0; i < n; i++)
	{
		this->data[i] = new float[m];
	}
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			this->data[i][j] = 0;
		}
	}
}
bool matrix::isSameSize(const matrix& that)
{
	return (this->row == that.row) && (this->col == that.col);
}
matrix::matrix(float* a[], int m, int n)
{
	this->row = m;
	this->col = n;
	this->data = new float* [m];
	for (int i = 0; i < m; i++)
	{
		this->data[i] = new float[n];
	}
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			this->data[i][j] = a[i][j];
		}
	}
}
void matrix::operator=(const matrix & that)
{
	this->row = that.row;
	this->col = that.col;
	this->data = that.data;

}
matrix::matrix(const matrix & that)
{
	this->row = that.row;
	this->col = that.col;
	this->data = new float* [that.row];
	for (int i = 0; i < this->row; i++)
	{
		this->data[i] = new float[this->col];
	}
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			this->data[i][j] = that.data[i][j];
		}
	}
}
matrix matrix::operator+(const matrix & that)
{
	if (!this->isSameSize(that))
	{
		cout << "Two matrix must have same size!";
		return *this;
	}
	matrix tmpMat(this->row, this->col);
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; this->col; j++)
		{
			tmpMat.data[i][j] = this->data[i][j] + that.data[i][j];
		}
	}
	return tmpMat;
}


matrix matrix:: operator-(const matrix & that)
{
	if (!this->isSameSize(that))
	{
		cout << "Two matrix must have same size!\n";
		return *this;
	}
	matrix tmpMat(this->row, this->col);
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j <this->col; j++)
		{

			tmpMat.data[i][j] = this->data[i][j] - that.data[i][j];
		}
	}
	return tmpMat;
}
bool matrix::operator==(const matrix & that)
{
	if (!this->isSameSize(that))
	{
		//cout<<"Two matrix must have same size!";
		return false;
	}
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j <this->col; j++)
		{
			if (this->data[i][j] != that.data[i][j]) return false;
		}
	}
	return true;
}
matrix matrix::operator*(const matrix & that)
{
	if (this->col != that.row)
	{
		cout << "Error operation!\n";
		return *this;
	}
	matrix tmpMat(this->row, that.col);
	//cout<<tmpMat;
	for (int i = 0; i < tmpMat.row; i++)
	{
		for (int j = 0; j < tmpMat.col; j++)
		{
			for (int k = 0; k < this->col; k++)
			{
			    //cout<<this->data[i][k]<<","<<that.data[k][j];
				tmpMat.data[i][j] += (this->data[i][k]) * (that.data[k][j]);
				//cout<<tmpMat.data[i][j];
			}
		}
	}
	return tmpMat;
}
void matrix::display()
{
	for (int i = 0; i < this->row; i++)
	{
		cout << "[";
		for (int j = 0; j < this->col; j++)
		{
			cout << this->data[i][j]<<",";
		}
		cout << "]" << endl;
	}
}
ostream& operator<<(ostream&out, const matrix&that)
{
	for (int i = 0; i < that.row; i++)
	{
		out << "[";
		for (int j = 0; j < that.col; j++)
		{
			out << that.data[i][j]<<",";
		}
		out << "]" << endl;
	}
	return out;
}
