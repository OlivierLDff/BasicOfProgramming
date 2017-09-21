#include <stdio.h>

int main()
{
	int n = 4;
	int i = 0;
	int j;
	int space = n - 1;
	int numberOfBubble = 1;
	for(i; i < n ; ++i)
	{
		for(j = 0; j < space; ++j) printf(" ");
		for(j = 0; j < numberOfBubble; ++j) printf("0");
		space--;
		numberOfBubble+=2;
		printf("\n");
	}
}