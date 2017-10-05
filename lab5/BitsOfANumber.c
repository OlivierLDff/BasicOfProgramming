#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

size_t sizeOfUint32tInBit()
{
	return sizeof(uint32_t) * 8 - 1;
}

void printValue(uint32_t value)
{
	int i = sizeOfUint32tInBit();
	for (; i >= 0; --i)
		printf("%d", value >> i & 1);
	printf("\n");
}


int main(void) 
{
	uint32_t var = 1;
	//int i = sizeof(uint32_t) * 8 - 1;
	printValue(var);
#ifdef WIN32
	system("pause");
#endif
    return 0;
}
