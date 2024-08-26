#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

// Implementação da função que cria um aluno
Aluno* cria_aluno(char nome[], int matricula) {
    Aluno* novo_aluno = (Aluno*) malloc(sizeof(Aluno));
    if (novo_aluno != NULL) {
        strcpy(novo_aluno->nome, nome);
        novo_aluno->matricula = matricula;
        novo_aluno->num_disciplinas = 0;
    }
    return novo_aluno;
}

// Implementação da função que matricula um aluno em uma disciplina
void matricula_disciplina(Aluno* aluno, Disciplina* disciplina) {
    if (aluno->num_disciplinas < 10) {
        aluno->disciplinas[aluno->num_disciplinas] = disciplina;
        aluno->num_disciplinas++;
    } else {
        printf("Número máximo de disciplinas atingido!\n");
    }
}

// Implementação da função que exclui um aluno
void exclui_aluno(Aluno* aluno) {
    free(aluno);
}