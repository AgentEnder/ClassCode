/*
	Week 13 Programming Assignment
	Craigory Coppola
*/

#include <iostream>
#include <string>

using namespace std;

//Function Prototypes
void waitForUserInput();
void clearConsole();

//Define Struct to Hold Customer Info
struct Customer{
	string name;
	string address;
	string city;
	string state;
	string zipCode;
	string phoneNumber;
	double accountBalance;
	string dateLastPayed;
};

Customer customers[10] = {};

int main(){
	enum MenuStates {MAINMENU,INPUTCUSTOMERS, VIEWCUSTOMERS, EDITCUSTOMER}; //All possible menu states
	MenuStates m = MAINMENU;
	bool programRunning = true;
	while(programRunning){ //Loop through the menu system
		switch(m){ //Skip to the selected menu
			/*
				MAIN MENU
			*/
			case MAINMENU:{
				clearConsole();
				cout << "Would you like to:" << endl; //Display Menu Options
				cout << "(1)Input customer data," << endl;
				cout << "(2)View customer data," << endl;
				cout << "(3)Edit customer data," << endl;
				cout << "(4)Exit the program\n" << endl;
				
				int userChoice;
				cin >> userChoice;
				if(userChoice == 4){
					clearConsole();
					programRunning = false; //Exit the Infinite Loop
				}else if (userChoice == 1 ||userChoice == 2 || userChoice ==3){
					m = static_cast<MenuStates>(userChoice); //Set menu state to user choice
				}
				
				break;
			}
			/*
				INPUTCUSTOMERS MENU
			*/
			case INPUTCUSTOMERS:{
				clearConsole(); //Refresh Menu
				int userChoice; //Holds user choice
				
				//Display Menu
				cout << "Which customer would you like to input data for?" <<endl;
				cout << "Choose from 1-10, or enter 0 to return to the main menu" << endl;;
				cin >> userChoice;
				if(userChoice==0){
					m = MAINMENU;
				}else if(userChoice > 0 && userChoice <=10){
					clearConsole();
					//INPUT ALL CUSTOMER DATA FOR CHOOSEN CUSTOMER
					cin.ignore();
					cout << "Enter customer name: " << endl;
					getline(cin, customers[userChoice-1].name);
					cout << "Enter customer address: "<< endl;
					getline(cin, customers[userChoice-1].address);
					cout << "Enter customer's city: "<< endl;
					getline(cin, customers[userChoice-1].city);
					cout << "Enter customer's state: "<< endl;
					getline(cin, customers[userChoice-1].state);
					cout << "Enter customer zipCode: "<< endl;
					getline(cin, customers[userChoice-1].zipCode);
					cout << "Enter customer phone number: "<< endl;
					getline(cin, customers[userChoice-1].phoneNumber);
					cout << "Enter customer accountBalance: "<< endl;
					cin>>customers[userChoice-1].accountBalance;
					cin.ignore();
					cout << "Enter the last date payed by the customer: "<< endl;
					getline(cin, customers[userChoice-1].dateLastPayed);
					
					//ALL Data is Entered
					cout<<"\n\n The customer has been entered. \n";
					waitForUserInput();
				}
				break;
			}
			/*
				VIEWCUSTOMERS MENU
			*/
			case VIEWCUSTOMERS:{
				clearConsole();
				cout << "Press enter to move to the next customer" << endl;
				waitForUserInput();
				for(int i = 1; i <= 10; i++){ //Loop through each customer in array and display all members
					clearConsole();
					cout << "Customer #" << i << endl;
					cout << "name: " << customers[i-1].name << endl;
					cout << "address: "<< customers[i-1].address <<endl;
					cout << "city: "<< customers[i-1].city<< endl;
					cout << "state: "<< customers[i-1].state<< endl;
					cout << "zipCode: "<< customers[i-1].zipCode<< endl;
					cout << "phone number: "<< customers[i-1].phoneNumber<< endl;
					cout << "accountBalance: "<< customers[i-1].accountBalance << endl;

					cout << "last date payed: "<< customers[i-1].dateLastPayed<< endl;
					waitForUserInput();
				}
				m = MAINMENU; //Return to main menu
				break;
			}
			/*
				EDITCUSTOMER MENU
			*/
			case EDITCUSTOMER:{
				cout << "You choose Edit customers" << endl;
				cout << "We were told not to implement this menu." << endl;
				waitForUserInput();
				m = MAINMENU;
				break;
			}
			default:{
				break;
			}
		}
	}
	waitForUserInput();
}

void waitForUserInput(){
	system("PAUSE"); //Abstracted function for readability in code and easy refactoring.
}

void clearConsole(){
	system("cls"); //Abstracted function for readability in code and system dependance.
}
