#include <stdio.h>
#include <math.h>

int main() 
{
	int i, number;

	printf("Number ? \n");
	scanf("%d", &number);

	for (i = 1; i <= number; ++i) if (number % i == 0) printf("%d\n", i);
#if WIN32
	system("pause");
#endif
}