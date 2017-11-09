#include <stdio.h>
 
int *f1(int i) {
    return &i;
}
 
int main(void) {
    int x = 10;
    int *p = f1(x); //x is copied into a new variable i that is deallocated when f1 return, so p point to nowhere
    printf("%d\n", *p);
    printf("%d\n", *p);
    return 0;
}