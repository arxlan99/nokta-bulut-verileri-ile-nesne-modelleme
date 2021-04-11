#ifndef DEPTH_CAMERA_H
#define DEPTH_CAMERA_H
#include <string>
#include "PointCloud.h"
#include <fstream>
#include "PointCloudGenerator.h"
#include <vector>
#include <list>
using namespace std;

/**
* @author Ismail Kilic ismail000728@gmail.com
* @date :6 Aralik 2019 Cuma
* @brief :  Ismi verilen dosyadan, capture fonksiyonu cagrildiginda noktalari okur
*  ve yaratilan nokta bulutu nesnesine bu noktalari atar.
*/

class DepthCamera : public PointCloudGenerator
{
	string fileName;
public:
	DepthCamera(string);
	PointCloud capture() ;
	PointCloud captureFor() ;
	void setTransformRotation(Eigen::Vector3d ang);
	void setTransformTranslation(Eigen::Vector3d tr);
};

#endif // !DEPTH_CAMERA_H