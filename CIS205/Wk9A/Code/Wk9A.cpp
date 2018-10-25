/*
	Week 9 Programming Assignment
	Craigory Coppola
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototype
double caltotalSales(double, double);
double calAverage(double, int);

int main()
{
	int years,				// The number of years 
		totalQuarters;		// The number of quarters
	double sales, 
		   totalSales = 0, // The total sales for all quarters
		   average;         // The average quarterly sales

	// Get the number of years.
	cout << "This program will calculate average sales over a \n"
		 << "period of years.  How many years do you wish to average? ";
	cin  >> years;

	// Validate the number of years.
	while (years < 1)
	{  cout << "Years must be at least one. Please re-enter: ";
		cin  >> years;
	}
	double salesArray[years*4]; //Array Size = Quarters(4) multiplied by years 
	
	for (int yearNumber = 1; yearNumber <= years; yearNumber++) 
	{
		cout << "\nYear " << yearNumber << endl;
      
		// Get the sales amount for each quarter.
		for (int quarter = 1; quarter <= 4; quarter++) 
		{  
			cout << "sales amount for quarter "
				 << setw(2) << quarter << "? ";
			cin  >> sales;
         
			// Validate the sales amount.
			while (sales < 0)   
			{
				cout << "Sales amount must be zero or greater.\n";
				cout << "Sales amount for month  " 
					 << quarter << "? ";
				cin  >> sales;
			}
			salesArray[(yearNumber-1)*4+quarter-1] = sales; //yearNumber -1 gets 0 based yearNum, multiply to get quarters in previous years. add current quarters to get where it needs to be.
         	// Get the total sales from funtion
			totalSales = caltotalSales(totalSales, sales);
		}	
		
	}
	
	
	// Calculate the total number of quarters.
	totalQuarters = years * 4;
   
	// Get the average from average function
   average = calAverage(totalSales, totalQuarters);
	// Calculate the average sales amount.


	// Display the total sales amount for the period.
		cout << fixed << showpoint << setprecision(2);
		cout << "\nOver a period of " << totalQuarters 
		 << " quarters, " << totalSales <<endl;
   
	// Display the average sales for the period.
	cout << fixed << showpoint << setprecision(2);
	cout << "Average quarterly sales for the period is " << average << endl;
	
	return 0;
}
	
//********************************************************
// The caltotalSales function calculates the total sales   *
// for a given years.                                   *
// ********************************************************

double caltotalSales(double totalSales, double sale)
{
	// Accumulate the sales amount.
	return totalSales += sale;  	
}	
   
//********************************************************
// The average function calculates the average sales   *
// for a given years.                                   *
// ********************************************************   
   	
double calAverage(double totalSales, int quarters)
{
	   
	   return totalSales / quarters;
}
	

