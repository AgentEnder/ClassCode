/*
	Exam 1: Programming Portion
	Craigory Coppola
*/
#include <iostream>
#include <iomanip>

using namespace std;

const double SINGLE_10PERCENT_MAX = 30000; //Declare maximum income to be taxed at 10 percent
const double SINGLE_20PERCENT_MAX = 80000; //Declare maximum income to be taxed at 20 percent

const double MARRIED_10PERCENT_MAX = 50000; //Declare maximum income to be taxed at 10 percent
const double MARRIED_20PERCENT_MAX = 100000; //Declare maximum income to be taxed at 20 percent

/*NOTE(craigory): Since their is only one rate above 20%, 
				  it does not need to be declared. If any income is above 20%
				  it is automatically 35%.
*/

int main()
{
	/*
		Get Input
	*/
	bool isSingle; //if true single, else married;
	cout << "Tax filing status \n\n";
	cout << "1.single\n2.married\n\n";
	cout << "Enter your choice: ";
	int filingStatusNumber;
	cin >> filingStatusNumber; //Get filing status
	switch(filingStatusNumber){
		case 1:
		{
			isSingle = true; //Tax filing status is single
		}break;
		case 2:
		{
			isSingle = false; //Tax filing status is married
		}break;
		default:
		{
			cout << "Error: invalid status \n\nEnter 1 or 2" <<endl;
			system("pause"); //Wait for user input to ensure that message is seen
			return(0); //Exit the program on error;
		}break;
	}
	cout << "Enter your taxable income: ";
	double taxableIncome;
	cin >> taxableIncome; //Get taxable amt from user
	double taxAmount = 0; // Initalize a variable to hold tax amount
	
	/*
		Process Data
	*/
	
	if(isSingle) //Use Single Tax Rates
	{
		if(taxableIncome > SINGLE_10PERCENT_MAX)
		{
			if(taxableIncome > SINGLE_20PERCENT_MAX)
			{
				double income35p = taxableIncome - SINGLE_20PERCENT_MAX; //Amount to be taxed at 35%
				taxAmount+= income35p*0.35; //Tax any income over the 20% max at 35%
				taxAmount+= (SINGLE_20PERCENT_MAX-SINGLE_10PERCENT_MAX)*0.2; //Tax full range at 20%
			}else
			{
				double income20p = taxableIncome - SINGLE_10PERCENT_MAX; //Amount to tax at 20%
				taxAmount += income20p * 0.2; //Tax income over 10%max at 20%
			}
			taxAmount += SINGLE_10PERCENT_MAX*0.1; //Tax the max at 10%
		}else{
			taxAmount+=taxableIncome*0.1; //All income is under the 10% max
		}
	}else //Use Married Tax Rates
	{
		if(taxableIncome > MARRIED_10PERCENT_MAX)
		{
			if(taxableIncome > MARRIED_20PERCENT_MAX)
			{
				double income35p = taxableIncome - MARRIED_20PERCENT_MAX; //Amount to be taxed at 35%
				taxAmount+= income35p*0.35; //Tax any income over the 20% max at 35%
				taxAmount+= (MARRIED_20PERCENT_MAX-MARRIED_10PERCENT_MAX)*0.2; //Tax full range at 20%
			}else
			{
				double income20p = taxableIncome - MARRIED_10PERCENT_MAX; //Amount to tax at 20%
				taxAmount += income20p * 0.2; //Tax income over 10%max at 20%
			}
			taxAmount += MARRIED_10PERCENT_MAX*0.1; //Tax the max at 10%
		}else{
			taxAmount+=taxableIncome*0.1; //All income is under the 10% max
		}
	}
	
	/*
		Display Results
	*/
	cout << setw(15) <<left<<"\nFiling Status:\t" << filingStatusNumber <<endl;
	cout << setprecision(2) << fixed;
	cout << setw(15) <<left<< "Taxable Amount:" << right << setw(10) << taxableIncome << left <<endl;
	cout << setw(15) << "Tax Amount:" << right << setw(10) << taxAmount <<endl;
	system("pause");
}