#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    float info;
    struct no* prox;
} No;

typedef struct fila {
    No* inicio;
    No* fim;
} Fila;

Fila* fila_cria(void) {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
    }
    return f;
}

void fila_insere(Fila* f, float v) {
    No* n = (No*) malloc(sizeof(No));
    if (n == NULL) {
        printf("Memória insuficiente!\n");
        exit(1);
    }
    n->info = v;
    n->prox = NULL;
    if (f->fim != NULL) {
        f->fim->prox = n;
    } else {
        f->inicio = n;
    }
    f->fim = n;
}

float fila_retira(Fila* f) {
    if (fila_vazia(f)) {
        printf("Fila vazia!\n");
        exit(1);
    }
    No* t = f->inicio;
    float v = t->info;
    f->inicio = t->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(t);
    return v;
}

int fila_vazia(Fila* f) {
    return f->inicio == NULL;
}

void fila_imprime(Fila* f) {
    No* t;
    for (t = f->inicio; t != NULL; t = t->prox) {
        printf("%.2f ", t->info);
    }
    printf("\n");
}

void fila_libera(Fila* f) {
    No* t = f->inicio;
    while (t != NULL) {
        No* aux = t->prox;
        free(t);
        t = aux;
    }
    free(f);
}
