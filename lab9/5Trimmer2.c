#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 256

char * trim(const char * Src)
{
	size_t i = 0; //idx of src
	size_t j = 0; //idx of dest
	size_t l = strlen(Src);
	char * dest = malloc(l + 1);
	if(!dest)
	{
		printf("fail to allocate memory\n");
		return NULL;
	}
	while (Src[i++] == ' '); --i;
	while ((dest[j++] = Src[i++]) != '\0'); --j;
	while (dest[--j] == ' ') dest[j] = '\0';
	l = strlen(Src);
	char * tDest = realloc(dest, l + 1);
	if (tDest)
		return tDest;
	printf("fail to reallocate memory\n");
	return dest;
}

int main()
{
	char word[SIZE] = "  Hi, what's up?   ";
	char * Dest = trim(word);

	printf("before trim :>%s<\n", word);
	if (Dest)
	{
		printf("after trim : >%s<\n", Dest);
		free(Dest);
	}

#ifdef WIN32
	system("pause");
#endif
	return 0;
}
