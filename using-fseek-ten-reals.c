#include <stdio.h>
#include <stdlib.h>

void main() {
    FILE *fp;
    int i, n;
    float v[10], x;

    // Ler os dados a partir do teclado
    
    for(i = 0; i < 10; i++) {
        printf("Introd. o %d-ésimo No real: ", i+1);
        scanf("%f", &v[i]);
    }

    // Abrir o arquivo reals.dat
    if((fp = fopen("reals.dat","w+b")) == NULL) {
        printf("Impossivel criar o arquivo %s\n", "dados.dat");
        exit(1);
    }

    if(fwrite(v, sizeof(float), 10, fp) != 10)
        fprintf(stderr, "Nao foram escritos todos os elementos");

    printf("\nQual a ordem do numero que pretende ver 1..10? ");
    scanf("%d", &n);

    // Mostrar o n-ésimo número
    fseek(fp, (long) (n-1)*sizeof(float), SEEK_SET);
    fread(&x, sizeof(float), 1, fp);

    printf("\nO %do valor introduzido foi %f\n", n, x);

    // Mostra o primeiro valor
    rewind(fp);
    fread(&x, sizeof(float), 1, fp);
    printf("O 1o valor introduzido foi %f\n", x);

    // Mostra o ultimo valor
    fseek(fp, -(long) sizeof(float), SEEK_END);
    fread(&x, sizeof(float), 1, fp);
    printf("O ultimo valor introduzido foi %f\n", x);

    fclose(fp);
}