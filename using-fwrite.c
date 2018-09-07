#include <stdio.h>
#include <stdlib.h>

void main() {
	FILE *fp;
	int i;
	unsigned char v[10];

	// Ler os a partir do Teclado
	for(i=0; i<10; i++) {
		printf("Introd. o %d-ésimo No: ", i+1);
		scanf("%hhu", &v[i]);
	}

	//Abrir o arquivo dados.dat
	fp = fopen("dados.dat", "wb");
	if(fp == NULL) {
		printf("Impossivel criar o arquivo %s\n", "dados.dat");
		exit(1);
	}

	if(fwrite(v, sizeof(unsigned char), 10, fp) != 10) {
		fprintf(stderr, "Nao foram escritos todos os elementos!\n");
		fclose(fp);
	}
}