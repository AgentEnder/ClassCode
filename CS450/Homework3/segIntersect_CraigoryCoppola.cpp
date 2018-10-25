#include<iostream>
using namespace std;

typedef struct point {
	double x, y;
};

int segIntersect(point A, point B, point C, point D, point * interPoint) {
	// Line AB represented as a1x + b1y = c1
	double a1 = B.y - A.y;
	double b1 = A.x - B.x;
	double c1 = a1*(A.x) + b1*(A.y);

	// Line CD represented as a2x + b2y = c2
	double a2 = D.y - C.y;
	double b2 = C.x - D.x;
	double c2 = a2*(C.x) + b2*(C.y);

	double determinant = a1*b2 - a2*b1;

	if (determinant == 0)
	{
		return -1;
	}
	else
	{
		double x = (b2*c1 - b1*c2) / determinant;
		double y = (a1*c2 - a2*c1) / determinant;
		double t = (x - A.x ) / (B.x - A.x); //Determine T as a ratio of X translation
		double u = (x - C.x) / (D.x - C.x); //Determine U as a ratio of movement on X
		interPoint->x = x;
		interPoint->y = y;
		return (int(t <= 1 && t >= 0 && u >= 0 && u <= 1)); //Return 0 if not(t & u E[0,1])
	}

}

int main()
{
	point A = { 1, 1 };
	point B = { 4, 4 };
	point C = { 1, 9 };
	point D = { 2, 3 };

	point  intersection;

	int res = segIntersect(A, B, C, D, &intersection);

	if (res == -1)
	{
		cout << "Lines AB and CD are parallel." << endl;
	}
	else 
	{
		if (res == 0) {
			cout << "The intersection occurs outside of the given line segments." << endl;
		}
		cout << "The intersection of the lines AB and CD is: (" << intersection.x << "," << intersection.y << ")" << endl;
	}
	system("pause");
	return 0;
}