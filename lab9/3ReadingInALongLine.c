#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

char * read_long_line()
{
	size_t n = 1;
	char c = 0;
	char * res = malloc(sizeof(char)*n);
	if (!res)
		fprintf(stderr, "Fail to allocate dynamic array\n");
	else
	{
		res[0] = '\0';
		scanf("%c", &c);
		++n;
		while (c != '\n')
		{
			char * tArray = realloc(res, sizeof(char)*n);
			if (!tArray)
			{
				fprintf(stderr, "Fail to to realloc\n");
				return res;
			}
			res = tArray;
			size_t i = 0;
			res[n - 2] = c;
			res[n - 1] = '\0';
			scanf("%c", &c);
			++n;
		}
	}
	return res;
}

int main()
{
	char * res = read_long_line();
	printf("string read : \"%s\"\n", res);
	free(res);
	res = NULL;
#ifdef WIN32
	system("pause");
#endif
	return 0;
}
