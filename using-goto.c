#include <stdio.h>

void main() {
    int n, i;
    printf("Introd. um inteiro: ");
    scanf("%d", &n);

    for(i=1; i<=10; i++)
        if(n == i) goto salta1;
        else if(n*i == 50) goto salta2;
    
    puts("\nNenhuma condicao se verificou.\n");
    goto fim;

    salta1:
        puts("n: Valor entre 1 e 10");
        goto fim;
    salta2:
        puts("n*i: Produto multiplo de 50");
    fim:
        puts("Finalizado!");
}