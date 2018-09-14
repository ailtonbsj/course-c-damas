#include <stdio.h>
#include "arquivo1.c"
#include "arquivo2.c"

int var;

void main() {
    int i = 2, j = 5;
    var = 3;
    printf("%d\n", f1(i));
    printf("%d\n", f2(j));
}