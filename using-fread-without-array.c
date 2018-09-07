#include <stdio.h>
#include <stdlib.h>

void main() {
	FILE *fp;
	unsigned char valor;
	int i, n;

	//Abrir o arquivo dados.dat
	if( (fp = fopen("dados.dat", "rb")) == NULL ) {
		printf("Impossivel abrir o arquivo %s\n", "dados.dat");
		exit(1);
	}

	while( fread(&valor, sizeof(unsigned char), 1, fp) )
		printf("%2d No: %d\n", ++i, valor);

	fclose(fp);
}