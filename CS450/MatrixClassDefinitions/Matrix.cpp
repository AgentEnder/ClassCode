#include<iostream>
#include "Matrix.h"


template<class t>
Matrix<t>::Matrix(int w, int h, t* elements)
{
	data = new t[w*h];
	size_x = w;
	size_y = h;
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			int idx = i * size_y + j;
			data[idx] = elements[idx];
		}
	}
}

template<class t>
Matrix<t>::Matrix(int w, int h)
{
	size_x = w;
	size_y = h;
	data = new t[size_x*size_y];
}

template<class t>
Matrix<t>::Matrix()
{
	size_x = 3;
	size_y = 3;
	data = new t[size_x*size_y];
}


template<class t>
void Matrix<t>::transpose()
{
	t * new_data = new t[size_x*size_y];
	for (int i = 0; i < size_x; i++)
	{
		for (int j = 0; j < size_y; j++)
		{
			int idx_original = i * size_y + j;
			int idx_new = j * size_x + i;
			new_data[idx_new] = data[idx_original];
		}
	}
	int temp = size_x;
	size_x = size_y;
	size_y = temp;
	delete[] data;
	data = new_data;
}

template<class t>
void Matrix<t>::push(t item)
{
	for (int i = 0; i < size_x*size_y - 1; i++)
	{
		data[i] = data[i + 1];
	}
	data[size_x*size_y - 1] = item;
}

template<class t>
Matrix<t> Matrix<t>::operator*(Matrix<t> other)
{
	t * new_data = new t[size_x*other.size_y];
	if (size_x == other.size_y && other.size_x == size_y) {
		for (int i = 0; i < size_x; i++)
		{
			for (int j = 0; j < other.size_y; j++)
			{
				t sum = 0;
				for (int k = 0; k < size_y; k++)
				{
					sum += data[i*size_y + k] * other.data[k*other.size_y + j];
				}
				new_data[i*other.size_y + j] = sum;
			}
		}
		return Matrix<t>(size_x, other.size_y, new_data);
	}
	else {
		std::cerr << "Invalid Matrix Multiplication" << std::endl;
		return Matrix<t>();
	}
}


template<class t>
Matrix<t> Matrix<t>::operator+(Matrix<t> other)
{
	if (!(size_x == other.size_x && size_y == other.size_y))
	{
		std::cerr << "Can only add matrices with equal dimensions" << std::endl;
	}
	else {
		t * new_data = new t[size_x*size_y];
		for (int i = 0; i < size_x; i++)
		{
			for (int j = 0; j < size_y; j++)
			{
				int idx = i * size_y + j;
				new_data[idx] = data[idx] + other.data[idx];
			}
		}
		return Matrix<t>(size_x, size_y, new_data);
	}
	return Matrix<t>();
}

template<class t>
Matrix<t> Matrix<t>::operator-(Matrix<t> other)
{
	if (!(size_x == other.size_x && size_y == other.size_y))
	{
		std::cerr << "Can only subtract matrices with equal dimensions" << std::endl;
	}
	else {
		t * new_data = new t[size_x*size_y];
		for (int i = 0; i < size_x; i++)
		{
			for (int j = 0; j < size_y; j++)
			{
				int idx = i * size_y + j;
				new_data[idx] = data[idx] - other.data[idx];
			}
		}
		return Matrix<t>(size_x, size_y, new_data);
	}
	return Matrix<t>();
}

template<class t>
void Matrix<t>::print_data()
{
	std::cout << std::endl;
	for (int i = 0; i < size_x*size_y; i++)
	{
		std::cout << data[i] << ",";
	}
	std::cout << std::endl;
}

template<class t>
std::ostream & operator<<(std::ostream & os, Matrix<t> m)
{
	for (int i = 0; i < m.size_x; i++)
	{
		os << std::endl;
		for (int j = 0; j < m.size_y; j++)
		{
			os << m.data[i*m.size_y + j] << "\t";
		}
	}
	os << std::endl;
	return os;
}

template<class t>
std::istream & operator>>(std::istream & is, Matrix<t> m)
{
	t temp;
	is >> temp;
	m.push(temp);
	return is;
}

