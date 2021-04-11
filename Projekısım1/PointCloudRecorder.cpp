#include "PointCloudRecorder.h"

PointCloudRecorder::PointCloudRecorder(string name)
{
	/**
	* @brief : Dosya ismini name degiskenine atar.
	* @param name: Dosya ismidir.
	*/
	fileName = name;
}

bool PointCloudRecorder::save( PointCloud &p)
{
	/**
	* @brief : Olusturulan nokta bulutunu dosyaya kaydeder.
	* @param &p: Nokta bulutudur.
	* @return : True veya false dondurur.
	*/
	ofstream file(fileName);
	
	if (!file.is_open())
		return false;

	Point* po;
	po = p.getPoints();

	for (int i = 0; i < p.getPointNumber(); i++)
	{
		file << po[i].getX() << " " << po[i].getY() << " " << po[i].getZ() << endl;
	}
	file.close();
	return true;
}
