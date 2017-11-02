#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main()
{
	size_t n = 1;
	size_t i = 0;
	double * values = NULL;
	printf("Enter real value and finish the sequence by -1 \n");
	//scanf("%d", &n);

	values = malloc(sizeof(double)*n);
	if (!values)
		fprintf(stderr, "Fail to allocate dynamic array\n");
	else
	{
		double realValue = 0.f;
		scanf("%lf", &realValue);
		while(realValue != -1.f)
		{
			double * tArray = realloc(values, sizeof(double)*n);
			if(!tArray)
			{
				fprintf(stderr, "Fail to to realloc\n");
				free(values);
				values = NULL;
				realValue = -1.f;
			}
			else
			{
				values = tArray;
				values[n - 1] = realValue;
				scanf("%lf", &realValue);
				++n;
			}		
		}
		--n;

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
