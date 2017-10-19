#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h> //Ne pas oublier d'inclure le fichier time.h
#define SIZE 10

size_t sizeOfUint32tInBit()
{
	return sizeof(uint8_t) * 8 - 1;
}

void printValue(uint8_t value)
{
	int i = sizeOfUint32tInBit();
	for (; i >= 0; --i)
		printf("%d", value >> i & 1);
}


void bitShifting(const uint8_t * arr, const size_t s, uint8_t * dest)
{
	if (!(arr && dest)) return;
	size_t i = 0;
	for(; i < s; ++i)
	{
		dest[i] = arr[i] << 1;
		if (i != s - 1)
			dest[i] += (arr[i + 1] & 0x80) ? 1 : 0;
	}
}


int main()
{
	uint8_t src[SIZE];
	uint8_t dest[SIZE];
	size_t i = 0;
	srand(time(NULL)); // initialisation de rand

	for (; i < SIZE; ++i)
		src[i] = rand();

	bitShifting(src, SIZE, dest);
	
	for (i = 0; i < SIZE; ++i)
	{
		printf("%d >\n", i);
		printf(" in : ");
		printValue(src[i]);
		printf("\nout : ");
		printValue(dest[i]);
		printf("\n");
	}

#ifdef WIN32
	system("pause");
#endif
	return 0;
}
