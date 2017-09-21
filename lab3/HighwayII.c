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
	int bill = 0;

	for(i = 0; i < size; i += 3)
	{
		if(speed[i] != currenthour)
		{
			if(bill)
				printf("%d:00-%d:59 -> %d EUR\n", currenthour, currenthour, bill);
			bill = 0;
			currenthour = speed[i];
		}	
		if(speed[i + 2] > 180) bill += 150;
		else if(speed[i + 2] > 140) bill += 50;
	}
	if(size > 0) if(bill)
		printf("%d:00-%d:59 -> %d EUR\n", currenthour, currenthour, bill);
			
#ifdef WIN32
	system("pause");
#endif
	return 0;
}