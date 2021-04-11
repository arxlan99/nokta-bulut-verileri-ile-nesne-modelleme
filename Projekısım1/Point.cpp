#include "Point.h"
#include <cmath>

//Bu sýnýf nokta bulutundaki 3B noktalarýn koordinatlarýný tutar



bool Point::operator==(Point &p)
{
	/**
	* @brief : Iki noktanin esit olup olmadigini kontrol eder.
	* @param &p : Kontrol edilecek nokta degerleridir.
	* @return : True veya false dondurur.
	*/
	return (x == p.x) && (y == p.y) && (z == p.z);
}
double Point::distance(const Point& p) const
{
	/**
	* @brief : Iki nokta arasindaki uzakligi bulur.
	* @param &p : Kontrol edilecek nokta degerleridir.
	* return : Mesafeyi dondurur.
	*/
	double result = pow((p.x - x), 2) + pow((p.y - y), 2) + pow((p.z - z), 2);
	return pow(result, 0.5);
}
void Point::setX(double xi)
{
	/**
	* @brief : set/get function.
	* @param xi : Noktanin x degeri.
	*/
	this->x = xi;
}
void Point::setY(double yi)
{
	/**
	* @brief : set/get function.
	* @param yi : Noktanin y degeri.
	*/
	this->y = yi;
}
void Point::setZ(double zi)
{
	/**
	* @brief : set/get function.
	* @param zi : Noktanin z degeri.
	*/
	this->z = zi;
}
double Point::getX()
{
	/**
	* @brief : x degerini dondurmeyi saglar.
	* @return : x degerini dondurur
	*/
	return this->x;
}
double Point::getY()
{
	/**
	* @brief : y degerini dondurmeyi saglar.
	* @return : y degerini dondurur
	*/

	return this->y;
}
double Point::getZ()
{
	/**
	* @brief : z degerini dondurmeyi saglar.
	* @return : z degerini dondurur
	*/

	return this->z;
}