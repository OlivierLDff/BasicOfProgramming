#include <stdio.h>
#define SIZE 6
const int * foo(const int * arr, const size_t size)
{
	if (!arr) return NULL;
	size_t i = 0;
	size_t j = 0;
	for (; i < size; ++i)
		for (j = i + 1; j < size; ++j) if (arr[i] == arr[j]) return &arr[i];
	return NULL;
}

int main()
{
	int arr[SIZE] = { 1, 2, 3, 4, 5, 3 };
	const int * elt = foo(arr, SIZE);
	if (elt)
		printf("First element that is present twice is %d\n", *elt);
	else
		printf("No element is present twice\n");
	
#ifdef WIN32
	system("pause");
#endif
	return 0;
}
