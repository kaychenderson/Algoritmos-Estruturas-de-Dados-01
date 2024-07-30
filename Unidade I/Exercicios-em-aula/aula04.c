#include <stdio.h>
#include <stdlib.h>

#define QTD_ALUNOS 5

typedef struct aluno{
    int matricula;
    int idade;
    char nome[20];
} Aluno;

void preenche(Aluno *aluno, int tamanho){
    int count;
    for(count = 0; count < tamanho; count++){
        printf("Informe o nome: \t");
        scanf(" %[^\n]", aluno[count].nome); 
        printf("Informe a matricula: \t");
        scanf("%d", &aluno[count].matricula);
        printf("Informe a idade: \t");
        scanf("%d", &aluno[count].idade);
    }
}

int main(void){

    int novoTamanho;
    Aluno *aluno = (Aluno *) malloc(QTD_ALUNOS * sizeof(Aluno));
    if(aluno == NULL){
        printf("No memory RAM\n");
        exit(1);
    }

    preenche(aluno, QTD_ALUNOS);

    printf("Informe o novo tamanho: \t");
    scanf("%d", &novoTamanho);

    aluno = (Aluno *) realloc(aluno, novoTamanho * sizeof(Aluno));
    if(aluno == NULL){
        printf("Falha na Realocação \n");
        exit(1);
    } else {
        printf("Vetor realocado com sucesso! \n");
    }

    preenche(aluno, novoTamanho);

    free(aluno); 

    return 0;
}