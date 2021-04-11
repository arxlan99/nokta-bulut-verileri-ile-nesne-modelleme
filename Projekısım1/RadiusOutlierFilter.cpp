#include "RadiusOutlierFilter.h"


void RadiusOutlierFilter::filter(PointCloud &p)
{
	/**
	* @brief : Nokta nulutundaki her bir nokta icin tek tek islem yapilir.
	* @param &p : Filtereme yapilicak nokta bulutudur.
	*/
	int x = p.getPointNumber();

	Point *points = new Point[x];
	points = p.getPoints();

	for (int i = 0; i < x; i++)
	{
		int count = 0;
		for (int j = 0; j < x; j++)
		{
			if ((points[i].distance(points[j]) < radius) && i!=j)
			{
				count++;
				break;
			}

		}
		if (!count)
		{
			for (int k = i; k < p.getPointNumber() ; k++)
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