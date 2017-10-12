#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool vowel(const char cs)
{
	char c = tolower(cs);
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main(void)
{
	char c;
	while (scanf("%c", &c) == 1) 
	{
		if (vowel(c))
			printf("%ch%c", c, tolower(c));
		else
			printf("%c", c);
	}

	return 0;
}