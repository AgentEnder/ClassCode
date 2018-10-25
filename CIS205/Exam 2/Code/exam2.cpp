/*
	Exam 2
	Craigory Coppola
*/

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

double getMinScore(vector<double>); //function prototype
double getMaxScore(vector<double>); //function prototype
double getAverageScore(vector<double>); //function prototype

int numStudents = 0;

int main()
{
	//Ask for number of scores, and get input
	while(numStudents < 1){ //Continue asking if invalid input/
		cout << "How many students? ";
		cin >> numStudents;
	}
	
	cout << "\nEnter " << numStudents << " scores. \n" << endl;
	
	vector<double> listScores(numStudents); //Declare a vector to hold scores. Vector instead of an array due to cpp standards not supporting variable length arrays.
	
	for(int i = 0; i < numStudents; i++){ //Get scores and place them in array
		cout << "Score " << i+1 << ": ";
		cin >> listScores[i];
	}
	
	cout << "\nThe highest score is " << getMaxScore(listScores) << endl; // 
	cout << "The lowest score is " << getMinScore(listScores) << endl;
	cout << "The average score is " << getAverageScore(listScores) << endl;
	cout << endl; //spacing
	system("PAUSE");
}

double getMinScore(vector<double> v){
	double minScore;
	for(int i = 0; i < v.size(); i++){ //Iterate through each item
		if(i==0){
			minScore = v[i];   //First item will always be the lowest at time of iteration
		}else if(v[i] < minScore){
			minScore = v[i]; //Assign minScore if score is lower than current value.
		}
	}
	return(minScore);
}

double getMaxScore(vector<double> v){
	double maxScore;
	for(int i = 0; i < v.size(); i++){ //Iterate through each item
		if(i==0){
			maxScore = v[i];   //First item will always be the highest at time of iteration
		}else if(v[i] > maxScore){
			maxScore = v[i]; //Assign minScore if score is higher than current value.
		}
	}
	return(maxScore);
}


double getAverageScore(vector<double> v){
	double totalScores;
	double averageScore;
	for(int i = 0; i < v.size(); i++){ //Iterate through each item
		totalScores += v[i];
	}
	averageScore = totalScores/v.size();
	return(averageScore);
}