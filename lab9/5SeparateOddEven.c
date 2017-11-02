#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int ** separate(int *a, const int n)
{
	int ** result = malloc(3*sizeof(int *));
	if (!result) return NULL;
	int i = 0;
	for (; i < 2; ++i)
		result[i] = malloc(n * sizeof(int));
	result[2] = malloc(2 * sizeof(int));
	result[2][0] = result[2][1] = 0;

	for(i = 0; i < n; ++i)
		if(a[i]&1)
			result[0][result[2][0]++] = a[i];
		else
			result[1][result[2][1]++] = a[i];

	for (i = 0; i < 2; ++i)
	{
		int * ta = realloc(result[i], result[2][i] * sizeof(int));
		if (ta)
			result[i] = ta;
		else
			printf("fail to reallocate\n");
	}

	return result;
}

int main(void)
{
	int i = 0;
	int a[] = { 1, 2, 3, 4, 5 };

	int ** result = separate(a, 5);

	if(!result)
	{
		printf("fail\n");
		return 0;
	}

	printf("odd value : { ");
	for(; i < result[2][0]; ++i)
		printf("%d ", result[0][i]);
	printf("}\n");

	printf("even value : { ");
	for (i = 0; i < result[2][1]; ++i)
		printf("%d ", result[1][i]);
	printf("}\n");

	for (i = 0; i < 3; ++i) if(result[i])
		free(result[i]);
	free(result);
		
#ifdef WIN32
	system("pause");
#endif
	return 0;
}