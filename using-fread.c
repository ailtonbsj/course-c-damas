#include <stdio.h>
#include <stdlib.h>

void main() {
	FILE *fp;
	unsigned char v[10];
	int i, n;

	//Abrir o arquivo dados.dat
	if( (fp = fopen("dados.dat", "rb")) == NULL ) {
		printf("Impossivel abrir o arquivo %s\n", "dados.dat");
		exit(1);
	}
	n = fread(v, sizeof(unsigned char), 10, fp);
	if( n != 10 )
		fprintf(stderr, "Foram lidos apenas %d Elementos\n", n);
	// Apresentar os dados ao usuario
	for (i = 0; i < n; i++) {
		printf("%2d No: %d\n", i+1, v[i]);
	}
	fclose(fp);
}