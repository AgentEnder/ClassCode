////////////////////////
////Craigory Coppola////
//////Pg 57, 2 & 3//////
////////////////////////
#include<iostream>;
#include <string>;
#include <vector>;

using namespace std;

class dayType {
	private:
		int currentDay = 0;
		static vector<string> days;
	public:
		dayType(int);
		void setDay(int);
		string getDay() const;
		void printDay() const;
		string getNextDay() const;
		string getPreviousDay() const;
		string getFutureDay(int x) const;
};

vector<string> dayType::days = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };

dayType::dayType(int x) {
	setDay(x); //% loops to not exceed array bounds
}

void dayType::setDay(int x) {
	int a = (x - 1) % 7;
	a = (a < 0 ? a + 7 : a);
	currentDay = a; //% loops to not exceed array bounds
}

string dayType::getDay() const {
	return days[currentDay];
}

void dayType::printDay() const {
	cout << "The current day is " << getDay() << "." << endl;
}
string dayType::getNextDay() const {
	return getFutureDay(1); //% loops to not exceed array bounds
}
string dayType::getPreviousDay() const {
	return getFutureDay(-1); //% loops to not exceed array bounds
}
string dayType::getFutureDay(int x)const {
	int a = (currentDay + x) % 7;
	a = (a < 0 ? a + 7 : a);
	return days[a]; //% loops to not exceed array bounds
}



int main() {
	dayType day(1);

	cout << "Current day variable set to 1 by constructor" << endl;
	cout << "Current day is:" << day.getDay() << "." << endl;
	cout << "The next day would be:" << day.getNextDay() << "." << endl;
	cout << "Yesterday was: " << day.getPreviousDay() << "." << endl;
	cout << "Set current day to 4, or Wednesday";
	day.setDay(4);
	cout << "Current day is: " << day.getDay() << endl;
	cout << "Adding 13 to the day count results in: " << day.getFutureDay(13) << endl; //should be tuesday
	cout << "Subtracting 5 days results in:" << day.getFutureDay(-5); //should be friday?

	getchar();
	return(0);
}