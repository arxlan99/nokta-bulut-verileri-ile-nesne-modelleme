#include <iostream>
#include <cmath>
const double PI = 3.14159265358979323846;
using namespace std;
int main()
{
	double gama = 0, beta = 0, alpha = -90;
	gama = (gama * PI / 180.0);
	beta = (beta * PI / 180.0);
	alpha = (alpha * PI / 180.0);

	double transMatrix[4][4];

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

	double result[4];
	double matris[4] = {150,150,-50,1};

	for (int i = 0; i < 4; i++)
	{
		double carpim =1;
		double toplam = 0;
		for (int j = 0; j < 4; j++)
		{
			carpim =  transMatrix[i][j] * matris[j];
			toplam += carpim;
		}
		result[i] = toplam;
	}

	cout << result[0] << " " << result[1] << " " << result[2] << endl ;



	system("pause");
}