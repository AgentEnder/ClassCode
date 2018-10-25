/*
	Week 4 Programming Assignment
	Craigory Coppola
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	const double ASSESSMENT_RATE = 0.8; //Assign assessment rate
	const double FEDERAL_TAX = 0.005; //Assign Federal Tax rate
	const double STATE_MIN = .001; //Assign Minimum state tax
	const double STATE_MAX = .005; //Assign maximum state tax
	
	////////////////////////
	////Get Actual Value////
	////////////////////////
	
	cout << "Enter the actual value of the property: ";
	double actualValue; //Declare variable to hold actual value
	while(true){
		try
		{
			cin >> actualValue; //Attempt to get property value from user
			if(actualValue < 0)
			{
				throw(1); //Value too low, Property value can not be negative_sign
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
				cout << "A property cannot have negative value\n"; //catch thrown error
			}
			cout << "Please enter a correct property value: "; 
		}
	}
	
	//////////////////////
	////Get State Tax ////
	//////////////////////
	
	cout << "Enter the state property tax rate (between 0.1% and 0.5%): ";
	double stateTaxRate; //Declare variable to hold state tax
	while(true){
		try
		{
			cin >> stateTaxRate; //Attempt to get tax from user
			if(stateTaxRate < STATE_MIN || stateTaxRate > STATE_MAX)
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
				cout << "State Tax must be between 0.001 and 0.005\n"; //catch thrown error
			}
			cout << "Please enter a correct state tax value: "; 
		}
	}
	
	//////////////////////
	///////Do Math ///////
	//////////////////////
	
	double assessmentValue = ASSESSMENT_RATE*actualValue;
	double propertyTax = assessmentValue*stateTaxRate + assessmentValue*FEDERAL_TAX;
	
	//////////////////////
	///Display Results////
	//////////////////////
	cout << setprecision(3) << fixed <<endl; //Set up decimal points
	cout << left << setw(20) << "Actual Value: " << "$" << right << setw(10) << actualValue << endl; //setw(20) aligns first part, numbers are right aligned and decimals match.
	cout << left << setw(20) << "Assessment Value: "  << "$" << right << setw(10) << assessmentValue << endl; //setw(20) aligns first part, numbers are right aligned and decimals match.
	cout << left << setw(20) << "Federal Tax Rate: " << right << setw(11) << FEDERAL_TAX << endl; //setw(20) aligns first part, numbers are right aligned and decimals match.
	cout << left << setw(20) << "State Tax Rate: " << right << setw(11) << stateTaxRate << endl; //setw(20) aligns first part, numbers are right aligned and decimals match.
	cout << left << setw(20) << "Property Tax: " <<  "$" << right << setw(10) << propertyTax << endl; //setw(20) aligns first part, numbers are right aligned and decimals match.
	cout << endl;
	
	system("pause");
	
}
