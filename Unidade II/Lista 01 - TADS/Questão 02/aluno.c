#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

// Implementação da função que cria um aluno
Aluno* criarAluno(char nome[], int matricula) {
    Aluno* aluno = (Aluno*) malloc(sizeof(Aluno));
    if (aluno != NULL) {
        strcpy(aluno->nome, nome);
        aluno->matricula = matricula;
        aluno->num_disciplinas = 0;
    }
    return aluno;
}

// Implementação da função que matricula um aluno em uma disciplina
void matricularAlunoDisciplina(Aluno* aluno, Disciplina* disciplina) {
    if (aluno->num_disciplinas < 10) {
        aluno->disciplinas[aluno->num_disciplinas] = disciplina;
        aluno->num_disciplinas++;
    } else {
        printf("Número máximo de disciplinas atingido!\n");
    }
}

// Implementação da função que exclui um aluno
void excluirAluno(Aluno* aluno) {
    free(aluno);
}