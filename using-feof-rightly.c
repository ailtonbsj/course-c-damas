#include <stdio.h>
#include <stdlib.h>

void main(int argc, char* argv[]) {
	FILE *fp;
	int conta = 0;
	char val = 0;

	if(argc != 2){
		printf("Sintaxe:\n\n%s arquivo\n\n", argv[0]);
		exit(1);
	}

	if((fp = fopen(argv[1],"rb")) == NULL){
		printf("Impossivel abrir o arquivo %s\n", argv[1]);
		exit(1);
	}
	while((val = fgetc(fp)) != EOF){
		printf("%c\n", val);
		conta++;
	}
	fclose(fp);

	printf("Total de Caracteres: %d\n", conta);
}