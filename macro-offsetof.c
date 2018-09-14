#include <stdio.h>
#include <stddef.h>

typedef struct {
    int campo1;
    double campo2[100];
    char campo3[20];
} Reg;

void main() {
    printf("Campo1 começa no offset %ld\n", offsetof(Reg, campo1));
    printf("Campo2 começa no offset %ld\n", offsetof(Reg, campo2));
    printf("Campo3 começa no offset %ld\n", offsetof(Reg, campo3));
}