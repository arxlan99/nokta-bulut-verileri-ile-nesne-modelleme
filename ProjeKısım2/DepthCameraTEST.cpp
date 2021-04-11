#include "DepthCamera.h"
#include "Transform.h"
#include "RadiusOutlierFilter.h"
#include <iostream>
using namespace std;

int main()
{
	DepthCamera cam1("camera1.txt");

	Eigen::Vector3d ang1;
	Eigen::Vector3d tr1;
	ang1(0) = 0, ang1(1) = 0, ang1(2) = -90;
	tr1(0) = 100, tr1(1) = 500, tr1(2) = 50;

	FilterPipe fp;
	fp.addFilter(new RadiusOutlierFilter(25));
	cam1.setFilterPipe(&fp);

	Transform t1;
	t1.setRotation(ang1);
	t1.setTranslation(tr1);

	cam1.setTransformRotation(ang1);
	cam1.setTransformTranslation(tr1);

	PointCloud pc;
	pc = cam1.captureFor();

	auto points = pc.getPoints();
	auto iter = points.begin();

	for (iter; iter != points.end(); iter++)
	{
		cout << (*iter).getX() << " " << (*iter).getY() << " " << (*iter).getZ() << endl;
	}


	system("pause");
}
