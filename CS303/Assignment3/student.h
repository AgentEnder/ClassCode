#pragma once
#include<string>;

using namespace std;

class student
{
public:
	student();
	student(string, int);
	~student();
	string name;
	int score;
	int getScore();
	string getName();
	void setScore(int s);
	void setName(string n);
};

