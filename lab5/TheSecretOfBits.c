#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

size_t sizeOfUint32tInBit()
{
	return sizeof(uint32_t) * 8 - 1;
}

void printValue(uint32_t value)
{
	int i = sizeOfUint32tInBit();
	for (; i >= 0; --i)
		printf("%c", value >> i & 1 ? '#' : ' ');
	printf("\n");
}

void printDrawing(uint32_t * values, size_t s)
{
	int i = 0;
	for (; i<s; ++i)
		printValue(values[i]);
}

int main(void)
{
	unsigned long values[8] = { 0U, 2436482610U, 2862950730U, 2762287426U,
		2436483450U, 2317437256U, 2216764978U, 0U };
	printDrawing(values, 8);
	
	
#ifdef WIN32
	system("pause");
#endif
	return 0;
}
