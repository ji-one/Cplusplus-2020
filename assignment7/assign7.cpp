#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

class Matrix
{
	int **values;
	int row, column;

public:
	Matrix(int _row, int _column)
		: row(_row), column(_column), values(new int *[_row])
	{
		for (int i = 0; i < _row; i++)
		{
			values[i] = new int[_column];
			memset(values[i], 0, sizeof(int) * _column);
		}
	}

	Matrix operator+(const Matrix &matrix) const
	{
		Matrix m(matrix.row, matrix.column);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				m.values[i][j] = (matrix.values[i][j] + values[i][j]);
			}
		}
		return m;
	}

	Matrix operator*(const int n) const
	{
		Matrix m(row, column);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				m.values[i][j] = n * values[i][j];
			}
		}
		return m;
	}

	void operator=(const Matrix &another)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				values[i][j] = another.values[i][j];
			}
		}
	}

	Matrix(const Matrix &another)
		: row(another.row), column(another.column), values(new int *[another.row])
	{
		for (int i = 0; i < row; i++)
		{
			values[i] = new int[column];
			for (int j = 0; j < column; j++)
			{
				values[i][j] = another.values[i][j];
			}
		}
	}

	~Matrix()
	{
		for (int i = 0; i < row; i++)
		{
			delete[] values[i];
		}
		delete[] values;
	}

	friend ostream &operator<<(ostream &os, const Matrix &matrix);
	friend istream &operator>>(istream &is, Matrix &matrix);
};

istream &operator>>(istream &is, Matrix &matrix)
{
	for (int i = 0; i < matrix.row; i++)
	{
		for (int j = 0; j < matrix.column; j++)
		{
			is >> matrix.values[i][j];
		}
	}
	return is;
}

ostream &operator<<(ostream &os, const Matrix &matrix)
{
	for (int i = 0; i < matrix.row; i++)
	{
		for (int j = 0; j < matrix.column; j++)
		{
			os << matrix.values[i][j] << ' ';
		}
		os << '\n';
	}
	return os;
}

int main()
{
	Matrix m1(2, 2), m2(2, 2);
	cin >> m1;
	cin >> m2;
	Matrix m3(m1 + m2);
	Matrix m4(2, 2);
	m4 = m3 * 10;
	cout << m3 << endl
		 << m4 << endl;
}
