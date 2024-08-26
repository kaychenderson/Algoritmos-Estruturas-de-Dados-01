#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno {
    int mat;
    char nome[50];
    float media;
};

Aluno* criarAluno(int mat, char nome[], float media) {
    Aluno* aluno = (Aluno*) malloc(sizeof(Aluno));
    if (aluno == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    aluno->mat = mat;
    aluno->media = media;
    strcpy(aluno->nome, nome);
    return aluno;
}

void salvarAlunoEmArquivo(char nome_arquivo[], Aluno* aluno) {
    FILE *arq = fopen(nome_arquivo, "a");
    if (arq == NULL) {
        printf("Não foi possível abrir o arquivo!\n");
        exit(1);
    }
    fprintf(arq, "%d\t%s\t%.2f\n", aluno->mat, aluno->nome, aluno->media);
    fclose(arq);
}

void exibirAlunos(char nome_arquivo[]) {
    Aluno aluno;
    int count = 1;
    FILE *arq = fopen(nome_arquivo, "r");
    if (arq == NULL) {
        printf("Não foi possível abrir o arquivo!\n");
        return;
    }
    
    printf("Alunos cadastrados:\n");
    while (fscanf(arq, "%d\t%s\t%f", &aluno.mat, aluno.nome, &aluno.media) == 3) {
        printf("Aluno %d: Matricula: %d, Nome: %s, Media: %.2f\n", count, aluno.mat, aluno.nome, aluno.media);
        count++;
    }
    fclose(arq);
}