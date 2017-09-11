#include <stdio.h>
#include <math.h>

#define PI 3.14
#define INCREASE_VALUE 0.1f
#define VOLUME_LIMIT 1

int main() 
{
	double radius = 0.1f;
	double volume;

	while((volume = 4*PI*pow(radius, 3)/3) < VOLUME_LIMIT) 
	{
		printf("%lf\n", volume);
		radius+=INCREASE_VALUE;
	}

#if WIN32
	system("pause");
#endif
}