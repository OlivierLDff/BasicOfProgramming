#include <stdio.h>

int main(int argc, char ** argv, char ** envp)
{
	int n;
	int product = 1;
	printf("n? ");
	scanf("%d", &n);

	while(n>=2) product *= n--;

	printf("n! = %d\n", product);

#ifdef WIN32
	system("pause");
#endif
	return 0;
}