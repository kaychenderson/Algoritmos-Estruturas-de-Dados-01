#include <stdio.h>
#include <stdlib.h>

typedef struct lista2 {
    int info;
    struct lista2* prox;
    struct lista2* ant;
} Lista2;

void l2circ_imprime_rev(Lista2* l) {
    if (l == NULL) return;
    Lista2* p = l->ant;  // Começa do último nó (anterior ao primeiro)
    do {
        printf("%d ", p->info);
        p = p->ant;
    } while (p != l->ant);
    printf("\n");
}

Lista2* l2circ_insere(Lista2* l, int v) {
    Lista2* novo = (Lista2*) malloc(sizeof(Lista2));
    novo->info = v;
    if (l == NULL) {
        novo->prox = novo;
        novo->ant = novo;
        return novo;
    }
    Lista2* ultimo = l->ant;
    ultimo->prox = novo;
    novo->ant = ultimo;
    novo->prox = l;
    l->ant = novo;
    return l;
}

int main() {
    Lista2* l = NULL;
    l = l2circ_insere(l, 10);
    l = l2circ_insere(l, 20);
    l = l2circ_insere(l, 30);
    
    printf("Lista circular duplamente encadeada em ordem reversa: ");
    l2circ_imprime_rev(l);

    return 0;
}