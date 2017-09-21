#include <stdio.h>
#include <stddef.h>

typedef enum EMonotony
{
	EMonotony_None,
	EMonotony_Unknown,
	EMonotony_Increasing,
	EMonotony_Decreasing
} EMonotony;

EMonotony EvaluateMonotony(int * array, size_t size)
{
	EMonotony result = EMonotony_None;
	int i;
	if(size <= 1) return result;

	if( array[0] == array[1]) 
		result = EMonotony_Unknown;
	else 
		result = array[0] > array[1] ? EMonotony_Decreasing : EMonotony_Increasing;

	for(i = 1; i < size - 1; ++i)
	{
		switch(result)
		{
			case EMonotony_None: return result;

			case EMonotony_Unknown:
			if(array[i] != array[i + 1])
			{
				if(array[i] > array[i + 1])
					result = EMonotony_Decreasing;
				else
					result = EMonotony_Increasing;
			}
			break;

			case EMonotony_Increasing:
			if(array[i] > array[i + 1]) result = EMonotony_None;
			break;

			case EMonotony_Decreasing: 			
			if(array[i] < array[i + 1]) result = EMonotony_None;
			break;

			default:;
		}
	}
	return result;
}

printMonotony(int * array, size_t size)
{
	EMonotony monotony = EvaluateMonotony(array, size);
	printf("Evaluate array : "); printArray(array, size);
	switch(monotony)
	{
		case EMonotony_None: printf("Array isn't monotone\n"); break;
		case EMonotony_Unknown: printf("Array is unknown\n"); break;
		case EMonotony_Increasing: printf("Array is increasing\n"); break;
		case EMonotony_Decreasing: printf("Array is decreasing\n"); break;
		default:;
	}
}

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
	int array1[] = {5,5,5,5,5,5,5,5,5,5};
	int array2[] = {5,6,5,5,5,5,5,5,5,5};
	int array3[] = {5,6,8,10,10,10,11,12,13,58};
	int array4[] = {5,6,8,10,10,10,11,12,13,1};
	int array5[] = {6,4,5,5,5,5,5,5,5,5};
	int array6[] = {1,4,5,5,5,5,5,5,5,78};
	int array7[] = {85,9,9,5,10,5,5,5,5,1};
	int array8[] = {85,9,9,5,5,5,5,5,5,1};
	
	printf("Should be none\n");
	printMonotony(array, ARRAY_SIZE);
	printf("Should be Unknown\n");
	printMonotony(array1, ARRAY_SIZE);
	printf("Should be none\n");
	printMonotony(array2, ARRAY_SIZE);
	printf("Should be increasing\n");
	printMonotony(array3, ARRAY_SIZE);
	printf("Should be none\n");
	printMonotony(array4, ARRAY_SIZE);
	printf("Should be none\n");
	printMonotony(array5, ARRAY_SIZE);
	printf("Should be increasing\n");
	printMonotony(array6, ARRAY_SIZE);
	printf("Should be none\n");
	printMonotony(array7, ARRAY_SIZE);
	printf("Should be decreasing\n");
	printMonotony(array8, ARRAY_SIZE);
 
#ifdef WIN32
	system("pause");
#endif
	return 0;
}