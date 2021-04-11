#include "PointCloudRecorder.h"

PointCloudRecorder::PointCloudRecorder(string name)
{
	/**
	* @brief : Dosya ismini name degiskenine atar.
	* @param name: Dosya ismidir.
	*/
	fileName = name;
}

bool PointCloudRecorder::save(const PointCloud &p)
{
	/**
	* @brief : Olusturulan nokta bulutunu dosyaya kaydeder.
	* @param &p: Nokta bulutudur.
	* @return : True veya false dondurur.
	*/
	ofstream file;
	file.open(fileName, ios::out);

	if (!file.is_open())
		return false;

	auto points = p.getPoints();
	

	for (auto it = points.begin(); it != points.end(); it++)
	{
		file << (*it).getX() << " " << (*it).getY() << " " << (*it).getZ() << endl;
	}
	file.close();
	return true;
}


