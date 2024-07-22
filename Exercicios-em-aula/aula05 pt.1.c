#include <stdio.h>

typedef union documentos {
    char cpf[12]; 
    char rg[12];
} Documentos;

typedef struct pessoa {
    char nome[20]; 
    int tipoDoc; 
    Documentos documento;
} Pessoa;

void preenche(Pessoa * pessoa) {
    int opcaoDoc;
    printf("Informe o nome: \n");
    scanf(" %[^\n]", pessoa->nome);
    printf("Informe um dos documentos disponíveis: \n");
    printf("1- CPF\n");
    printf("2- RG\n");
    scanf("%d", &opcaoDoc);

    pessoa->tipoDoc = opcaoDoc;

    switch (opcaoDoc) {
        case 1:
            printf("Informe o CPF: \n");
            scanf(" %[^\n]", pessoa->documento.cpf);
            break;
        case 2:
            printf("Informe o RG: \n");
            scanf(" %[^\n]", pessoa->documento.rg);
            break;
        default:
            printf("Valor inválido! \n");
            break;
    }
}

void imprime(Pessoa * pessoa) {
    printf("Os dados informados foram: \n");
    printf("Nome: %s \n", pessoa->nome);
    
    switch (pessoa->tipoDoc) {
        case 1:
            printf("CPF: %s \n", pessoa->documento.cpf);
            break;
        case 2:
            printf("RG: %s \n", pessoa->documento.rg);
            break;
    }
}

int main(void) {
    Pessoa pessoa;

    preenche(&pessoa);
    imprime(&pessoa);

    return 0;
}