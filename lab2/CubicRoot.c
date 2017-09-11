#include <stdio.h>
#include <math.h>
 
int main() 
{
	double number, root;
	printf("number?\n");
	scanf("%lf", &number);
	printf("Root is %lf\n", root = sqrt(number));
	printf("approximation is %lf\n", ((number / pow(root, 2)) + (2*root))/3);

#if WIN32
	system("pause");
#endif
}