#include <stdio.h>
 
int main(void)
{
    double dvar=(4.f +2.f-(3.f -(6+4.f/5.f)))/(3*(2-7));
	printf("result = %lf\n", dvar); 
#ifdef WIN32
	system("pause");
#endif
    return 0;
}