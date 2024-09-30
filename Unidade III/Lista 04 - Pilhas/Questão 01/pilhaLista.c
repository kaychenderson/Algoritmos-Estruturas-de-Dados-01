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

// Função para criar a pilha
Pilha* pilha_cria(void) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

// Função para empurrar (push) um valor na pilha
void pilha_push(Pilha* p, float v) {
    struct no* novo = (struct no*) malloc(sizeof(struct no));
    novo->info = v;
    novo->prox = p->topo;
    p->topo = novo;
}

// Função para retirar (pop) o valor do topo da pilha
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

// Função para verificar se a pilha está vazia
int pilha_vazia(Pilha* p) {
    return p->topo == NULL;
}

// Função para liberar a memória da pilha
void pilha_libera(Pilha* p) {
    struct no* t = p->topo;
    while (t != NULL) {
        struct no* prox = t->prox;
        free(t);
        t = prox;
    }
    free(p);
}
