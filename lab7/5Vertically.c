#include <stdio.h>

void printVertical(char * cs)
{
	while(*cs)
	{
		printf("%c\n", *cs);
		++cs;
	}
}

int main()
{
	char str[50];

	printf("Enter a string : ");
	gets(str);

	printVertical(str);

#ifdef WIN32
	system("pause");
#endif
	return 0;
}
