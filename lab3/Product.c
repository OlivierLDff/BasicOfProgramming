#include <stdio.h>
#include <stddef.h>
#include <math.h>

printArray(int * array, size_t size)
{
	int i;
	printf("[");
	for(i = 0; i <size; ++i)
	{
		printf(" %d", array[i]); 
		if(i != (size-1)) printf(",");
		else  printf(" ]");
	} 
	printf("\n");
}

int main(int argc, char ** argv, char ** envp)
{
	const size_t ARRAY_SIZE = 10;
	int array[] = {5,2,54,8,77,6,29,10,3,2};
	int i, j, n;

	printf("n? ");
	scanf("%d", &n);

	printf("Array : ");
	printArray(array, ARRAY_SIZE);

	for(i = 0; i < ARRAY_SIZE - 1; ++i)
		for(j = i + 1; j < ARRAY_SIZE; ++j)
			if(array[i] * array[j] == n)
				printf("%d*%d=%d\n", array[i], array[j], n);


#ifdef WIN32
	system("pause");
#endif
	return 0;
}