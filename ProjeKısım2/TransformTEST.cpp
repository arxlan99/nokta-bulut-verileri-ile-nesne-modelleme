#include "Transform.h"
#include <iostream>
#include "DepthCamera.h"
using namespace std;

int main()
{
	DepthCamera cam1("camera1.txt");

	PointCloud pc = cam1.capture();
	
	Eigen::Vector3d ang1;
	Eigen::Vector3d tr1;
	ang1(0) = 0, ang1(1) = 0, ang1(2) = -90;
	tr1(0) = 100, tr1(1) = 500, tr1(2) = 50;

	Transform t1;
	t1.setRotation(ang1);
	t1.setTranslation(tr1);

	pc = t1.doTransform(pc);

	auto points = pc.getPoints();
	auto iter = points.begin();

	for (iter; iter != points.end(); iter++)
	{
		cout << (*iter).getX() << " " << (*iter).getY() << " " << (*iter).getZ() << endl;
	}

	system("pause");
}