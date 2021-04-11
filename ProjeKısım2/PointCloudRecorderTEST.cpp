#include "PointCloudRecorder.h"
#include "DepthCamera.h"
#include <iostream>
using namespace std;

int main()
{
	PointCloudRecorder pcr("pcr_test.txt");
	DepthCamera cam1("camera1.txt");

	PointCloud pc = cam1.capture();

	pcr.save(pc);

	system("pause");
}