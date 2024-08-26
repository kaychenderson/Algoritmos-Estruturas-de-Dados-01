#ifndef ALUNO_H
#define ALUNO_H

#include "disciplina.h"

typedef struct {
    char nome[100];
    int matricula;
    Disciplina* disciplinas[10];
    int num_disciplinas;
} Aluno;

// Função que cria um aluno
Aluno* cria_aluno(char nome[], int matricula);

// Função que matricula um aluno em uma disciplina
void matricula_disciplina(Aluno* aluno, Disciplina* disciplina);

// Função que exclui um aluno
void exclui_aluno(Aluno* aluno);

#endif