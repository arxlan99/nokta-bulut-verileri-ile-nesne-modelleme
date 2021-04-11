#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "PointCloud.h"
#include <Eigen/Dense>


/**
* @author Ismail Kilic ismail000728@gmail.com
* @date  : 30 Aralik 2019 Pazartesi
* @brief : Trans
* ve angle degerlerine gore donusum matrisini olusturur 
* daha sonrasinda doTrans fonksiyonu ile alinan nokta ya da nokta bulutunu bu donusume tabi tutarak nokta bulutunu dondurur.
*/

class Transform
{
	Eigen::Vector3d angles;
	Eigen::Vector3d trans;
	Eigen::Matrix4d transMatrix;
public:

	list<Point> doTransForm(list<Point>points);
	PointCloud doTransform(PointCloud);
	void setRotation(Eigen::Vector3d ang);
	void setTranslation(Eigen::Vector3d tr);
};

#endif // !TRANSFORM_H