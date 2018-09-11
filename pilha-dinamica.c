#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct sNumero {
    int valor;
    struct sNumero *prox;
} Numero;

// Inicia uma pilha
void iniciar(Numero** pilha) {
    *pilha = NULL;
}

// Insere um item
void push(Numero** pilha, int num) {
    Numero* tmp;
    tmp = (Numero*) malloc(sizeof(Numero));
    if(tmp == NULL) return;
    tmp->valor = num;
    tmp->prox = *pilha;
    *pilha = tmp;
}

// Testa se esta vazia
int empty (Numero* pilha) {
    return (pilha == NULL);
}

// Apaga um item
void pop (Numero** pilha) {
    Numero *tmp = *pilha;
    if(empty(*pilha)) return;
    *pilha = (*pilha)->prox;
    free(tmp);
}

// Lista todos os itens
void print (Numero* pilha) {
    if(empty(pilha)) return;
    printf("%d \n", pilha->valor);
    print(pilha->prox);
}

// Devolve item do topo da pilha
int top(Numero *pilha) {
    if(empty(pilha)) return -1;
    return pilha->valor;
}

void main() {
    Numero* p;
    iniciar(&p);
    printf("%s esta vazia\n", empty(p) ? "": "Nao" );
    print(p);
    puts("push: 10");
    push(&p, 10);
    puts("push: 20");
    push(&p, 20);
    puts("push: 30");
    push(&p, 30);
    printf("%s esta vazia\n", empty(p) ? "": "Nao" );
    print(p);
    puts("pop:");
    pop(&p);
    print(p);
    puts("pop:");
    pop(&p);
    print(p);
    puts("pop:");
    pop(&p);
    print(p);
    printf("%s esta vazia\n", empty(p) ? "": "Nao" );

}
