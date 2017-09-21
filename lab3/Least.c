#include <stdio.h>

const size_t ARRAY_SIZE = 10;

int main(int argc, char ** argv, char ** envp)
{
	int array[] = {25,69,54,8,77,6,29,10,3,98};
	int i;
	int leastElement = array[0];

	printf("Array:");
	for(i = 0; i <ARRAY_SIZE; ++i) printf(" %d", array[i]); printf("\n");
	printf("A tömb:");
	for(i = 0; i <ARRAY_SIZE; ++i) printf(" %d]=%d", i, array[i]); printf("\n");

	for(i = 0; i <ARRAY_SIZE; ++i) 
		if(array[i] < leastElement) leastElement = array[i];

	printf("The least : %d\n", leastElement);
	printf("Denoted:");
	for(i = 0; i <ARRAY_SIZE; ++i)
	{
		 printf(" %d", array[i]);
		 if(array[i] == leastElement) printf("[MIN]");
	} 
	printf("\n");
	 
 
#ifdef WIN32
	system("pause");
#endif
	return 0;
}