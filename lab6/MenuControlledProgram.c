/*Create a simple menu controlled program! 
 *The program stores a number with an initial value of n = 1. 
 *Then the program should print the actual value of n and the menu below. 
 *After the user selects a menu item (scanf()) the program should do ton 
 *whatever the user requested and print the value of n and the menu! 
 *These must be repeated as long as the user chooses anything but the Exit
 * menu option! Use switch() and post-testing do ... while() loop.*/

#include <stdio.h>

int main()
{
	int n = 1;
	int bIsRunning = 1;
	int opt;
	while(bIsRunning)
	{
		printf("0. Restore the initial value (n = 1)\n"
			"1. Add 1\n"
			"2. Negate the number (+/-)\n"
			"3. Multiple by 2\n"
			"9. Exit\n");
		scanf("%d", &opt);

		switch(opt)
		{
		case 0: n = 1; break;
		case 1: n += 1; break;
		case 2: n = -n; break;
		case 3: n <<= 1; break;
		case 9: bIsRunning = 0;	break;
		default: ;
		}

		printf("n=%d\n", n);
	}
	
}