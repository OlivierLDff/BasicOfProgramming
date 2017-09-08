#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PI 3.14

int main(void)
{
	float celsius, fahrenheit;

	printf("celsius ? ");
	scanf("%f", &celsius);

	printf("fahrenheit : %.1f\n", celsius*1.8 + 32);

	system("pause");

	return 0;
}