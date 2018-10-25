/*
	Week 7 Programming Assignment
	Craigory Coppola
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	double totalSales = 0;
	cout << "This program will calculate average sales over a \n period of years.";
	
	/////////////////////////////
	////Get Years to Average ////
	/////////////////////////////
	
	double yearsAveraged; //Declare variable to hold number of years
	bool invalidInput = true;
	while(invalidInput){ //Loop to ensure proper input
		cout << "How many years do you wish to average? ";
		try
		{
			cin >> yearsAveraged; //Attempt to get property value from user
			if(yearsAveraged < 1)
			{
				throw(1); //Value too low, Years should be greater than 1
			}
			else
			{
				invalidInput = false; //Exit infinite loop
			}
		}
		catch (int e) //Catch errors from input
		{
			if(e==1)
			{
				cout << "You must enter at least 1 year.\n"; //catch thrown error
			}
		}
	}
	
	//////////////////////////////////////////////////////
	////Loop through each year and get quarter values ////
	//////////////////////////////////////////////////////
	
	for(int year = 1;year <= yearsAveraged; year++){
		cout << "Year " << year << endl;
		for(int quarter = 1; quarter <= 4; quarter++){
			cout << "sales amount for quarter " << quarter << "? ";
			double quarterlyAmount; //Declare variable to hold quarterlySales
			while(true){
				try
				{
					cin >> quarterlyAmount; //Attempt to get quarterly sales
					if(quarterlyAmount < 0)
					{
						throw(1); //Value out of bounds
					}
					else
					{
						break; //Exit infinite loop
					}
				}
				catch (int e) //Catch errors from input
				{
					if(e==1)
					{
						cout << "Sales must be positive. \n"; //catch thrown error
					}
					cout << "Please enter a correct quarterly sales amount: "; 
				}
			}
			totalSales += quarterlyAmount;
		}
	}
	
	
	//////////////////////
	///////Do Math ///////
	//////////////////////
	int numQuarters = yearsAveraged*4;
	double averageSales = totalSales / numQuarters;
	//////////////////////
	///Display Results////
	//////////////////////
	cout << "\nOver a period of " << numQuarters << " quarters, $" << totalSales << endl;
	cout << fixed << setprecision(2) << "Average quarterly sales for the period is $" << averageSales << endl;
 	
	system("pause");
	
}
