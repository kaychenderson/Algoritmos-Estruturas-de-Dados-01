#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct no {
    float info;
    struct no* prox;
};

struct pilha {
    struct no* topo;
};

Pilha* pilha_cria(void) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void pilha_push(Pilha* p, float v) {
    struct no* novo = (struct no*) malloc(sizeof(struct no));
    novo->info = v;
    novo->prox = p->topo;
    p->topo = novo;
}

float pilha_pop(Pilha* p) {
    if (pilha_vazia(p)) {
        printf("Erro: pilha vazia!\n");
        exit(1);
    }
    struct no* t = p->topo;
    float v = t->info;
    p->topo = t->prox;
    free(t);
    return v;
}

int pilha_vazia(Pilha* p) {
    return p->topo == NULL;
}

void pilha_libera(Pilha* p) {
    struct no* t = p->topo;
    while (t != NULL) {
        struct no* prox = t->prox;
        free(t);
        t = prox;
    }
    free(p);
}
