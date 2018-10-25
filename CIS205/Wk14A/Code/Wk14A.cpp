/*
	Week 14/15 Programming Assignment
	Craigory Coppola
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Function Prototypes
void waitForUserInput();
void clearConsole();

//Class Definitions

class Person{
	private:			//Actual Data Vars
		string name;
		string address;
		int age;
		string phoneNumber;
	public:
		//Set Functions
		void setName(string n){
			name = n;
		}
		void setAddress(string a){
			address = a;
		}
		void setAge(int a){
			age = a;
		}
		void setPhoneNumber(string p){
			phoneNumber = p;
		}
		//Get Functions
		string getName() const{
			return name;
		}
		string getAddress() const{
			return address;
		}
		int getAge() const{
			return age;
		}
		string getPhoneNumer() const{
			return phoneNumber;
		}
		//Constructor
		Person(string _name, string _address, int _age, string _phoneNumber){
			name = _name;
			address = _address;
			age = _age;
			phoneNumber = _phoneNumber;
		}
};

//Main F(x)
int main(){
	Person loremIpsum = Person("Lorem Ipsum", "Dolor sit amet rd", 1, "859-583-6625");
	Person randomName = Person("Dave Ipsum", "Dolor rash amet lane", 2, "859-583-6125");
	Person randomName2 = Person("Lora Inum", "Dolor sit amet street", 3, "859-583-6622");
	vector<Person> vPeople; //Vector to hold 3 people
	vPeople.push_back(loremIpsum); //Add person 1
	vPeople.push_back(randomName); //Add person 2
	vPeople.push_back(randomName2); //Add person 3
	
	for(int i = 0; i < vPeople.size(); i++){
		cout << vPeople[i].getName();
		cout << ":\n-Address:" << vPeople[i].getAddress();
		cout << "\n-Age:" << vPeople[i].getAge();
		cout << "\n-PhoneNumber:" << vPeople[i].getPhoneNumer() << "\n----------------------"<< endl;
	}
	waitForUserInput();
}

void waitForUserInput(){
	system("PAUSE"); //Abstracted function for readability in code and easy refactoring.
}

void clearConsole(){
	system("cls"); //Abstracted function for readability in code and system dependance.
}
