#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main()
{
	size_t n;
	size_t i = 0;
	double * values = NULL;
	printf("Number Of real value to read?");
	scanf("%zu", &n);

	values = malloc(sizeof(double)*n);
	if(!values)
		fprintf(stderr, "Fail to allocate dynamic array\n");
	else
	{
		for (; i < n; ++i)
			scanf("%lf", &values[i]);

		printf("{");
		for (i = 1; i <= n; ++i)
			printf("%lf ", values[n - i]);
		printf("}\n");

		free(values);
		values = NULL;
	}

#ifdef WIN32
	system("pause");
#endif
	return 0;
}
