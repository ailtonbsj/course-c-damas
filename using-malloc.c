#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main() {
    char s[200], *ptr;

    printf("Qual a sua String: ");
    fgets(s, 200, stdin);

    //Aloca memoria nescessaria
    ptr = (char *) malloc(strlen(s)+1);
    if(ptr == NULL) {
        puts("Problemas na alocacao da memoria");
    } else {
        strcpy(ptr, s);
        printf("String original: %s\nCopia: %s\n", s, ptr);
        free(ptr);
    }

}