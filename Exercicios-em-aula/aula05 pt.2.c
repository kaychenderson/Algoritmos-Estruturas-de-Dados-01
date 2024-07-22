#include <stdio.h>

typedef union documentos {
    char cpf[12]; 
    char rg[12];
    char sus[12];
    char titulo[12];
    char passaporte[12];
} Documentos;

typedef struct aluno {
    char nome[20]; 
    int tipoDoc; 
    Documentos documento;
} Aluno;

void preenche(Aluno * aluno) {
    int opcaoDoc;
    printf("Informe o nome: \n");
    scanf(" %[^\n]", aluno->nome);
    printf("Informe um dos documentos disponíveis: \n");
    printf("1- CPF\n");
	printf("2- RG\n");
	printf("3- SUS\n");
	printf("4- Titulo de Eleitor\n");
	printf("5- Passaporte\n");
    scanf("%d", &opcaoDoc);

    aluno->tipoDoc = opcaoDoc;

    switch (opcaoDoc) {
        case 1:
            printf("Informe o CPF: \n");
            scanf(" %[^\n]", aluno->documento.cpf);
            break;
        case 2:
            printf("Informe o RG: \n");
            scanf(" %[^\n]", aluno->documento.rg);
            break;
        case 3:
            printf("Informe o SUS: \n");
            scanf(" %[^\n]", aluno->documento.sus);
            break;
        case 4:
            printf("Informe o Titulo de Eleitor: \n");
            scanf(" %[^\n]", aluno->documento.titulo);
            break;
        case 5:
            printf("Informe o Passaporte: \n");
            scanf(" %[^\n]", aluno->documento.passaporte);
            break;
        default:
            printf("Valor inválido! \n");
            break;
    }
}

void imprime(Aluno * aluno) {
    printf("Os dados informados foram: \n");
    printf("Nome: %s \n", aluno->nome);
    
    switch (aluno->tipoDoc) {
        case 1:
            printf("CPF: %s \n", aluno->documento.cpf);
            break;
        case 2:
            printf("RG: %s \n", aluno->documento.rg);
            break;
        case 3:
            printf("SUS: %s \n", aluno->documento.sus);
            break;
        case 4:
            printf("Titulo de Eleitor: %s \n", aluno->documento.titulo);
            break;
        case 5:
            printf("Passaporte: %s \n", aluno->documento.passaporte);
            break;
    }
}

int main(void) {
    Aluno aluno;

    preenche(&aluno);
    imprime(&aluno);

    return 0;
}