#include <stdio.h>
#include <math.h>

typedef struct point point;

struct point
{
	double x;
	double y;
};
 
int main() 
{
	point P = {0 , 0};
	point Q = {0 , 0};
	double result = 0;
 
	printf("Value of P.x?\n");
	scanf("%lf", &P.x);
	printf("Value of P.y?\n");
	scanf("%lf", &P.y);
	printf("Value of Q.x?\n");
	scanf("%lf", &Q.x);
	printf("Value of Q.y?\n");
	scanf("%lf", &Q.y);

	result = sqrt(pow(P.x - Q.x, 2) + pow(P.y - Q.y, 2));

	printf("length of line (%lf, %lf) - (%lf, %lf) is %lf\n", P.x, P.y, Q.x, Q.y, result);
#if WIN32
	system("pause");
#endif
}