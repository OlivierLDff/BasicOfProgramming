#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * copyString(const char * str)
{
	if (str)
	{
		const size_t s = strlen(str);
		char * res = malloc((s + 1) * sizeof(char));
		size_t i = 0;
		for (; i <= s; ++i)
			res[i] = str[i];
		return res;
	}
	return NULL;
}

char * catString(char * dynString, const char * toAppend)
{
	if (toAppend)
	{
		const size_t s1 = dynString ? strlen(dynString) : 0; //Size of the first string
		const size_t s2 = strlen(toAppend); //Size of the first string

		char * res = malloc((s1 + s2 + 1) * sizeof(char)); //size of both string + \0
		size_t i = 0;
		for (; i < s1; ++i)
			res[i] = dynString[i];
		for (; i <= s1 + s2; ++i)
			res[i] = toAppend[i - s1];
		if(dynString) free(dynString);
		return res;
	}
	return dynString;
}

int main()
{
	char * buffer = NULL;
	const char * c = "coucou ceci est un test";
	buffer = catString(buffer, c);
	printf("%s\n", buffer);

	const char * c2 = " ceci est un append";
	buffer = catString(buffer, c2);
	printf("%s\n", buffer);

	free(buffer);

	system("pause");
	return 0;
}