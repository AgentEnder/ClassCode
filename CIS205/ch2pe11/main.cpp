/*
	Craigory Coppola
	Chapter 2, Programming Excersize #11
*/

#include <iostream>
using namespace std;

const int NUMBER_OF_GALLONS = 20; //Number of gallons in gas tank
const double MILES_PER_GALLON_T = 23.5; //Number of miles per gallon on average in town
const double MILES_PER_GALLON_H = 28.9; //Number of miles per gallon on average on highway


int main()
{
	double hwayMiles = NUMBER_OF_GALLONS*MILES_PER_GALLON_H; //Calculate number of miles on highway
	double townMiles = NUMBER_OF_GALLONS*MILES_PER_GALLON_T; //Calculate number of miles in town
	
	cout << "In town you would get " << townMiles << " miles, "
		 << "\nOn the Highway you would get " << hwayMiles << " miles.\n";  //Display calculation results in console
	system("pause");
}
