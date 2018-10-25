#include "student.h"
#include <string>

using namespace std;

student::student()
{
	score = 0;
	name = "";
}

student::student(string s, int n) {
	setName(s);
	setScore(n);
}


student::~student()
{
}


int student::getScore()
{
	return score;
}


string student::getName()
{
	return name;
}


void student::setScore(int s)
{
	score = s;
}


void student::setName(string n)
{
	name = n;
}
