#include <stdio.h>
#define SIZE 256

void trim(const char * Src, char * Dest)
{
	size_t i = 0; //idx of src
	size_t j = 0; //idx of dest
	while (Src[i++] == ' '); --i;	
	while ((Dest[j++] = Src[i++]) != '\0'); --j;	
	while (Dest[--j] == ' ') Dest[j] = '\0';
}

int main()
{
	char word[SIZE] = "  Hi, what's up?   ";
	char dest[SIZE];

	trim(word, dest);

	printf("before trim :>%s<\n", word);
	printf("after trim : >%s<\n", dest);

#ifdef WIN32
	system("pause");
#endif
	return 0;
}
