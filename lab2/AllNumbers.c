#include <stdio.h>
#include <math.h>

#define MIN 1000
#define MAX 9999

int main() 
{
	int i, modTen, modHundred, modThousand, modTenThousand;

	for(i = MIN; i <= MAX; ++i)
	{
		if((modTen = (i % 10)) == 3 || 
			modTen == 4 || 
			modTen == 5 ||
			(modHundred = (i % 100)/10) == 3 || 
			modHundred == 4 || 
			modHundred == 5 ||
			(modThousand = (i % 1000)/100) == 3 || 
			modThousand == 4 || 
			modThousand == 5||
			(modTenThousand = (i % 10000)/1000) == 3 || 
			modTenThousand == 4 || 
			modTenThousand == 5) 
			printf("%d\n", i);
		
	}


#if WIN32
	system("pause");
#endif
}