#ifndef POINT_CLOUD_INTERFACE_H
#define POINT_CLOUD_INTERFACE_H

#include <vector>
#include "PointCloudGenerator.h"
#include "PointCloud.h"
#include "PointCloudRecorder.h"

/**
* @author Ismail Kilic ismail000728@gmail.com
* @date  : 30 Aralik 2019 Pazartesi
* @brief :  Bu sinif islemleri basitlestirmek icin kullanilan bir siniftir. Aldigi nokta bulutlarini dosyaya kaydeder.
*/

class PointCloudInterface
{
private:
	PointCloud pointCloud;
	PointCloud patch;
	PointCloudRecorder* recorder;
	vector<PointCloudGenerator*> generators;
public:
	PointCloudInterface() {}
	void addGenerator(PointCloudGenerator*);
	void setRecorder(PointCloudRecorder*);
	bool generate();
	bool record();
};

#endif // !POINT_CLOUD_INTERFACE_H