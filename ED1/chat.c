#include <stdio.h>

int main(void) {

    int x,*p;
    x = 100;
    p = &x;

    printf(" %p \t %d", p, *p);

    return 0;
}