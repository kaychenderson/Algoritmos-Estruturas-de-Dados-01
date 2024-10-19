#include <stdio.h>
#include <stdlib.h>
#include "lista2.h"

struct lista2 {
    int info;
    Lista2* prox;
    Lista2* ant;
};

Lista2* lst2_cria(void) {
    return NULL;  // Lista inicialmente vazia
}

void lst2_libera(Lista2* l) {
    Lista2* p = l;
    while (p != NULL) {
        Lista2* t = p->prox;
        free(p);
        p = t;
    }
}

Lista2* lst2_insere(Lista2* l, int v) {
    Lista2* novo = (Lista2*) malloc(sizeof(Lista2));
    if (!novo) exit(1); // Falta de memória
    novo->info = v;
    novo->prox = l;
    novo->ant = NULL;
    if (l != NULL) l->ant = novo;
    return novo;
}

Lista2* lst2_retira(Lista2* l, int v) {
    Lista2* p = l;
    while (p != NULL && p->info != v) {
        p = p->prox;
    }
    if (p == NULL) return l;  // Elemento não encontrado
    if (p->ant != NULL) p->ant->prox = p->prox;
    else l = p->prox;  // Remove o primeiro elemento
    if (p->prox != NULL) p->prox->ant = p->ant;
    free(p);
    return l;
}

int lst2_vazia(Lista2* l) {
    return (l == NULL);
}

Lista2* lst2_busca(Lista2* l, int v) {
    Lista2* p = l;
    while (p != NULL && p->info != v) {
        p = p->prox;
    }
    return p;  // Retorna NULL se não encontrar
}

void lst2_imprime(Lista2* l) {
    Lista2* p;
    for (p = l; p != NULL; p = p->prox) {
        printf("%d ", p->info);
    }
    printf("\n");
}