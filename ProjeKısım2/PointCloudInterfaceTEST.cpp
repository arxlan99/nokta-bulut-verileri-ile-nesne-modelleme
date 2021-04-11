#include "PointCloudInterface.h"
#include "DepthCamera.h"
#include "RadiusOutlierFilter.h"
#include <iostream>
using namespace std;

int main()
{
	DepthCamera cam1("camera1.txt");
	FilterPipe fp;
	fp.addFilter(new RadiusOutlierFilter(25));
	cam1.setFilterPipe(&fp);
	PointCloudRecorder pcr("pci_test.txt");

	PointCloudInterface pci;
	pci.addGenerator(&cam1);
	pci.setRecorder(&pcr);
	pci.generate();
	pci.record();

	system("pause");
}