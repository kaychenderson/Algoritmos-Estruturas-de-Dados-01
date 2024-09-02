#ifndef DISCIPLINA_H
#define DISCIPLINA_H

typedef struct {
    char nome[100];
    int codigo;
} Disciplina;

// Função que cria uma disciplina
Disciplina* criarDisciplina(char nome[], int codigo);

// Função que exclui uma disciplina
void excluirDisciplina(Disciplina* disciplina);

#endif