#pragma once
#include<iostream>

template<class t>
class Matrix
{
public:
	Matrix(int, int, t*);
	Matrix(int, int);
	Matrix();


	void transpose();
	void push(t);
	Matrix<t> operator*(Matrix<t>);
	Matrix<t> operator+(Matrix<t>);
	Matrix<t> operator-(Matrix<t>);
	template<class t> friend std::ostream& operator<<(std::ostream& os, Matrix<t> m);
	template<class t> friend std::istream& operator>>(std::istream& is, Matrix<t> m);
protected:
	int size_x;
	int size_y;
	t * data;
};


