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
		if (dynString) free(dynString);
		return res;
	}
	return dynString;
}

char * subString(const size_t begin, const size_t end, const char * src)
{
	const size_t s = src ? strlen(src) : 0;
	if (s && begin < end && end <= s)
	{
		char * res = malloc(sizeof(char)*(end - begin + 1));

		int i = 0;

		for (; i < end - begin; ++i)
			res[i] = src[i + begin];
		res[i] = '\0';
		return res;
	}
	return NULL;
}

char * dynInsertString(const char * src, const size_t idx, const char * toInsert)
{
	if(src && toInsert)
	{
		const size_t s1 = strlen(src); //Size of the first string
		const size_t s2 = strlen(toInsert); //Size of the first string
		char * res = malloc((s1 + s2 + 1) * sizeof(char)); //size of both string + \0

		int i = 0;
		for (; i < idx; ++i)
			res[i] = src[i];
		for (; i < idx + s2; ++i)
			res[i] = toInsert[i - idx];
		for (; i < s2 + s1; ++i)
			res[i] = src[i - s2];
		res[i] = '\0';

		return res;
	}
	return NULL;
}

int main()
{
	char * buffer = NULL;
	const char * c = "Hello, World";
	buffer = dynInsertString("hello!", 5, ", world");

	printf("%s\n", buffer);

	free(buffer);

	system("pause");
	return 0;
}