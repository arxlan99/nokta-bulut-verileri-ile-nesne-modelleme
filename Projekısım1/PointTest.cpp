#include <iostream>
#include "Point.h"
using namespace std;

int main()
{
	Point p;

	p.setX(5);
	p.setY(7);
	p.setZ(3);

	cout << p.getX() << endl;
	cout << p.getY() << endl;
	cout << p.getZ() << endl;


	system("pause");
}