#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void pNumeralSys(const uint32_t n, const uint32_t base)
{
	if (!n) return;
	pNumeralSys(n / base, base);
	printf("%d ", n%base);
}

void pNumeralSys_it(uint32_t n, const uint32_t base)
{
	uint32_t buf[32]; //32 is enough for 32 bits in base 2
	size_t i = 0;
	while(n / base)
	{		
		buf[i++] = n%base;
		n = n / base;
	}
	buf[i++] = n%base;
	for (; i > 0; --i)
		printf("%d ", buf[i - 1]);
	printf("\n");
}

int main()
{
	int n = 1234;
	pNumeralSys(n, 10);
	printf("\n");
	pNumeralSys_it(n, 10);
	pNumeralSys(n, 16);
	printf("\n");
	pNumeralSys_it(n, 16);
	pNumeralSys(n, 2);
	printf("\n");
	pNumeralSys_it(n, 2);
	pNumeralSys(n, 8);
	printf("\n");
	pNumeralSys_it(n, 8);
#ifdef WIN32
	system("pause");
#endif
	return 0;
}
