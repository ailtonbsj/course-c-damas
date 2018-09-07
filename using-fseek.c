#include <stdio.h>
#include <stdlib.h>

void main(int argc, char* argv[]) {
	FILE *fp;

	if (argc != 2) {
		printf("Sintaxe:\n\n%s arquivo\n\n", argv[0]);
		exit(1);
	}

	if ((fp = fopen(argv[1],"rb")) == NULL) {
		printf("Impossivel abrir o arquivo %s\n", argv[1]);
		exit(2);
	}

	// Ir para o fim do arquivo
	fseek(fp, 0L, SEEK_END);
	printf("Dim. do arquivo %ld\n", ftell(fp));
	fclose(fp);
}