#include <iostream>
#include "DepthCamera.h"
#include <fstream>
using namespace std;

int main()
{
	DepthCamera dc("camera1.txt");
	int size = dc.getFileSize();

	PointCloud *pc = new PointCloud(size);

	pc = dc.capture();

	Point *p = new Point[886];

	p = pc->getPoints();

	for (int i = 0; i < size; i++)
	{
		cout << p[i].getX() << "  " << p[i].getY() << "  " << p[i].getZ() << endl;
	}

	system("pause");
}