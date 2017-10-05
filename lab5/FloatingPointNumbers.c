#include <stdio.h>
 
int main(void) {
    double dvar=1e20/1e-20;
    float fvar=1e20f/1e-20;
    printf("1. %g\n", dvar);
    printf("2. %g\n", fvar);
    printf("3. %g\n", 1e60);
    printf("4. %f\n", 1e60);
    printf("5. %s\n", 1e3+1 == 1e3 ? "yes" : "no");
    printf("6. %s\n", 1e30+1 == 1e30 ? "yes" : "no");
 
    return 0;
}