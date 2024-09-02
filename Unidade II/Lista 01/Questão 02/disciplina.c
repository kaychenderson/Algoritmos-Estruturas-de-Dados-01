#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disciplina.h"

// Implementação da função que cria uma disciplina
Disciplina* criarDisciplina(char nome[], int codigo) {
    Disciplina* novaDisciplina = (Disciplina*) malloc(sizeof(Disciplina));
    if (novaDisciplina != NULL) {
        strcpy(novaDisciplina->nome, nome);
        novaDisciplina->codigo = codigo;
    }
    return novaDisciplina;
}

// Implementação da função que exclui uma disciplina
void excluirDisciplina(Disciplina* disciplina) {
    free(disciplina);
}