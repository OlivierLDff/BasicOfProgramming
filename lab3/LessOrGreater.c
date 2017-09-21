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
	int array[] = {25,69,54,8,77,6,29,10,3,98};
	int limit, i;
	int upperset = 0;
	int lowerset = 0;

	printf("print the limit? ");
	scanf("%d", &limit);

	printf("Array : ");
	printArray(array, ARRAY_SIZE);

	for(i = 0; i < ARRAY_SIZE; ++i)
		if(array[i] > limit) ++upperset;
		else if(array[i] < limit) 
			++lowerset;

	printf("Number of value in upper set : %d\n", upperset);
	printf("Number of value in lower set : %d\n", lowerset);
			
	if(upperset > lowerset)
		printf("There is more value in the upper set\n");
	else if(upperset < lowerset)
		printf("There is more value in the lower set\n");
	else
		printf("There is the same number of element in each set\n");

#ifdef WIN32
	system("pause");
#endif
	return 0;
}