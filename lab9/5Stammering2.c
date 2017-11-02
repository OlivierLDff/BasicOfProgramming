#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

bool vowel(const char cs)
{
	char c = tolower(cs);
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

char * Stammer(char * st, const char c)
{
	//size_t n = 1;
	//char c = 0;
	size_t n = (st ? strlen(st) + 1 : 1);
	const bool bVowel = vowel(c);
	const size_t aSize = sizeof(char)*n + (bVowel ? 3 : 1);
	char * res = st ? realloc(st, aSize) : malloc(aSize);
	if (res)
	{
		if (!st) n = 1;
		res[n-1] = c;
		if(bVowel)
		{
			res[n++] = 'h';
			res[n++] = tolower(c);
		}		
		res[n] = '\0';
		return res;
	}
	return st;
}

int main(void)
{
	char c;
	char * s = NULL;
	while (scanf("%c", &c) == 1 && c != '\n')
		s = Stammer(s, c);

	if (s)
		printf("Stammer string : %s\n", s);
	else
		printf("empty string\n");

	if (s)
		free(s);
#ifdef WIN32
	system("pause");
#endif
	return 0;
}