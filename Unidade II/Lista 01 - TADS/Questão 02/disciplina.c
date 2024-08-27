#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disciplina.h"

// Implementação da função que cria uma disciplina
Disciplina* cria_disciplina(char nome[], int codigo) {
    Disciplina* nova_disciplina = (Disciplina*) malloc(sizeof(Disciplina));
    if (nova_disciplina != NULL) {
        strcpy(nova_disciplina->nome, nome);
        nova_disciplina->codigo = codigo;
    }
    return nova_disciplina;
}

// Implementação da função que exclui uma disciplina
void exclui_disciplina(Disciplina* disciplina) {
    free(disciplina);
}