#include <stdio.h>
#include <stddef.h>
#include <string.h>

const size_t MAX_BUFFER = 512;
const size_t ALPHABET_LETTER_NUMBER = 26;

int main(int argc, char ** argv)
{
	int ASuceed = 0;
	int BSuceed = 0;
	int CSuceed = 0;
	int DSuceed = 0;

	int bRun = 1;

	char c;
	int res1;
	int res2;
	int res3;

	while(bRun)
	{
		scanf("%c %d %d %d", &c, &res1, &res2, &res3);
		if(res1 >= 2 && res2 >= 2 && res3 >= 2 && res1+res2+res3>=12)
			switch(c)
			{	
				case 'A': ++ASuceed;
				break;
				case 'B': ++BSuceed;
				break;
				case 'C': ++CSuceed;
				break;
				case 'D': ++DSuceed;
				break;
				default:;	
			}
		if(c == 'x') bRun = 0;
	}
	
	printf("A : %d\n", ASuceed);
	printf("B : %d\n", BSuceed);
	printf("C : %d\n", CSuceed);
	printf("D : %d\n", DSuceed);

#ifdef WIN32
	system("pause");
#endif
	return 0;
}