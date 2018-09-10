#include <stdio.h>

typedef struct { int dia, mes, ano; } Data;

typedef struct pessoa {
    char nome[100];
    int idade;
    float salario;
    Data nasc;
} Pessoa;

void ler (Pessoa *ptr) {
    printf("Qual o Nome: ");
    // fgets((*ptr).nome, sizeof((*ptr).nome), stdin);
    fgets(ptr->nome, sizeof(ptr->nome), stdin);
    printf("Qual a Idade: ");
    // scanf("%d", &(*ptr).idade);
    scanf("%d", &ptr->idade);
    printf("Qual o Salario: ");
    scanf("%f", &ptr->salario);
    printf("Qual a Data de Nsc.: ");
    scanf("%d %d %d", 
        &ptr->nasc.dia, &ptr->nasc.mes, &ptr->nasc.ano);
}

void mostrar (Pessoa x) {
    printf("Nome     : %s", x.nome);
    printf("Idade    : %d\n", x.idade);
    printf("Salário  : %.2f\n", x.salario);
    printf("Dt. Nasc : %d/%d/%d\n", 
        x.nasc.dia, x.nasc.mes,x.nasc.ano);
}

void main () {
    Pessoa p = {"Carlos\n", 23, 12345.67, {23,5,1954}};
    mostrar(p);
    puts("\n");
    ler(&p);
    puts("\n");
    mostrar(p);
}