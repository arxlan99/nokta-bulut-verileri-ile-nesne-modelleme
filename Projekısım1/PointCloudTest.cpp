#include <iostream>
#include "PointCloud.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	PointCloud pc(3);
	Point p[3];
	Point *p2;

	srand(time(0));


	for (int i = 0; i < 3; i++)
	{
		int x, y, z;
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;
		z = rand() % 9 + 1;

		cout << x << " " << y << " " << z << " ";
		p[i].setX(x);
		p[i].setY(y);
		p[i].setZ(z);
	}

	cout << "\n-------------------------------------------\n";
	pc.setPoints(p);
	p2 = pc.getPoints();

	for (int i = 0; i < 3; i++)
	{
		cout<<p2[i].getX() << " ";
		cout << p2[i].getY() << " ";
		cout << p2[i].getZ() << " ";
	}



	system("pause");
}