#include <stdio.h>
#include <math.h>
 
int main() 
{
	int iter, i;
	double number, approx;
	printf("number?\n");
	scanf("%lf", &number);
	printf("approx?\n");
	scanf("%lf", &approx);
	printf("iter?\n");
	scanf("%d", &iter);

	for(i = 0; i <= iter; ++i)
	{
		approx = (number/(pow(approx,2))+2*approx)/3;
	}

	//printf("Root is %lf\n", root = sqrt(number));
	printf("approximation is %lf\n", approx);

#if WIN32
	system("pause");
#endif
}