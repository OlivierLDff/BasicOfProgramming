#include <stdio.h>
#include <stddef.h>
#include <math.h>

int main(int argc, char ** argv)
{
	const size_t size = 30;
	int speed [] =
	{
		12, 1, 145,
		12, 23, 254,
		12, 45, 110,
		13, 41, 120,
		14, 21, 145,
		14, 23, 150,
		14, 28, 158,
		17, 25, 120,
		17, 28, 150,
		20, 8, 285
	};
	int i;
	int currenthour = speed[0];
	int bestspeed = 0;

	for(i = 0; i < size; i += 3)
	{
		if(speed[i] != currenthour)
		{
			printf("%d:00-%d:59 -> %d km/h\n", currenthour, currenthour, bestspeed);
			bestspeed = 0;
			currenthour = speed[i];
		}	
		if(speed[i + 2] > bestspeed) bestspeed = speed[i + 2];
	}
	if(size > 0)
		printf("%d:00-%d:59 -> %d km/h\n", currenthour, currenthour, bestspeed);
			
#ifdef WIN32
	system("pause");
#endif
	return 0;
}