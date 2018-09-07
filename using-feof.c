#include <stdio.h>
#include <stdlib.h>

void main() {
	FILE *fp;
	int i = 0, valor, n;

	// Criar o arquivo lixo vazio
	if((fp = fopen("lixo","wb")) == NULL){
		printf("Impossivel criar o arquivo %s\n", "lixo");
		exit(1);
	}
	fclose(fp);

	// Abrir o arquivo
	if((fp = fopen("lixo","rb")) == NULL){
		printf("Impossivel abrir o arquivo o %s\n", "lixo");
		exit(1);
	}

	puts(feof(fp) ? "EOF" : "NOT EOF");

	// Tentar ler um caractere
	fgetc(fp);

	puts(feof(fp) ? "EOF" : "NOT EOF");

	fclose(fp);
}