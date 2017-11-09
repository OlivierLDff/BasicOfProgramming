#include <stdio.h>
 
int *f1(int i) {
    return &i;
}
 
int main(void) {
    int *p;
    p = f1(10); //p is dealloacted from memory when returned
    printf("%d\n", *p);
    printf("%d\n", *p);
    return 0;
}