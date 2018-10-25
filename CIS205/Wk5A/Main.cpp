/*
	Week 5 Assignment
	Intro to C++
	Craigory Coppola
*/
#include <iostream>
#include <iomanip>

using namespace std;

const double BALL_PRICE = 10.00; //Base Price for each ball
//Declare Discounts
const double RED_DISCOUNT_10 = .2; 
const double RED_DISCOUNT_20 = .3;
const double RED_DISCOUNT_50 = .4;
const double RED_DISCOUNT_100 = .5;
const double BLUE_DISCOUNT_10 = .25;
const double BLUE_DISCOUNT_20 = .35;
const double BLUE_DISCOUNT_50 = .45;
const double BLUE_DISCOUNT_100 = .55;


int ballChoice; //Declare variable for ball choice
int ballNum; //Declare variable for number of balls
double totalPrice; //Declare variable for price of order
double discount; //Storage for discount amount

int main(){
	//Loop to ensure proper ball selection
	while(true){
		cout << "Would you like to buy (1)Red or (2)Blue balls?\nEnter the number of your selection: ";
		int input; //Declare container for input
		try
		{
			cin >> input; //Attempt to get value from user
			if(input <= 0 || input > 2 )
			{
				throw(1); //Value invalid
			}
			else
			{
				ballChoice = input;
				break; //Exit infinite loop
			}
		}
		catch (int e) //Catch errors from input
		{
			if(e == 1){
				cout << "You must enter either 1 or 2.\n";
			}
			cout << "Please enter a correct menu choice: "; 
		}
	}
	
	// Loop to ensure proper number of balls is given
	while(true){
		cout << "How many balls would you like to buy?\n";
		int input; //Declare container for input
		try
		{
			cin >> input; //Attempt to get value from user
			if(input <= 0 ) // At least one ball must be purchased.
			{
				throw(1); //Value invalid
			}
			else
			{
				ballNum = input;
				break; //Exit infinite loop
			}
		}
		catch (int e) //Catch errors from input
		{
			if(e == 1){
				cout << "You must purchase at least one ball.\n";
			}
			cout << "Please enter a correct choice: "; 
		}
	}
	
	switch(ballChoice){ //Choose path based on which ball was choosen;
		case 1: //Red Ball
			{
				if(ballNum >= 100){
					discount = BALL_PRICE*RED_DISCOUNT_100;
				}else if(ballNum >= 50){
					discount = BALL_PRICE*RED_DISCOUNT_50;
				}else if(ballNum >= 20){
					discount = BALL_PRICE*RED_DISCOUNT_20;
				}else if(ballNum >= 10){
					discount = BALL_PRICE*RED_DISCOUNT_10;
				}else{
					//THIS SHOULD NEVER RUN!
				}
			}break;
		case 2:	//Blue Ball
			{	
				if(ballNum >= 100){
					discount = BALL_PRICE*BLUE_DISCOUNT_100;
				}else if(ballNum >= 50){
					discount = BALL_PRICE*BLUE_DISCOUNT_50;
				}else if(ballNum >= 20){
					discount = BALL_PRICE*BLUE_DISCOUNT_20;
				}else if(ballNum >= 10){
					discount = BALL_PRICE*BLUE_DISCOUNT_10;
				}else{
					//THIS SHOULD NEVER RUN!
				}
			}break;
		default:
			{
				//THIS SHOULD NEVER RUN!
			}break;
	}
	discount *= ballNum;
	totalPrice = BALL_PRICE*ballNum - discount;
	

	cout << left << setw(20) << "\nAmount Ordered:" << right << setw(5) << ballNum << " balls" <<endl;
	cout << fixed<<setprecision(2); //Set up decimal Points
	cout << left << setw(20) << "Discount Recieved:" << "$" << right << setw(10) << discount<<endl;
	cout << left << setw(20) << "Total Price:" << "$" << right << setw(10) << totalPrice<<endl;
	
	system("pause"); //Force window to not close instantly
	
}
