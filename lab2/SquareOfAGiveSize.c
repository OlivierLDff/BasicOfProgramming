#include <stdio.h>
 
void printLine(int size)
{
	int i;
	printf("+");
	for(i = 0; i < size; ++i) printf("-");
	printf("+\n");
}

void printInside(int size)
{
	int i;
	printf("|");
	for(i = 0; i < size; ++i) printf(".");
	printf("|\n");
}

int main() 
{
	int size, i;

	printf("Size of the Square?\n");
	scanf("%d", &size);
	if(size < 0) size = -size;

	printLine(size);
	for(i = 0; i < size; ++i) printInside(size);
	printLine(size);

#if WIN32
	system("pause");
#endif
}