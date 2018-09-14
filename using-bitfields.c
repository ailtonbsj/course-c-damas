#include <stdio.h>
#include <string.h>

struct Pessoa {
    char nome[30];
    int idade;
    unsigned sexo : 1;
    unsigned estCivil : 2; 
};

enum sexo { FEMININO, MASCULINO };
enum estCivil { SOLTEIRO, CASADO, VIUVO, DIVORCIADO };

void main() {
    struct Pessoa p;

    strcpy(p.nome, "Samad o Terrivel");
    p.idade = 32;
    p.sexo = MASCULINO;
    p.estCivil = DIVORCIADO;

    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Sexo: %s\n", 
        p.sexo == 0 ? "Feminino": "Masculino");
    printf("Estado Civil: ");
    switch(p.estCivil) {
        case 0: puts("Solteiro"); break;
        case 1: puts("Casado"); break;
        case 2: puts("Viuvo"); break;
        case 3: puts("Divorciado"); break;
    }
}