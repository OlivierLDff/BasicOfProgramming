#include <stdio.h>
#include <stdbool.h>
#define SIZE 8

const double * IsSorted(const double * arr, const size_t s)
{
	if (!arr) return NULL;
	size_t i = 2;
	if (s < 3) return NULL;
	bool bAscending = arr[0] < arr[1];
	for(; i < s; ++i)
		if (arr[i - 1] < arr[i] != bAscending) return &arr[i];
	return NULL;
}

int main()
{
	double arr[SIZE] = { -8.11, -5.3, 0.1, 2.5, 1.4, 6.9, 12.0, 5.7 };
	const double * elt = IsSorted(arr, SIZE);
	if (elt)
		printf("First element that break the pattern is %lf\n", *elt);
	else
		printf("Array is ordered\n");

#ifdef WIN32
	system("pause");
#endif
	return 0;
}
