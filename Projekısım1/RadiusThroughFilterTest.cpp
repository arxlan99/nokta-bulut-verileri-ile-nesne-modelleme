#include <iostream>
#include "DepthCamera.h"
#include "RadiusOutlierFilter.h"
#include <cmath>
#include "PassThroughFilter.h"
#include "PointCloudRecorder.h"
using namespace std;
const double PI = 3.14159265358979323846;

int main(){
	DepthCamera camera1("camera1.txt");
	

	int size1 = camera1.getFileSize();

	PointCloud *pc1 = new PointCloud(size1);

	pc1 = camera1.capture();

	RadiusOutlierFilter rof(25);
	rof.filter(*pc1);


	PointCloudRecorder record("rtfTest.txt");
	record.save(*pc1);

	return 0;
	
}
