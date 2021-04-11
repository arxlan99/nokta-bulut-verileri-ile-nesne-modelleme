#include <iostream>
#include "DepthCamera.h"
#include "PassThroughFilter.h"
using namespace std;

int main() {
	DepthCamera camera1("camera1.txt");


	int size1 = camera1.getFileSize();

	PointCloud *pc1 = new PointCloud(size1);

	pc1 = camera1.capture();

	cout << "Filterdan once point sayisi: " << pc1->getPointNumber() <<endl;

	PassThroughFilter ptf(0, 400, 0, 400, -45, 45);
	ptf.filter(*pc1);

	cout << "Filterdan sonra point sayisi: " << pc1->getPointNumber() <<endl;


	
	system("pause");
	return 0;
}
