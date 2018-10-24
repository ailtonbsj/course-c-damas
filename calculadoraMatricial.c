/*
* Autor: ailtonbsj
* OS: GNU/Linux 4.15
*/

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

#define clearTerminal() printf("\033[H\033[J")

void clearBufferKey() {
    fflush(stdin); // for win
    __fpurge(stdin); //for unix
}

enum Escolha {
    SOMAR = 1,
    SUBTRAIR,
    MULTIPLICAR_ESCALAR,
    MULTIPLICAR,
    SAIR
};

int *matrizA, *matrizB, *matrizC;
int linA, colA, linB, colB, linC, colC;

int menuPrincipal () {
    int escolha;
    clearTerminal();
    printf("########### CALCULADORA DE MATRIZES ###########\n\n");
    printf("Escolha uma operacao:\n\n\n");
    printf("1. Somar duas matrizes\n");
    printf("2. Subtrair duas matrizes\n");
    printf("3. Multiplicar matriz por escalar\n");
    printf("4. Multiplicar duas Matrizes\n");
    printf("5. Sair\n\n");
    printf("Sua escolha: ");
    clearBufferKey();
    scanf("%d",&escolha);
    return escolha;
}

void alerta (char* text) {
    clearTerminal();
    printf("########### CALCULADORA DE MATRIZES ( ALERTA ) ###########\n\n");
    printf(" %s\n\n\n", text);
    printf("Pressione qualquer tecla para continuar...");
    clearBufferKey();
    getchar();
}

void obterMatriz (int lins, int cols, int *matriz) {
    int i, j;
    for(j = 0; j < lins; j++){
        for(i = 0; i < cols; i++){
            printf("Digite o valor da posicao (%d,%d): ", i, j);
            scanf("%d", &matriz[j*cols + i]);
        }
    } 
}

void desenharMatriz (int lins, int cols, int* matriz) {
    int i, j;
    for(j = 0; j < lins; j++){
        printf(" │ ");
        for(i = 0; i < cols; i++){
            printf("%5d", matriz[j*cols + i]);
        }
        printf(" │ \n");
    }
}

void obterLinsECols (int* lins, int* cols, char* id) {
    clearTerminal();
    printf("########### CALCULADORA DE MATRIZES ###########\n\n");
    printf("Informe as dimensoes da matriz %s:\n\n\n", id);
    printf("Digite a quantidade de linhas: ");
    scanf("%d", lins);
    printf("Digite a quantidade de colunas: ");
    scanf("%d", cols);
    printf("\n\n");
}

void obterEDesenharMatriz (int lins, int cols, int *matriz, char* id) {
    obterMatriz(lins, cols, matriz);
    printf("\n\nRepresentacao da matriz %s:\n\n", id);
    desenharMatriz(lins, cols, matriz);
    printf("\nPressione qualquer tecla para continuar...");
    clearBufferKey();
    getchar();
}

void somarMatriz (char operador) {
    int i,j;
    obterLinsECols(&linA, &colA, "A");
    obterEDesenharMatriz(linA, colA, matrizA, "A");
    obterLinsECols(&linB, &colB, "B");
    if( (linA == linB) && (colA  == colB) ) {
        obterEDesenharMatriz(linB, colB, matrizB, "B");
        for(j = 0; j < colA; j++){
            for(i = 0; i < linA; i++){
                matrizC[j*linA + i] = (operador == '+') ?
                matrizA[j*linA + i] + matrizB[j*linA + i]:
                matrizA[j*linA + i] - matrizB[j*linA + i];
            }
        }
        clearTerminal();
        printf("########### CALCULADORA DE MATRIZES ###########\n\n");
        desenharMatriz(linA, colA, matrizA);
        printf("\n %c\n\n", operador);
        desenharMatriz(linB, colB, matrizB);
        printf("\n =\n\n");
        desenharMatriz(linA, colA, matrizC);
    } else alerta("Operacao invalida! Matrizes devem ter dimensoes iguais!");
}

void multiplicarMatrizPorEscalar() {
    int i,j, escalar;
    obterLinsECols(&linA, &colA, "A");
    obterEDesenharMatriz(linA, colA, matrizA, "A");
    clearTerminal();
    printf("########### CALCULADORA DE MATRIZES ###########\n\n");
    printf("Digite o valor do escalar: ");
    scanf("%d", &escalar);
    printf("\n\n");
    printf("\nPressione qualquer tecla para continuar...");
    clearBufferKey();
    getchar();
    for(j = 0; j < colA; j++){
        for(i = 0; i < linA; i++){
            matrizC[j*linA + i] = matrizA[j*linA + i] * escalar;
        }
    }
    clearTerminal();
    printf("########### CALCULADORA DE MATRIZES ###########\n\n");
    desenharMatriz(linA, colA, matrizA);
    printf("\n *\n\n %d\n", escalar);
    printf("\n =\n\n");
    desenharMatriz(linA, colA, matrizC);
}
void multiplicarMatrizes() {
    int i,j,k;
    obterLinsECols(&linA, &colA, "A");
    obterEDesenharMatriz(linA, colA, matrizA, "A");
    obterLinsECols(&linB, &colB, "B");
    if( colA == linB ){

        obterEDesenharMatriz(linB, colB, matrizB, "B");
        for(j = 0; j < linA; j++){
            printf(" │ ");
            for(i = 0; i < colB; i++){

                int res = 0;

                for(k = 0; k < colA; k++){
                    printf("+%d*%d",matrizA[j*colA + k], matrizB[k*colB + i]);
                    res += (matrizA[j*colA + k] * matrizB[k*colB + i]);
                }
                printf("  ->  ");
                //printf("%2d (%d,%d)    ",res,i, j*colA);
                matrizC[j*colB + i] = res;
                
                // matrizC[j*linA + i] = (operador == '+') ?
                // matrizA[j*linA + i] + matrizB[j*linA + i]:
                // matrizA[j*linA + i] - matrizB[j*linA + i];
            }
            printf(" │\n");
        }
        clearTerminal();
        printf("########### CALCULADORA DE MATRIZES ###########\n\n");
        desenharMatriz(linA, colA, matrizA);
        printf("\n *\n\n");
        desenharMatriz(linB, colB, matrizB);
        printf("\n =\n\n");
        desenharMatriz(linA, colB, matrizC);
    } else alerta("Operacao invalida!\n Dimensao de Coluna em A tem que ser igual a linhas em B!");
}

void roteador () {
    int escolha;
    escolha = menuPrincipal();
    switch(escolha) {
        case SOMAR:
            somarMatriz('+');
            break;
        case SUBTRAIR:
            somarMatriz('-');
            break;
        case MULTIPLICAR_ESCALAR:
            multiplicarMatrizPorEscalar();
            break;
        case MULTIPLICAR:
            multiplicarMatrizes();
            break;
        case SAIR:
            exit(0);
        default:
            alerta("Opcao Invalida!");
            roteador ();
    }
}

int main () {
    matrizA = (int *) malloc(10*10*sizeof(int));
    matrizB = (int *) malloc(10*10*sizeof(int));
    matrizC = (int *) malloc(10*10*sizeof(int));
    roteador();
    
    return 0;
}