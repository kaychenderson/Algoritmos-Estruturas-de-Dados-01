#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista* prox;
} Lista;

void lcirc_imprime(Lista* l) {
    if (l == NULL) return;
    Lista* p = l;
    do {
        printf("%d ", p->info);
        p = p->prox;
    } while (p != l);
    printf("\n");
}

Lista* lcirc_insere(Lista* l, int v) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = v;
    if (l == NULL) {
        novo->prox = novo; // Primeiro elemento
        return novo;
    }
    Lista* p = l;
    while (p->prox != l) p = p->prox;
    p->prox = novo;
    novo->prox = l;
    return l;
}

int main() {
    Lista* l = NULL;
    l = lcirc_insere(l, 10);
    l = lcirc_insere(l, 20);
    l = lcirc_insere(l, 30);
    
    printf("Lista circular: ");
    lcirc_imprime(l);

    return 0;
}