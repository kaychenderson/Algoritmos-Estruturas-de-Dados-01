#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

#define TAM 10

struct pilha {
    float *dados;
    int topo;
    int capacidade;
};

Pilha* pilha_cria(void) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->dados = (float*) malloc(TAM * sizeof(float));
    p->topo = 0;
    p->capacidade = TAM;
    return p;
}

void pilha_push(Pilha* p, float v) {
    if (p->topo == p->capacidade) {
        p->capacidade *= 2;
        p->dados = (float*) realloc(p->dados, p->capacidade * sizeof(float));
    }
    p->dados[p->topo++] = v;
}

float pilha_pop(Pilha* p) {
    if (pilha_vazia(p)) {
        printf("Erro: pilha vazia!\n");
        exit(1);
    }
    return p->dados[--p->topo];
}

int pilha_vazia(Pilha* p) {
    return p->topo == 0;
}

void pilha_libera(Pilha* p) {
    free(p->dados);
    free(p);
}