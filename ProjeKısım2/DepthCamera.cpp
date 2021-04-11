#include "DepthCamera.h"
#include <iostream>
#include <iterator>

DepthCamera::DepthCamera(string name)
{
	/**
	* @brief : Alinan dosya ismini degiskene atar ve dosyadaki nokta sayisini bulur.
	* @param name: Dosya ismidir.
	*/

	fileName = name;
}

PointCloud DepthCamera::capture()
{
	/**
	* @brief : Dosyadan okuma yapar.
	* @return : Nokta bulutunu dondurur.
	*/
	ifstream file(fileName);

	PointCloud pCloud;
	list<Point>points;

	Point p;
	for (int i = 0; !file.eof(); i++)
	{
		double x, y, z;
		file >> x >> y >> z;

		p.setX(x);
		p.setY(y);
		p.setZ(z);
		points.push_back(p);
	}
	file.close();

	pCloud.setPoints(points);
	return pCloud;
}

PointCloud DepthCamera::captureFor()
{	/**
	* @brief : Dosyadan okuma yapar. Okudugu nokta bulutunu filtrelerden gecirir. Donusum islemi yapar.
	* @return : Nokta bulutunu dondurur.
	*/
	PointCloud pc = capture();

	for (int i = 0; i < filterPipe->getFilterNums(); i++)
	{
		filterPipe->filterOut(pc);
	}

	pc = transform.doTransform(pc);

	return pc;
}

void DepthCamera::setTransformRotation(Eigen::Vector3d ang)
{
		/**
	* @brief : Dosyadan okuma yapar.
	* @param ang: Transform islemi icin angles degeridir.
	*/
	transform.setRotation(ang);
}

void DepthCamera::setTransformTranslation(Eigen::Vector3d tr)
{
		/**
	* @brief : Dosyadan okuma yapar.
	* @param tr: Transform islemi icin trans degeridir.
	*/
	transform.setTranslation(tr);
}


