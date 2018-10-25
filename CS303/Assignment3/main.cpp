//CRAIGORY COPPOLA
//PROGRAMING QUESTION 2, Pg. 259
//Homework Assign. #3
//CS 303, Dr. Sani

#include <iostream>
#include <vector>
#include "student.h";

int main() {
	vector<student> vecStudents; //Container to hold students
	string name = ""; //TempName var to hold name before creating student
	int score; //TempScore var to hold score before creating student
	while (name!="done") { //Exit loop when "done" is typed
		cout << "Input a name. If finished typing names, type done." << endl;;
		getline(cin, name); //Store Name, getline allows spaces.
		if (name != "done") { //Dont run if done is typed
			cout << "What was " << name << "'s score?"; //prompt for score
			cin >> score; //Store Score
			student tempStudent(name, score); //create a student to add to the vector.
			vecStudents.push_back(tempStudent); //push student on the back of the vector.
		}
	}
	if (vecStudents.size() == 0) { //Ensure a student was entered
		cout << "No students were entered";
	}
	else {
		int sum = 0;
		int highestScore = 0;
		double average;
		for (int i = 0; i < vecStudents.size(); i++) //Go over each element in the vector
		{
			int s = vecStudents[i].getScore();
			sum += s; //Add the current students score to the sum
			if (highestScore < s) //Check if they have a higher score than the previous max score.
				highestScore = s;
		}
		average = sum / vecStudents.size(); //Calculate Average
		cout << "Student Average: " << average << endl; //Print average
		cout << "The following student/s had the highest score: " << endl;
		for (int i = 0; i < vecStudents.size(); i++) //Iterate over elements
		{
			if (vecStudents[i].getScore() == highestScore) //Print students with max score only.
				cout << vecStudents[i].getName() << " had the highest score." << endl;
		}
		cout << "The following student/s had a below average score: " << endl;
		for (int i = 0; i < vecStudents.size(); i++)
		{
			if (vecStudents[i].getScore() < average)
				cout << vecStudents[i].getName() << " had a below average score." << endl;

		}
		getchar();
	}
	return(0);
}