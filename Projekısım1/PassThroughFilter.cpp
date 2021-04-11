#include "PassThroughFilter.h"



PassThroughFilter::PassThroughFilter(double ux, double lx, double uy, double ly, double uz, double lz)
{
	/**
	* @brief : Alinan upper ve lower degerlerini degiskenlere atar.
	* @param ux: x in upper limiti
	* @param uy: y in upper limiti
	* @param uz: z in upper limiti
	* @param lx: x in lower limiti
	* @param ly: y in lower limiti
	* @param lz: z in lower limiti
	*/

	upperLimitX = ux;
	lowerLimitX = lx;
	upperLimitY = uy;
	lowerLimitY = ly;
	upperLimitZ = uz;
	lowerLimitZ = lz;
}

void PassThroughFilter::filter(PointCloud &p)
{		
	/**
	* @brief : Nokta bulutunu filtreler.
	* @param &p: Nokta bulutudur
	*/
	int x = p.getPointNumber();

	Point *points = new Point[x];
	points = p.getPoints();

	for (int i = 0; i < x; i++)
	{
		if (((points[i].getX() >= lowerLimitX || points[i].getX() <= upperLimitX)
			|| (points[i].getY() >= lowerLimitY || points[i].getY() <= upperLimitY)
			|| (points[i].getZ() >= lowerLimitZ || points[i].getZ() <= upperLimitZ)))
		{
			for (int k = i; k < p.getPointNumber(); k++)
			{
				points[k].setX(points[k + 1].getX());
				points[k].setY(points[k + 1].getY());
				points[k].setZ(points[k + 1].getZ());
			}
			p.decrementPointNumber();
			i--;
		}
	}
}


