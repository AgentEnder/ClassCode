#pragma once
#define _USE_MATH_DEFINES
#include "pointType.h"
#include <string>
#include <cmath>

using namespace std;

class circleType :
	public pointType
{
private:
	double radius;
public:
	circleType();
	circleType(double, double, double);

	void setCenter(double, double);
	void setRadius(double r);

	string getCenter() const;
	double getRadius() const;
	double getArea() const;
	double getCircumference() const;

	~circleType();
};

