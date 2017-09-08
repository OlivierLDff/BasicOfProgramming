#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PI 3.14

int main(void)
{
	int fiftyCoins, hundredCoins, twoHundredCoins;
	bool bValidCoins = false;
	printf("Let's guess how many do you have?\n\n");

	printf("50 ft coins? ");
	while(!bValidCoins)
	{	
		scanf("%d", &fiftyCoins);
		if(fiftyCoins < 0) printf("please enter a positive number");
		else bValidCoins = true;
	}

	bValidCoins = false;
	printf("100 ft coins? ");
	while(!bValidCoins)
	{	
		scanf("%d", &hundredCoins);
		if(hundredCoins < 0) printf("please enter a positive number");
		else bValidCoins = true;
	}
		
	bValidCoins = false;
	printf("200 ft coins? ");
	while(!bValidCoins)
	{	
		scanf("%d", &twoHundredCoins);
		if(twoHundredCoins < 0) printf("please enter a positive number");
		else bValidCoins = true;
	}

	printf("\nYou have %d ft\n\n", 50*fiftyCoins + 100*hundredCoins + 200*twoHundredCoins);

	system("pause");

	return 0;
}