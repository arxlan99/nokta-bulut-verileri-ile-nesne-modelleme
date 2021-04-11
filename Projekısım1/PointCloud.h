#ifndef POINT_CLOUD_H
#define POINT_CLOUD_H
#include "Point.h"

/**
* @author Ahmet Telceken ahmettlckn1@gmail.com
* @date :6 Aralik 2019 Cuma
* @brief : Sahip oldugu noktalari, dinamik olarak yaratilan bir Point dizisinde tutar. Dizinin
* boyutu, nesne yaratilirken constructor fonksiyonunda bir parametre olarak alinir.
*/

class PointCloud
{
	Point *points;
	int pointNumber;
public:
	PointCloud(int);
	Point* getPoints();
	void setPoints(Point*);
	void decrementPointNumber() { --pointNumber; }
	int getPointNumber(){ return pointNumber;}
	PointCloud* operator+(PointCloud&);
};

#endif