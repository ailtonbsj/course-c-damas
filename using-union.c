#include <stdio.h>

struct Est {
	char c;
	int n;
	float x;
};

union Uni {
	char c;
	int n;
	float x;
};

void main() {
	printf("Dimensao da Estrutura: %ld\n", sizeof(struct Est));
	printf("Dimensao da Uniao: %ld\n", sizeof(union Uni));

	union Uni uniao;
	uniao.x = 12345.6;
	puts("Valores Iniciais");
	printf(" '%c' %d %7.2f\n", uniao.c, uniao.n, uniao.x);
	puts("\nVou alterar apenas o int");
	uniao.n = 2500;
	printf(" '%c' %d %7.2f\n", uniao.c, uniao.n, uniao.x);
}