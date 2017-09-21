#include <stdio.h>
#include <stddef.h>

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
	int i;

	printArray(array, ARRAY_SIZE);
 
#ifdef WIN32
	system("pause");
#endif
	return 0;
}