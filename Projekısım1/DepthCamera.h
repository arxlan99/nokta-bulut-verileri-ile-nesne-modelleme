#ifndef DEPTH_CAMERA_H
#define DEPTH_CAMERA_H
#include <string>
#include "PointCloud.h"
#include <fstream>
using namespace std;

/**
* @author Ismail Kilic ismail000728@gmail.com
* @date :6 Aralik 2019 Cuma
* @brief :  Ismi verilen dosyadan, capture fonksiyonu cagrildiginda noktalari okur
*ve yaratilan nokta bulutu nesnesine bu noktalari atar.
*/

class DepthCamera
{
	string fileName;
	int file_size=0;
	void findFileSize();
public:
	DepthCamera(string);
	PointCloud* capture();
	int getFileSize() { return file_size; };
};

#endif // !DEPTH_CAMERA_H