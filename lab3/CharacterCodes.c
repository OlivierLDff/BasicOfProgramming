#include <stdio.h>

int main(int argc, char ** argv, char ** envp)
{
	char letter;
    while (scanf("%c", &letter) == 1)
        printf("letter='%c', letter=%d\n", letter, letter);

#ifdef WIN32
	system("pause");
#endif
	return 0;
}