#include <stdio.h>
#include <stddef.h>
#include <math.h>

int main(int argc, char ** argv, char ** envp)
{
	const size_t arraysize = 18;
	double riverArray[] = {0.1, 1, 1.5, 1.7, 2, 2.3, 2.8, 4.5, 9.8, 12, 14.1, 13, 11.9, 8.7, 6.1, 3.5, 1, 0.5};
	int i;
	double steppest = 0;
	int meter = 0;
	double tempAbs;
	for(i = 0 ; i < arraysize - 1; ++i)
	{
		tempAbs = fabs(riverArray[i] - riverArray[i + 1]);
		if(tempAbs > steppest)
		{
			steppest = tempAbs;
			meter = i;
		} 
	}
	meter *= 2;
	printf("The steppest part of the river is between %d meter and %d meter with a step of %lf\n", meter, meter + 2, steppest);
 
#ifdef WIN32
	system("pause");
#endif
	return 0;
}