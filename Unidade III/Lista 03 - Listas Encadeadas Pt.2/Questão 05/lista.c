#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

typedef struct funcionario {
    char depto;
    int mat;
    char nome[81];
    float salario;
} Funcionario;

typedef struct lista_func {
    Funcionario func;
    struct lista_func* prox;
} ListaFunc;

float lstfunc_folha_pagto(ListaFunc* l, char depto) {
    float total_pagto = 0.0;
    ListaFunc* atual = l;

    while (atual != NULL) {
        if (atual->func.depto == depto) {
            total_pagto += atual->func.salario;  
        }
        atual = atual->prox;
    }

    return total_pagto;
}

ListaFunc* cria_no(Funcionario f) {
    ListaFunc* novo = (ListaFunc*)malloc(sizeof(ListaFunc));
    if (novo != NULL) {
        novo->func = f;
        novo->prox = NULL;
    }
    return novo;
}

ListaFunc* insere_funcionario(ListaFunc* l, Funcionario f) {
    ListaFunc* novo = cria_no(f);
    novo->prox = l;
    return novo;
}

Funcionario cria_funcionario(char depto, int mat, char nome[], float salario) {
    Funcionario f;
    f.depto = depto;
    f.mat = mat;
    strcpy(f.nome, nome);
    f.salario = salario;
    return f;
}

void exibe_funcionarios(ListaFunc* l) {
    ListaFunc* atual = l;
    while (atual != NULL) {
        printf("Nome: %s, Departamento: %c, Matrícula: %d, Salário: %.2f\n", atual->func.nome, atual->func.depto, atual->func.mat, atual->func.salario);
        atual = atual->prox;
    }
}
