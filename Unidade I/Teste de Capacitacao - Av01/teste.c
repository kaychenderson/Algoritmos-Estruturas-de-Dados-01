#include <stdio.h>
#include <stdlib.h>

typedef union documento {
    char rg[15];
    char cpf[15];
    char sus[15];
    char passaporte[15];
} Documento;

typedef enum genero {
    MASCULINO = 1,
    FEMININO,
    NEUTRO,
    OUTRO
} Genero;

typedef struct pessoa {
    char nome[20];
    Documento documento;
    int idade;
    Genero genero;
    int tipoDoc; // 1 para RG, 2 para CPF, 3 para SUS, 4 para Passaporte
} Pessoa;

void preenche (Pessoa * pessoa) {
    printf("Informe o nome: \n");
    scanf(" %[^\n]s", pessoa->nome);

    printf("Informe o tipo de documento: (1- RG, 2- CPF, 3- SUS, 4- PASSAPORTE)\n");
    scanf("%d", &pessoa->tipoDoc);

    switch (pessoa->tipoDoc) {
        case 1:
            printf("Informe o RG: \n");
            scanf("%s", pessoa->documento.rg);
            break;
        case 2:
            printf("Informe o CPF: \n");
            scanf("%s", pessoa->documento.cpf);
            break;
        case 3:
            printf("Informe o SUS: \n");
            scanf("%s", pessoa->documento.sus);
            break;
        case 4:
            printf("Informe o Passaporte: \n");
            scanf("%s", pessoa->documento.passaporte);
            break;
        default:
            printf("Tipo de documento inválido.\n");
            break;
    }

    printf("Informe a idade: \n");
    scanf("%d", &pessoa->idade);

    printf("Informe o seu genero: (1- MASCULINO, 2- FEMININO, 3- NEUTRO, 4- OUTRO)\n");
    scanf("%d", (int *)&pessoa->genero);
}

void imprime (Pessoa * pessoa) {
    printf("Nome: %s \n", pessoa->nome);

    switch (pessoa->tipoDoc) {
        case 1:
            printf("Documento (RG): %s \n", pessoa->documento.rg);
            break;
        case 2:
            printf("Documento (CPF): %s \n", pessoa->documento.cpf);
            break;
        case 3:
            printf("Documento (SUS): %s \n", pessoa->documento.sus);
            break;
        case 4:
            printf("Documento (Passaporte): %s \n", pessoa->documento.passaporte);
            break;
        default:
            printf("Tipo de documento inválido.\n");
            break;
    }

    printf("Idade: %d \n", pessoa->idade);
    printf("Genero: %s \n", 
        pessoa->genero == MASCULINO ? "MASCULINO" :
        pessoa->genero == FEMININO ? "FEMININO" :
        pessoa->genero == NEUTRO ? "NEUTRO" : "OUTRO");
}

void atualiza (Pessoa * pessoa) {
    int nvIdade;
    printf("Informe a nova idade: \n");
    scanf("%d", &nvIdade);
    pessoa->idade = nvIdade;
}

int main(void) {
    
    Pessoa p;

    preenche(&p);
    imprime(&p);
    atualiza(&p);
    imprime(&p);

    return 0;
}