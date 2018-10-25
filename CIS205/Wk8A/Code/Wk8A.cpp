/*
	Week 8 Programming Assignment
	Craigory Coppola
*/

#include <iostream>
#include <iomanip>
using namespace std;

double totalSalesGetter( int numYears){
	double sales,			// The sales for a given quarter
		   totalSales = 0, // The total sales for all quarters
		   average;         // The average quarterly sales

	// The outer loop iterates once for each year.
	for (int yearNumber = 1; yearNumber <= numYears; yearNumber++) 
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
				cout << "Sales amount for quater  " 
					 << quarter << "? ";
				cin  >> sales;
			} 
         
			// Accumulate the sales amount.
			totalSales += sales;  
		}
	}
	return totalSales;
}

double averageGetter(int years, double sales){
	// Calculate the total number of quarters.
	int totalQuarters = years * 4;
   
	// Calculate the average sales amount.
	return sales / totalQuarters;
}

int main()
{
	int years,				// The number of years 
		totalQuarters;		// The number of quarters
	double sales,			// The sales for a given quarter
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

	totalSales = totalSalesGetter(years);
	
	average = averageGetter(years, totalSales);
	
	totalQuarters = years*4;
	// Display the total sales amount for the period.
		cout << fixed << showpoint << setprecision(2);
		cout << "\nOver a period of " << totalQuarters 
		 << " quarters, " << totalSales <<endl;
   
	// Display the average sales for the period.
	cout << fixed << showpoint << setprecision(2);
	cout << "Average quarterly sales for the period is " << average << endl;

	system("pause");
	return 0;
}