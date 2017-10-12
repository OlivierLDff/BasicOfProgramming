#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

printCone(const size_t s)
{
	size_t i,j;
	for(i=0; i<s;++i)
	{
		printf("|");
		for(j=0; j<(s*2-2);++j)
			printf(" ");
		printf("|\n");
	}
}

printV(const size_t s)
{
	size_t i,j,k,l;
	l = (s*2-2);
	k=0;
	for(i=0; i<s;++i)
	{
		for(j=0;j<k;++j)
			printf(" ");
		printf("\\");
		for(j=0; j<l;++j)
			printf(" ");
		printf("/\n");
		++k;
		l-=2;
	}
}

int main()
{
	size_t s = 5;
	printCone(5);
	printV(5);
}