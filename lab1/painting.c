#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

int main(void)
{
	float height, diameter, area;
	printf("Paint the container\n\n");

	printf("Height? ");
	scanf("%f", &height);
	printf("Diameter? ");
	scanf("%f", &diameter);

	area  = PI*diameter*height + diameter*diameter*PI/2;

	printf("%.1f can(s) of paint needed.\n", (area/2));

	system("pause");

	return 0;
}