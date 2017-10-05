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

void ClearArray(uint32_t * values, size_t s)
{
	memset(values, 0, sizeof(values)*s);
}

uint32_t sizeToBitMask(size_t size)
{
	return 0x80000000 >> size;
}

void SetPx(uint32_t * values, size_t s, size_t x, size_t y, bool bValue)
{
	if (x <= sizeOfUint32tInBit() && y < s)
	{
		if (bValue)
			values[y] |= sizeToBitMask(x);
		else
			values[y] &= ~sizeToBitMask(x);
	}
}

int main(void)
{
	uint32_t var = 29;
	unsigned long values[24];
	size_t x, y;
	int c = 1;

	ClearArray(values, 24);
	while (c >= 0)
	{
		printf("x=");
		scanf("%d", &x);

		printf("y=");
		scanf("%d", &y);
		printf("command (0 : empty pixel, 1 : draw px, 2 : clear array, <0 exit program)=");
		scanf("%d", &c);
		switch (c)
		{
		case 0:case 1:
			SetPx(values, 24, x, y, c);
			break;
		default:
			ClearArray(values, 24);
		}
		printDrawing(values, 24);
	}


#ifdef WIN32
	system("pause");
#endif
	return 0;
}
