#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void pForward(const uint8_t * a, const size_t n)
{
	if (n)
	{
		printf("%d ", a[0]);
		pForward(&a[1], n - 1);
	}		
	else printf("\n");
}

void pBackWard(const uint8_t * a, const size_t n)
{
	if (n)
	{
		printf("%d ", a[n - 1]);
		pBackWard(a, n - 1);
	}
	else printf("\n");
}

void pForward_it(const uint8_t * a, const size_t n)
{
	size_t i = 0;
	for (; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");
}

void pBackWard_it(const uint8_t * a, const size_t n)
{

	size_t i = n;
	for (; i > 0; --i)
		printf("%d ", a[i - 1]);
	printf("\n");
}

int main()
{
	uint8_t a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	pForward(a, 10);
	pForward_it(a, 10);
	pBackWard(a, 10);
	pBackWard_it(a, 10);

#ifdef WIN32
	system("pause");
#endif
	return 0;
}
