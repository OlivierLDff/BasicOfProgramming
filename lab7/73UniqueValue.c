#include <stdio.h>
#include <stdbool.h>
#define SIZE 10

void uniqueValue(const int * arr, const size_t s, int * dest, size_t * sDest)
{
	if (!(arr && dest && sDest)) return;
	size_t i = 0;
	size_t j = 0;
	*sDest = 0;
	for (; i < s; ++i)
	{
		bool bFound = false;
		for (j = 0; j < s; ++j) if (i != j && arr[i] == arr[j])
		{
			bFound = true;
			break;
		}
		if (!bFound) dest[(*sDest)++] = arr[i];
	}
}


int main()
{
	int arr[SIZE] = { 2, 7, 5, 8, 9, 5, 7, 5, 5, 3 };
	int dest[SIZE];
	size_t s;
	size_t i = 0;
	uniqueValue(arr, SIZE, dest, &s);
	printf("unique value are ={");
	for (; i < s; ++i) 
		if(i == s - 1)
			printf("%d", dest[i]);
		else
			printf("%d, ", dest[i]);
	printf("}\n");
#ifdef WIN32
	system("pause");
#endif
	return 0;
}
