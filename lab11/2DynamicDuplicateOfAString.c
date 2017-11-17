#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * copyString(const char * str)
{
	if(str)
	{
		const size_t s = strlen(str);
		char * res = malloc((s+1) * sizeof(char));
		size_t i = 0;
		for (; i <= s; ++i)
			res[i] = str[i];
		return res;
	}
	return NULL;
}

int main()
{
	const char * c = "coucou ceci est un test\n";
	printf("%s", c);
	char * copy = copyString(c);
	printf("%s", copy);
	free(copy);
	system("pause");
	return 0;
}