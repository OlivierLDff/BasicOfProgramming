#include <stdio.h>

int main(int argc, char ** argv, char ** envp)
{
	int n, i;
	int sum = 0;
	printf("n? ");
	scanf("%d", &n);

	//for (i = 1; i<=n; ++i)//number include
	for(i = 1; i<n; ++i) //number not include
		if (n%i == 0) sum += i;

	printf("sum is %d\n", sum);
	if (sum == n) printf("it is a perfect number\n");

#ifdef WIN32
	system("pause");
#endif
	return 0;
}