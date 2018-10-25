/*
	Final Exam
	Craigory Coppola
*/
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// Function Prototype
double caltotalSales(double, double);
double calAverage(double, int);

class SalesFigures{ //Define class Sales Figure
	private: //Store Data Figs Here
		int years; //Number of years
		int quarters; //Number of Quarters
		double totalSales = 0; //Hold total $ amt
		double averageSales = 0; //Hold avg $ amt
	public:
		void collectSales(){ //Function to collect sales figures from user
			double sales; //Hold sales number
			for (int yearNumber = 1; yearNumber <= years; yearNumber++)  //Loop through each year
			{
				cout << "\nYear " << yearNumber << endl;
			  
				// Get the sales amount for each quarter.
				for (int quarter = 1; quarter <= 4; quarter++) //Loop through each quarter per year
				{  
					cout << "sales amount for quarter "
						 << setw(2) << quarter << "? ";
					cin  >> sales; //Set Sale
				 
					// Validate the sales amount.
					while (sales < 0)   
					{
						cout << "Sales amount must be zero or greater.\n";
						cout << "Sales amount for quarter  " 
							 << quarter << "? ";
						cin  >> sales; 
					}
					 
					// Get the total sales from funtion
					totalSales += sales; //Add to total sales
				}	
			} //All sales gathered
			averageSales = calAverage(totalSales, quarters); //set average
		}
		void setYears(int y){ //set years
			years = y;
			quarters = y*4; //set quarters
		}
		int getTotalQuarters()const {
			return quarters; //Return quarter number
		}
		double getTotalSales()const {
			return totalSales; //return sales
		}
		double getAverageSales() const{
			return averageSales; //return Avg sales amts
		}
		
};

int main()
{
	int years; // The number of years 
	SalesFigures sF; //Declare an instance of class SalesFigures
	// Get the number of years.
	cout << "This program will calculate average sales over a \n"
		 << "period of years.  How many years do you wish to average? ";
	cin  >> years;

	// Validate the number of years.
	while (years < 1)
	{  cout << "Years must be at least one. Please re-enter: ";
		cin  >> years;
	}
	
	sF.setYears(years); //set num years
   
	sF.collectSales(); //get sales`
	
	// Display the total sales amount for the period.
		cout << fixed << showpoint << setprecision(2);
		cout << "\nOver a period of " << sF.getTotalQuarters()
		 << " quarters, " << sF.getTotalSales() <<endl;
   
	// Display the average sales for the period.
	cout << fixed << showpoint << setprecision(2);
	cout << "Average quarterly sales for the period is " << sF.getAverageSales() << endl;

	system("pause");
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