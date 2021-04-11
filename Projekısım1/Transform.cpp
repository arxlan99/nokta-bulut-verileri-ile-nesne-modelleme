

#include "Transform.h"
#include <cmath>


Transform::Transform()
{
}
void Transform::setAngles(double ang[])
{
	/**
	* @brief : Verilen aci degerlerini ang degiskenine uygular.
	* @param ang[] : Input olarak alinan rotasyon acilardir.
	*/
	angles[0] = ang[0];
	angles[1] = ang[1];
	angles[2] = ang[2];
	setRotation(ang);
}
void Transform::setTrans(double tr[])
{
	/**
	* @brief : Trans degerini alir.
	* @param tr[] : 2 orjin arasindaki uzaklik degeridir.
	*/
	trans[0] = tr[0];
	trans[1] = tr[1];
	trans[2] = tr[2];
	setTranslation(tr);
}
void Transform::setRotation(double ang[])
{
	/**
	* @brief : Rotasyon aci degerlerini donusum matrisine uygular. 
	* @param ang[] : Input olarak alinan rotasyon acilardir.
	*/
	const double PI = 3.14159265358979323846;

	double gama = ang[0], beta = ang[1], alpha = ang[2];
	gama = (gama * PI / 180.0);
	beta = (beta * PI / 180.0);
	alpha = (alpha * PI / 180.0);

	transMatrix[0][0] = round(cos(alpha))*round(cos(beta));
	transMatrix[0][1] = (round(cos(alpha))*round(sin(beta))*round(sin(gama))) - (round(sin(alpha))*round(cos(gama)));
	transMatrix[0][2] = (round(cos(alpha))*round(sin(beta))*round(cos(gama))) + (round(sin(alpha))*round(sin(gama)));
	transMatrix[1][0] = (round(sin(alpha))*round(cos(beta)));
	transMatrix[1][1] = (round(sin(alpha))*round(sin(beta))*round(sin(gama))) + (round(cos(alpha))*round(cos(gama)));
	transMatrix[1][2] = (round(sin(alpha))*round(sin(beta))*round(cos(gama))) - (round(cos(alpha))*round(sin(gama)));
	transMatrix[2][0] = round(-sin(beta));
	transMatrix[2][1] = round(cos(beta))*round(sin(gama));
	transMatrix[2][2] = round(cos(beta))*round(cos(gama));
	transMatrix[3][0] = 0;
	transMatrix[3][1] = 0;
	transMatrix[3][2] = 0;


}

void Transform::setTranslation(double tr[])
{
	/**
	* @brief : Rotasyon aci degerlerini trans matrisine uygular.
	* @param tr[] : 2 orjin arasindaki uzaklik degeridir.
	*/
	double X = tr[0], Y = tr[1], Z = tr[2];

	transMatrix[0][3] = X;
	transMatrix[1][3] = Y;
	transMatrix[2][3] = Z;
	transMatrix[3][3] = 1;
}

Point* Transform::doTransForm(Point *p,int x)
{
	/**
	* @brief : Aldigi nokta bulutunu donusum matrisiyle donusume tabi tutar.
	* @param *p : Nokta bulutundaki nokta degerleridir.
	* @param x : Nokta bulutundaki nokta sayisidir.
	* @return  : Nokta bulutunu dondurur.
	*/

	double vektor_matris[4];
	double result_matris[4];



	Point *pp = new Point[x];
	
	for (int i = 0; i < x; i++)
	{
		vektor_matris[0] = p[i].getX();
		vektor_matris[1] = p[i].getY();
		vektor_matris[2] = p[i].getZ();
		vektor_matris[3] = 1;

		for (int k = 0; k < 4; k++)
		{
			double carpim = 1;
			double toplam = 0;
			for (int j = 0; j < 4; j++)
			{
				carpim = transMatrix[k][j] * vektor_matris[j];
				toplam += carpim;
			}
			result_matris[k] = toplam;
		}
		pp[i].setX(result_matris[0]);
		pp[i].setY(result_matris[1]);
		pp[i].setZ(result_matris[2]);
	}
	return pp;
}
PointCloud Transform::doTransform(PointCloud *pc)
{
	/**
	* @brief : Nokta bulutunu donusturur.
	* @param *pc : Donusturulucek nokta bulutudur.
	*/
	int x = pc->getPointNumber();

	Point *p = new Point[x];
	p = pc->getPoints();

	p = doTransForm(p,x);
	
	PointCloud *ppc = new PointCloud(x);
	
	ppc->setPoints(p);

	return *ppc;
}