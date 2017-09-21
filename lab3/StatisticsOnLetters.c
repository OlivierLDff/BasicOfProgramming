#include <stdio.h>
#include <stddef.h>
#include <string.h>

const size_t MAX_BUFFER = 512;
const size_t ALPHABET_LETTER_NUMBER = 26;

int main(int argc, char ** argv)
{
	char buffer[MAX_BUFFER];
	int i;
	scanf("%s", buffer);

	int numberOfLetter[ALPHABET_LETTER_NUMBER];
	memset(numberOfLetter, 0, ALPHABET_LETTER_NUMBER*sizeof(int));

	for(i = 0; buffer[i] != 0; ++i) 
		if(buffer[i] >= 'A' && buffer[i] <= 'Z')
			++numberOfLetter[buffer[i] - 'A'];

	for(i = 0; i < ALPHABET_LETTER_NUMBER; ++i) if(numberOfLetter[i])
		printf("%c: %d times\n", i + 'A', numberOfLetter[i]);

#ifdef WIN32
	system("pause");
#endif
	return 0;
}