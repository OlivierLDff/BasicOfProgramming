#include <stdio.h>
#include <stddef.h>

printArray(int * array, size_t size)
{
	int i;
	printf("Array:");
	for(i = 0; i <size; ++i) printf(" %d", array[i]); printf("\n");
}

void rotation(int * array, size_t size)
{
	int i;
	int temp;
	for(i = 0; i <size; ++i)
	{
		if(i == 0) temp = array[0];

		if(i == (size - 1)) array[i] = temp;
		else array[i] = array[i + 1];
	}
}

int main(int argc, char ** argv, char ** envp)
{
	const size_t ARRAY_SIZE = 10;
	int array[] = {25,69,54,8,77,6,29,10,3,98};
	int i;

	printArray(array, ARRAY_SIZE);
	for(i = 0; i < 10; ++i)
	{
		rotation(array, ARRAY_SIZE);
		printArray(array, ARRAY_SIZE);
	}
 
#ifdef WIN32
	system("pause");
#endif
	return 0;
}