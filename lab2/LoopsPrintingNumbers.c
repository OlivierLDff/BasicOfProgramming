#include <stdio.h>
 
int main() 
{
	int from, to;

	printf("from number = ");
	scanf("%d", &from);
	printf("to number = ");
	scanf("%d", &to);

	while(from != to) printf("%d\n", (from <= to) ? from++ : from--); printf("%d\n", from);

#if WIN32
	system("pause");
#endif
}