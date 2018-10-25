#pragma once
#include <iostream>
#include<string>

using namespace std;

class pointType
{
private:
	double xCoordinate;
	double yCoordinate;
public:
	pointType();
	pointType(double, double);
	~pointType();

	void setPoint(double, double);
	void showPoint() const;
	double getX() const;
	double getY() const;
	string getCoordinates() const;
	void printPoint() const;
};

