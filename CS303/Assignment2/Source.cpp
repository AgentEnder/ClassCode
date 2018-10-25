//Main File: Craigory Coppola
#include<iostream>
#include "pointType.h"
#include "circleType.h"

using namespace std;

int main() {
	pointType myPoint(3, 4);
	circleType myCircle(2, 3, 2);

	cout << "Circle Center: " <<myCircle.getCenter() << endl;
	cout << "Point Print f(x):" << endl;
	myPoint.printPoint();

	cout << "Circle Circumference:" << myCircle.getCircumference() << endl;
	cout << "Circle Area:" << myCircle.getArea() << endl;
	cout << "Circle Raidus:" << myCircle.getRadius() << endl;

	getchar();
	return 0;
}