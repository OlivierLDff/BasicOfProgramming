#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void printNicely(const uint32_t n)
{
	const uint32_t t = n / 1000;
	if (t)
	{
		printNicely(t);
		printf("%03d ", n % 1000);
	}
	else
		printf("%d ", n % 1000);
}

void printNicely_it(uint32_t n)
{
	uint32_t buf[4];
	size_t i = 0;
	buf[i++] = n % 1000;
	while (n / 1000)
	{
		n = n / 1000;
		buf[i++] = n % 1000;
	}
	if (i)printf("%d ", buf[i - 1]);
	--i;
	for (; i > 0; --i)
		printf("%03d ", buf[i - 1]);	
	printf("\n");
}

int main()
{
	uint32_t a[] = { 16077216,999,1000,12,0,1000222 };
	size_t i = 0;
	for (; i < 6; ++i)
	{
		printNicely(a[i]);
		printf("\n");
		printNicely_it(a[i]);
	}	
	
#ifdef WIN32
	system("pause");
#endif
	return 0;
}
