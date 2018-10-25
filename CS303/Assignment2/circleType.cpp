#include "circleType.h"



circleType::circleType()
{
	pointType::setPoint(0, 0);
}

circleType::circleType(double r, double x, double y)
{
	radius = r;
	pointType::setPoint(x, y);
}

void circleType::setCenter(double x, double y)
{
	pointType::setPoint(x, y);
}

void circleType::setRadius(double r)
{
	radius = r;
}


string circleType::getCenter() const
{
	return pointType::getCoordinates();
}

double circleType::getRadius() const
{
	return radius;
}

double circleType::getArea() const
{
	return M_PI*radius*radius;
}

double circleType::getCircumference() const
{
	return 2*M_PI*radius;
}

circleType::~circleType()
{
}
