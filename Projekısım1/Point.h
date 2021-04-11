#ifndef POINT_H
#define POINT_H

/**
* @author Ahmet Telceken ahmettlckn1@gmail.com
* @date :6 Aralik 2019 Cuma
* @brief : Bu sinif nokta bulutundaki 3B noktalarin koordinatlarini tutar.
*/

class Point
{
	double x;
	double y;
	double z;
public:
	bool operator==(Point &p);
	double distance(const Point& p)const;
	void setX(double);
	void setY(double);
	void setZ(double);
	double getX();
	double getY();
	double getZ();
	

};

#endif