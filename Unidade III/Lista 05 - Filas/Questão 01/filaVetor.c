#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 100

typedef struct fila {
    int inicio, fim, tamanho;
    float dados[TAM_MAX];
} Fila;

Fila* fila_cria(void) {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if (f != NULL) {
        f->inicio = 0;
        f->fim = 0;
        f->tamanho = 0;
    }
    return f;
}

void fila_insere(Fila* f, float v) {
    if (f->tamanho == TAM_MAX) {
        printf("Fila cheia!\n");
        exit(1);
    }
    f->dados[f->fim] = v;
    f->fim = (f->fim + 1) % TAM_MAX;
    f->tamanho++;
}

float fila_retira(Fila* f) {
    if (fila_vazia(f)) {
        printf("Fila vazia!\n");
        exit(1);
    }
    float v = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % TAM_MAX;
    f->tamanho--;
    return v;
}

int fila_vazia(Fila* f) {
    return f->tamanho == 0;
}

void fila_imprime(Fila* f) {
    if (fila_vazia(f)) {
        printf("Fila vazia!\n");
        return;
    }
    int i = f->inicio;
    for (int j = 0; j < f->tamanho; j++) {
        printf("%.2f ", f->dados[i]);
        i = (i + 1) % TAM_MAX;
    }
    printf("\n");
}

void fila_libera(Fila* f) {
    free(f);
}