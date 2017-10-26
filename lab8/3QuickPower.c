#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int powerRec(const int n, const int k)
{
	if (k == 0) return 1;
	if (k == 1) return n;
	if (k == 2) return n*n;
	
	if(n%2) //even
		return powerRec(n, k >> 1);
	return n*powerRec(n, k - 1); //odd
}

int powerRec_it(const int n, const int k)
{
	size_t i = 0;
	int res = 1;
	for (; i < k; ++i)
		res *= n;
	return res;
}

int main()
{
	size_t i = 0;
	for (; i < 16; ++i)
	{
		printf("2^%d=%d\n", i, powerRec(2, i));
		printf("2^%d=%d\n", i, powerRec_it(2, i));
	}
		
#ifdef WIN32
	system("pause");
#endif
	return 0;
}
