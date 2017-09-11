#include <stdio.h>
#include <math.h>
 
int main() 
{
	double a = 0;
	double n = 0;

	printf("a?\n");
	scanf("%lf", &a);
	printf("n?\n");
	scanf("%lf", &n);

	printf("%lf^%lf, %lf\n", a, n, pow(a, n));

#if WIN32
	system("pause");
#endif
}