/*
	Week 12 Programming Assignment
	Craigory Coppola
*/

#include <iostream>
using namespace std;

// Function Prototype
int doSomething(int * x, int * y);

int main(){
	int a = 2; //Declare A
	int b = 1; //Declare B
	int * x = &a; // X points to A (*x = A)
	int * y = &b; // Y points to B (*y = B)
	cout<<"Init X:"<<*x<< endl << "Init Y:"<<*y << endl; //Display initial Variables
	int result = doSomething(x,y); //Execute F(x)
	cout<<"X:"<<*x<< endl << "Y:"<<*y << endl << "RESULT OF doSomething: " <<result <<endl; //Display results
	system("PAUSE"); //Wait for user to close
	return(0); //Return
}

int doSomething(int *x, int * y){ //Takes ptr to each variable
	int temp = *x; //Temp assigned value at y address
	*x = *y * 10; //Value in memory at x changed to 10*value stored at y
	*y = temp * 10; //Value stored at why changed to 10*temp
	return *x + *y;
}