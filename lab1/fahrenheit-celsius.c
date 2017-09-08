#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PI 3.14

int main(void)
{
	float celsius, fahrenheit;

	printf("fahrenheit ? ");
	scanf("%f", &fahrenheit);

	printf("celsius : %.1f\n", (fahrenheit - 32)/1.8);

	system("pause");

	return 0;
}