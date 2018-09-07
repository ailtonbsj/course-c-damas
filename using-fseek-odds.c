#include <stdio.h>
#include <stdlib.h>

void main() {
    FILE *fp;
    float x;

    // Abre o arquivo reals.dat
    if( (fp = fopen("reals.dat", "rb")) == NULL ){
        printf("Impossivel abrir o arquivo %s\n", "reals.dat");
        exit(1);
    }

    while(1) {
        if( fread(&x, sizeof(float), 1, fp) == 0 ) break;
        printf("%f\n", x);
        fseek(fp, sizeof(float), SEEK_CUR);
    }
    fclose(fp);
}