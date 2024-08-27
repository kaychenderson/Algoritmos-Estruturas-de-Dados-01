#ifndef DISCIPLINA_H
#define DISCIPLINA_H

typedef struct {
    char nome[100];
    int codigo;
} Disciplina;

// Função que cria uma disciplina
Disciplina* cria_disciplina(char nome[], int codigo);

// Função que exclui uma disciplina
void exclui_disciplina(Disciplina* disciplina);

#endif