#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "PointCloud.h"

/**
* @author Ismail Kilic ismail000728@gmail.com
* @date :6 Aralik 2019 Cuma
* @brief : Trans
* ve angle degerlerine gore donusum matrisini olusturur 
* daha sonrasinda doTrans fonksiyonu ile alinan nokta ya da nokta bulutunu bu donusume tabi tutarak nokta bulutunu dondurur.
*/

class Transform
{
	double angles[3];
	double trans[3];
	double transMatrix[4][4];
public:
	Transform();
	void setAngles(double []);
	void setTrans(double[]);
	void setRotation(double[]);
	void setTranslation(double[]);
	Point* doTransForm(Point*,int);
	PointCloud doTransform(PointCloud*);
};

#endif // !TRANSFORM_H