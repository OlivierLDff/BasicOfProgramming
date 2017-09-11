#include <stdio.h>
#include <math.h>
 
int main() 
{
	int N, x, i;

	printf("N?\n");
	scanf("%d", &N);
	x = 2;

	printf("x0 = %d\n", x);
	for(i = 1; i <= N; ++i) printf("x%d = %d\n", i, x = 2*x+5);

#if WIN32
	system("pause");
#endif
}