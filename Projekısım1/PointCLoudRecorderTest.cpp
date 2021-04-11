#include <iostream>
#include "DepthCamera.h"
#include "PointCloudRecorder.h"
#include <fstream>
using namespace std;

int main()
{
	DepthCamera dc("camera1.txt");
	int size = dc.getFileSize();

	PointCloud *pc = new PointCloud(size);

	pc = dc.capture();

	PointCloudRecorder record("PCRTest.txt");

	record.save(*pc);

	
	system("pause");
}