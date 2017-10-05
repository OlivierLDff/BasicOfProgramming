#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void) 
{
	uint32_t var = 1;
	while(var)
	{
		printf("%u\n", var);
		var = var << 1;		
	}
#ifdef WIN32
		system("pause");
#endif
	return 0;
}
