#ifndef RADIUS_OUTLIER_FILTER_H
#define RADIUS_OUTLIER_FILTER_H

/**
* @author Ozkan ARSLAN stechnorsk59@gmail.com
* @date :6 Aralik 2019 Cuma
* @brief : Bu nokta bulutunda filtreleme yapar. Filter fonksiyonu ile nokta bulutunu alir
* ve filtrelenmis halini dondurur.
*/

#include "PointCloud.h"

class RadiusOutlierFilter
{
	double radius ;
public:
	RadiusOutlierFilter(int value) { radius = value; };
	void filter(PointCloud &);
};

#endif
