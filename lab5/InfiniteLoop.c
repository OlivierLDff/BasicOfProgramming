#include <stdio.h>

int main(void) 
{
	int i = 1;
	while (i > 0) {
		++i;
	}
	printf("%d\n", i); //rollback

	return 0;
}