#ifndef POINT_CLOUD_RECORDER_H
#define POINT_CLOUD_RECORDER_H

#include <string>
#include "PointCloud.h"
#include <fstream>
#include <iostream>

using namespace std;

/**
* @author Ismail Kilic ismail000728@gmail.com
* @date : 30 Aralik 2019 Pazartesi
* @brief : Bu nokta bulutlarinin dosyaya kaydedilmesi icin kullanilmaktadir. save
* fonksiyonu cagrildiginda, fileName ile ismi verilen dosya acilir, parametre olarak verilen nokta bulutundaki
* noktalar bu dosyaya kaydedilir
*/

class PointCloudRecorder
{
	string fileName;
public:
	PointCloudRecorder(string);
	bool save(const PointCloud&);
	
};

#endif // !POINT_CLOUD_RECORDER_H

