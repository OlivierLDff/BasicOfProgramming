#include <stdio.h>

void printInNumeralSys(double length, double * area, double * volume)
{
	if(area && volume)
	{
		*area = length * length * 6;
		*volume = length * length * length;
	}
}

int main()
{
	double l = 2.7f;
	double a, v;
	printInNumeralSys(l, &a, &v);
	printf("length is = %lf, volume = %lf, area is = %lf\n", l, v, a);
#ifdef WIN32
	system("pause");
#endif
	return 0;
}
