#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t fib(const uint32_t n)
{
	if(!n) return 0;
	if(n == 1) return 1;
	return fib(n - 1) + fib(n - 2);
}

uint32_t fib_it(const uint32_t n)
{
	int i;
	uint32_t f1 = 0;
	uint32_t f2 = 1;
	uint32_t fi;

	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	for (i = 2; i <= n; i++)
	{
		fi = f1 + f2;
		f1 = f2;
		f2 = fi;
	}
	return fi;
}

int main()
{
	size_t i = 0;
	for (; i < 40; ++i)
	{
		printf("fib(%d)\t\t= %d\n", i, fib(i));
		printf("fib_it(%d)\t= %d\n\n", i, fib_it(i));
	}	
#ifdef WIN32
	system("pause");
#endif
	return 0;
}
