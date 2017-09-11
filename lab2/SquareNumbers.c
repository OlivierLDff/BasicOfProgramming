#include <stdio.h>
#include <math.h>

int main() 
{
	int N, i, iSquare;

	printf("N?\n");
	scanf("%d", &N);
	printf("the first %d square numbers are : \n", N);
	for(i = 1; i <= N; ++i) printf("%d\n", (int)pow(i,2));

	printf("all square numbers less than %d : \n", N);
	i = 1;
	while((iSquare = (int)pow(i++, 2)) < N) printf("%d\n", iSquare);


#if WIN32
	system("pause");
#endif
}