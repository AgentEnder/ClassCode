#include<iostream>
#include "Matrix.h"
#include "Matrix.cpp"

using namespace std;

int main() {
	int width, height;
	cout << "Enter matrix height: ";
	cin >> height;
	cout << "Enter matrix width: ";
	cin >> width;
	Matrix<int> MatrixOne(width, height);
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			cout << "Enter element " << i * height + j << ":";
			cin >> MatrixOne;
		}
	}
	cout << "Enter matrix 2 height: ";
	cin >> height;
	cout << "Enter matrix 2 width: ";
	cin >> width;
	Matrix<int> MatrixTwo(width, height);
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			cout << "Enter element " << i * height + j << ":";
			cin >> MatrixTwo;
		}
	}
	cout << "MatrixOne" << endl;
	cout << MatrixOne;
	cout << "MatrixTwo" << endl;
	cout << MatrixTwo;
	
	cout << endl<<"MatrixOne*MatrixTwo" << endl;
	cout << MatrixOne*MatrixTwo;
	cout << endl<<"MatrixOne Transposed" << endl;
	MatrixOne.transpose();
	cout << MatrixOne;
	cout << endl << "MatrixOne+MatrixTwo" << endl;
	cout << MatrixOne + MatrixTwo;
	cout << endl << "MatrixOne-MatrixTwo" << endl;
	cout << MatrixOne - MatrixTwo;
	cout << endl << endl << "Input an item to add to Matrix One: ";
	cin >> MatrixOne;
	cout << endl << "Modified MatrixOne" << endl;
	cout << MatrixOne;
	getchar();
	getchar();
	getchar();
	return 0;
}