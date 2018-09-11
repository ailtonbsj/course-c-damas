#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct sPessoa {
	int idade;
	char nome[20+1];
	struct sPessoa *prox;
} Pessoa;

typedef Pessoa* Fila;

// Inicia uma Fila
void inic(Fila* fila) {
	*fila = NULL;
}

// Insere item na fila
void inserir(Fila* fila, int idade, char* nome) {
	if(*fila == NULL) {
		*fila = (Fila) malloc(sizeof(Pessoa));
		if (*fila == NULL) return;
		(*fila)->idade = idade;
		strcpy((*fila)->nome, nome);
		(**fila).prox = NULL;
	} else {
		inserir(&(**fila).prox, idade, nome);
	}
}

// Lista itens da fila
void listar(Fila fila) {
	if(fila == NULL) return; // Nao existem itens
	printf("%d %s\n", fila->idade, fila->nome);
	listar(fila->prox);
}

void apagar(Fila* fila) {
	Pessoa *tmp = *fila;

	if(*fila == NULL) return; // Nao existe item
	*fila = (*fila)->prox;
	free(tmp);
}

void main () {
	Fila f;
	inic(&f);
	puts("Iniciar:");
	listar(f);
	puts("Inserir:");
	inserir(&f, 10, "Tiago");
	inserir(&f, 20, "Luisa");
	inserir(&f, 30, "Ana");
	puts("Listar 3");
	listar(f);
	apagar(&f);
	puts("Listar 2");
	listar(f);
	apagar(&f);
	puts("Listar 1");
	listar(f);
	apagar(&f);
	puts("Listar Nada");
	listar(f);
}
