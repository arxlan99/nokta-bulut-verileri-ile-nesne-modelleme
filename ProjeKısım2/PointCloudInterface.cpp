#include "PointCloudInterface.h"


void PointCloudInterface::addGenerator(PointCloudGenerator *pcg)
{

	/**
	* @brief : Generator uyesine, PointCloudGenerator sinifindan turetilmis bir sinifin ornegini atar.
	* @param *pcg: PointCloudGenerator sinifindan turetilmis bir sinifin ornegidir.
	*/

	generators.push_back(pcg);
}

void PointCloudInterface::setRecorder(PointCloudRecorder *r)
{

	/**
	* @brief : Kaydedilecek dosya sinifinin ornegini alir. Bu siniftaki recorder nesnesine atar.
	* @param name: Dosya ismidir.
	*/

	recorder = r;
}

bool PointCloudInterface::generate()
{

	/**
	* @brief : Generators listesindeki pointcloud lari patch nesnesi ile toplar.
	* @return: True ya da false degerini dondurur.
	*/

	for (size_t i = 0; i < generators.size(); i++)
	{
		pointCloud = generators[i]->captureFor();
		
		if (!(patch.getPointNumber()))
			patch = pointCloud;
		else
			patch = (patch + pointCloud);
	}
	return true;
}

bool PointCloudInterface::record()
{

	/**
	* @brief : Recorder kullanarak Patch nesnesindeki nokta bulutlarini dosyaya yazdirir.
	* @return: True ya da false degerini dondurur.
	*/

	recorder->save(patch);
	return true;
}


