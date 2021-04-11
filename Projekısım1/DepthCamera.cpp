#include "DepthCamera.h"

DepthCamera::DepthCamera(string name)
{
	/**
	* @brief : Alinan dosya ismini degiskene atar ve dosyadaki nokta sayisini bulur.
	* @param name: Dosya ismidir.
	*/

	fileName = name;
	findFileSize();
}

PointCloud* DepthCamera::capture()
{
	/**
	* @brief : Dosyadan okuma yapar.
	* @return : Nokta bulutunu dondurur.
	*/
	ifstream file(fileName);
	
	PointCloud *pCloud = new PointCloud(file_size);
	Point *p = new Point[file_size];

	for (int i=0;i<file_size;i++)
	{
		double x, y, z;
		file >> x >> y >> z;
		p[i].setX(x);
		p[i].setY(y);
		p[i].setZ(z);
	}
	file.close();

	pCloud->setPoints(p);
	return pCloud;
}

void DepthCamera::findFileSize()
{
	/**
	* @brief : Dosyadaki nokta sayisini bulur.
	*/
	ifstream temp(fileName);
	string s;
	while (!temp.eof())
	{
		getline(temp, s);
		file_size++;
	}
	temp.close();
}

