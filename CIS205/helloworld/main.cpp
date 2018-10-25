#include <cstdlib>
#include <iostream>

using namespace std;

float add(float x, float y)
{
	float sum = x+y;
	return sum;
}
float sub(float x, float y)
{
	float sum = x-y;
	return sum;
}
float mult(float x, float y)
{
	float product = x*y;
	return product;
}
float divi(float x, float y)
{
	float quotient = x/y;
	return quotient;
}

int main(int argc, char** argv) 
{
	cout << "Would you like to (1)add, (2)subtract, (3)multiply, or (4)divide 2 numbers? \a\a\n";
	int op;
	cin >> op;
	float a,b,value;
	cout << "Enter value 1: ";
	cin >> a;
	cout << "Enter value 2: ";
	cin >> b;
	if(op == 1) {
		value = add(a,b);
	}
	else if(op == 2){
		value = sub(a,b);
	}
	else if (op == 3){
		value = mult(a,b);
	}
	else if (op == 4){
		value = divi(a,b);
	}

	cout << value;
	cout << "\n";
	system("PAUSE");
	return 0;
}
