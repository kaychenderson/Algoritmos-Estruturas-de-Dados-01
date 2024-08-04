#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

struct aluno{
    char nome[50];
    int idade;
    int matricula;
};

Aluno * aloca_aluno (){
    Aluno * aluno = (Aluno*)malloc(sizeof(Aluno));
    if(aluno == NULL){
        printf("No memory!\n");
        exit(1);
    } else{
        printf("Aluno alocado!\n");
    }
    return aluno;
}

void preenche(Aluno *aluno){
    printf("Informe o nome: \n");
    scanf(" %[^\n]", aluno->nome);
    printf("Informe a idade: \n");
    scanf("%d", &aluno->idade);
    printf("Informe a matricula: \n");
    scanf("%d", &aluno->matricula);
}

void imprime(Aluno *aluno){
    printf("Nome: %s \n", aluno->nome);
    printf("Idade: %d \n", aluno->idade);
    printf("Matricula: %d \n", aluno->matricula);
}

//gcc -c aluno.c
//gcc -c main.c
//gcc -o main.exe aluno.o main.o
//gcc main.c -o main
//./main