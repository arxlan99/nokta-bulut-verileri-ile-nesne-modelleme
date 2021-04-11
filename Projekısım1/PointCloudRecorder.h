#ifndef POINT_CLOUD_RECORDER_H
#define POINT_CLOUD_RECORDER_H

#include <string>
#include "PointCloud.h"
#include <fstream>

using namespace std;

/**
* @author Ismail Kilic ismail000728@gmail.com
* @date :6 Aralik 2019 Cuma
* @brief : Bu nokta bulutlarinin dosyaya kaydedilmesi icin kullanilmaktadir. save
* fonksiyonu cagrildiginda, fileName ile ismi verilen dosya acilir, parametre olarak verilen nokta bulutundaki
* noktalar bu dosyaya kaydedilir
*/

class PointCloudRecorder
{
	string fileName;
public:
	PointCloudRecorder(string);
	bool save( PointCloud&);
};

#endif // !POINT_CLOUD_RECORDER_H

