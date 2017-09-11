#include <stdio.h>
 
int main() 
{
	int length;

	printf("Length of the line?\n");
	scanf("%d", &length);
	if(length < 0) length = -length;

	printf("+");
	while(length--) printf("-");
	printf("+\n");

#if WIN32
	system("pause");
#endif
}