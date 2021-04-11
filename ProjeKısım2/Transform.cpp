

#include "Transform.h"
#include <cmath>
#include <iostream>





list<Point> Transform::doTransForm(list<Point>points)
{
	/**
	* @brief : Aldigi nokta bulutunu donusum matrisiyle donusume tabi tutar.
	* @param points : Nokta bulutundaki nokta degerleridir.
	* @return  : Nokta bulutu listesini dondurur.
	*/

	Eigen::Vector4d vektor_matris;
	Eigen::Vector4d result_matris;

	auto it = points.begin();

	list<Point>new_points;
	Point p;

	for (it; it!=points.end(); it++)
	{
		vektor_matris(0) = (*it).getX();
		vektor_matris(1) = (*it).getY();
		vektor_matris(2) = (*it).getZ();
		vektor_matris(3) = 1;

		result_matris = transMatrix * vektor_matris;
		
		p.setX(result_matris(0));
		p.setY(result_matris(1));
		p.setZ(result_matris(2));

		new_points.push_back(p);
	}
	return new_points;
}
PointCloud Transform::doTransform(PointCloud pc)
{
	/**
	* @brief : Nokta bulutunu donusturur.
	* @param pc : Donusturulucek nokta bulutudur.
	* @return : Nokta bulutu döndürür.
	*/
	PointCloud new_pc;

	auto points = pc.getPoints();

	list<Point>new_points;
	new_points = doTransForm(points);

	new_pc.setPoints(new_points);

	return new_pc;
}

void Transform::setRotation(Eigen::Vector3d ang)
{
	/**
	* @brief : Angles vektorune degerleri atar.
	* @param ang : Rotation degerleri
	*/

	angles(0) = ang[0];
	angles(1) = ang[1];
	angles(2) = ang[2];

	const double PI = 3.14159265358979323846;

	double gama = angles[0], beta = angles[1], alpha = angles[2];
	gama = (gama * PI / 180.0);
	beta = (beta * PI / 180.0);
	alpha = (alpha * PI / 180.0);

	transMatrix(0, 0) = round(cos(alpha))*round(cos(beta));
	transMatrix(0, 1) = (round(cos(alpha))*round(sin(beta))*round(sin(gama))) - (round(sin(alpha))*round(cos(gama)));
	transMatrix(0, 2) = (round(cos(alpha))*round(sin(beta))*round(cos(gama))) + (round(sin(alpha))*round(sin(gama)));
	transMatrix(1, 0) = (round(sin(alpha))*round(cos(beta)));
	transMatrix(1, 1) = (round(sin(alpha))*round(sin(beta))*round(sin(gama))) + (round(cos(alpha))*round(cos(gama)));
	transMatrix(1, 2) = (round(sin(alpha))*round(sin(beta))*round(cos(gama))) - (round(cos(alpha))*round(sin(gama)));
	transMatrix(2, 0) = round(-sin(beta));
	transMatrix(2, 1) = round(cos(beta))*round(sin(gama));
	transMatrix(2, 2) = round(cos(beta))*round(cos(gama));
	transMatrix(3, 0) = 0;
	transMatrix(3, 1) = 0;
	transMatrix(3, 2) = 0;


}

void Transform::setTranslation(Eigen::Vector3d tr)
{
	/**
	* @brief : Trans vektorune degerleri atar.
	* @param tr : Translation degerleri
	*/

	trans << tr[0], tr[1], tr[2];

	double X = trans[0], Y = trans[1], Z = trans[2];

	transMatrix(0, 3) = X;
	transMatrix(1, 3) = Y;
	transMatrix(2, 3) = Z;
	transMatrix(3, 3) = 1;
}
