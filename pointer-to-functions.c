#include <stdio.h>

int quadrado(int x) {
    return x*x;
}

int dobro(int x) {
    return 2*x;
}

int cubo(int x) {
    return quadrado(x)*x;
}

// Funcao como parametro um callback
void imprimeEspecial(int (*funcao)(int), int n) {
    printf("<<<|%d|>>>\n", (*funcao)(n));
}

void main() {
    imprimeEspecial(quadrado, 3);
    imprimeEspecial(dobro, 10);
    imprimeEspecial(cubo, 5);

    int (*f)(int);
    f = quadrado;
    imprimeEspecial(f, 4);
    f = dobro;
    imprimeEspecial(f, 11);
    f = cubo;
    imprimeEspecial(f, 6);
}