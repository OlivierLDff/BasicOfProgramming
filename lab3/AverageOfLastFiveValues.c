#include <stdio.h>
#include <stddef.h>

void ShiftArray(int * array, size_t size)
{
	int i;
	for(i = 0; i < size - 1; ++i)
		array[i] = array[i + 1];
}

int average(int * array, size_t size)
{
	int i;
	int result = 0;
	for (i = 0; i < size; ++i)
		result += array[i];
	return result / size;
}

void printArray(int * array, size_t size)
{
	int i;
	printf("[");
	for(i = 0; i < size; ++i)
	{
		printf(" %d", array[i]); 
		if(i != (size-1)) printf(",");
		else  printf(" ]");
	} 
	printf("\n");
}
const size_t SIZE = 5;

int main(int argc, char ** argv, char ** envp)
{
	printf("Enter a number until 0\n");

	int FiveLastEntry[] = {1,1,1,1,1};
	int entry = 1;
	int i;
	size_t FiveLastEntryIndex = 0;
	while(entry != 0)
	{
		scanf("%d", &entry);
		if(entry != 0)
		{
			if (FiveLastEntryIndex == SIZE)
				ShiftArray(FiveLastEntry, FiveLastEntryIndex + 1);
			if(FiveLastEntryIndex == SIZE)
				FiveLastEntry[FiveLastEntryIndex - 1] = entry;
			else  
				FiveLastEntry[FiveLastEntryIndex] = entry;
			if (FiveLastEntryIndex < SIZE) ++FiveLastEntryIndex;
		}	
	}
	if(FiveLastEntryIndex)
	{
		printf("Last Entries : ");
		printArray(FiveLastEntry, FiveLastEntryIndex);
		printf("Average is %d\n", average(FiveLastEntry, FiveLastEntryIndex));
	}
 
#ifdef WIN32
	system("pause");
#endif
	return 0;
}