#include <iostream>
#include "Transform.h"
#include "DepthCamera.h"
#include "RadiusOutlierFilter.h"
#include <cmath>
#include "PassThroughFilter.h"
#include "PointCloudRecorder.h"
using namespace std;

int main()
{
	//dosya okuma islemleri
	DepthCamera camera1("camera1.txt");
	DepthCamera camera2("camera2.txt");
	

	//dosyalarin baslangic boyutlarini bulma
	int size1 = camera1.getFileSize();
	int size2 = camera2.getFileSize();

	PointCloud *pc1 = new PointCloud(size1);
	PointCloud *pc2 = new PointCloud(size2);


	//noktalari point cloud a aktarma
	pc1 = camera1.capture();
	pc2 = camera2.capture();

	//RadiusOutlierFilter suzgeci
	RadiusOutlierFilter rof(25);
	rof.filter(*pc1);
	rof.filter(*pc2);

	//PassThroughFilter suzgeci
	PassThroughFilter ptf1(0, 400, 0, 400, -45, 45);
	ptf1.filter(*pc1);
	PassThroughFilter ptf2(0, 500, 0, 500, -45, 45);
	ptf2.filter(*pc2);

	//Transform islemi
	Transform transform1, transform2;

	double ang1[3] = { 0,0,-90}, ang2[3] = { 0,0,90 };
	transform1.setAngles(ang1);
	transform2.setAngles(ang2);

	double tr1[3] = { 100,500,50 }, tr2[3] = { 550,50,50 };
	transform1.setTrans(tr1);
	transform2.setTrans(tr2);

	*pc1 = transform1.doTransform(pc1);
	*pc2 = transform2.doTransform(pc2);


	//Iki nokta bulutunu toplayip tek nokta bulutu elde etme
	PointCloud* po = new PointCloud(pc1->getPointNumber() + pc2->getPointNumber());
	po = *pc1 + *pc2;

	//noktalari yazdirma
	PointCloudRecorder record("output.txt");
	record.save(*po);

	
	


	system("pause");
}