#include "PointCloud.h"
#include <iostream>
using namespace std;

/* @brief :  Sahip olduðu noktalari, dinamik olarak yaratilan bir Point dizisinde tutar.
*/

PointCloud::PointCloud(int size )
{
	/**
	* @brief : Dinamik olarak point dizisi olustrur. 
	* @param size : Nokta bulutunda ki nokta sayisidir.
	* @see main() : fonksiyonun hangi amacla cagrildigini inceleyiniz.
	*/
	points = new Point[size];
	pointNumber = size;
}

Point* PointCloud::getPoints()
{
	/**
	* @brief :  Point dizisini dondurur.
	* @see main() : fonksiyonun hangi amacla cagrildigini inceleyiniz.
	* @return : Nokta bulutunu dondurur.
	*/
	return points;
}

void PointCloud::setPoints(Point *p)
{
	/**
	* @brief :  Bir nokta bulutundaki degerleri diger nokta bulutuna aktarir.
	* @param *p : Esitlenecek noktalardir.
	*/
	for (int i = 0; i < pointNumber; i++)
	{
		points[i] = p[i];
	}
}

PointCloud* PointCloud::operator+(PointCloud& p)
{
	/**
	* @brief :  Iki nokta bulutunu toplayip tek bir nokta bulutu haline getirir.
	* @param &p : Nokta bulutudur.
	* @return : Toplanan nokta bulut degerlerini dondurur.
	*/
	int x = this->getPointNumber() + p.getPointNumber();
	int y = p.getPointNumber();

	Point* pp = new Point[x];

	Point* p1, * p2;
	p1 = this->getPoints();
	p2 = p.getPoints();

	for (int i = 0; i < y; i++)
	{
		pp[i].setX(p1[i].getX());
		pp[i].setY(p1[i].getY());
		pp[i].setZ(p1[i].getZ());

		pp[y + i].setX(p2[i].getX());
		pp[y + i].setY(p2[i].getY());
		pp[y + i].setZ(p2[i].getZ());
	}
	

	PointCloud *pc = new PointCloud(x);
	pc->setPoints(pp);

	return pc;
}


