#include "pointType.h"



pointType::pointType()
{
	xCoordinate = 0;
	yCoordinate = 0;
}

pointType::pointType(double x, double y)
{
	xCoordinate = x;
	yCoordinate = y;
}


pointType::~pointType()
{
}

void pointType::setPoint(double x, double y)
{
	xCoordinate = x;
	yCoordinate = y;
}

void pointType::showPoint() const
{
	//Im not sure what the book expects for showPoint, as we have not went over displaying graphics.
}

double pointType::getX() const
{
	return xCoordinate;
}

double pointType::getY() const
{
	return yCoordinate;
}

string pointType::getCoordinates() const
{
	return(to_string(xCoordinate) + "," + to_string(yCoordinate));
}

void pointType::printPoint() const
{
	std::cout << "X:" << xCoordinate << ", Y:" << yCoordinate << endl;
}
