#include <stdio.h>
#include <stdlib.h>

void main(int argc, char* argv[]) {
	FILE *fp;
	// long int nBytes = 0;

	if(argc != 2) {
		printf("Sintaxe: \n\n%s arquivo\n\n", argv[0]);
		exit(1);
	}

	if((fp = fopen(argv[1],"rb")) == NULL) {
		printf("Impossivel abrir o arquivo %s\n", argv[1]);
		exit(2);
	}

	// Acesso sequencial byte a byte
	// while(fgetc(fp) != EOF) nBytes++;
	// fclose(fp);
	while(fgetc(fp) != EOF);

	//printf("Dim. do arquivo: %ld\n", nBytes);
	printf("Dim. do arquivo: %ld\n", ftell(fp));
}