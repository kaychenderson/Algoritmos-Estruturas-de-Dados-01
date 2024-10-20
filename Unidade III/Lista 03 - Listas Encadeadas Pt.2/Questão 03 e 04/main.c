#include <stdio.h>
#include <stdlib.h>

typedef struct lista2 {
    int info;
    struct lista2* prox;
    struct lista2* ant;
} Lista2;

// Função para imprimir a lista em ordem reversa (Questão 3)
void l2circ_imprime_rev(Lista2* l) {
    if (l == NULL) return;
    Lista2* p = l->ant; 
    do {
        printf("%d ", p->info);
        p = p->ant;
    } while (p != l->ant);
    printf("\n");
}

// Função para inserir um elemento na lista circular duplamente encadeada (Questão 4)
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

// Função para remover um elemento da lista circular duplamente encadeada (Questão 4)
Lista2* l2circ_retira(Lista2* l, int v) {
    if (l == NULL) return NULL;
    
    Lista2* p = l;

    do {
        if (p->info == v) {
            if (p->prox == p) { 
                free(p);
                return NULL;
            }
            p->ant->prox = p->prox;
            p->prox->ant = p->ant;
            if (p == l) 
                l = p->prox;
            free(p);
            return l;
        }
        p = p->prox;
    } while (p != l);
    
    return l; 
}

int main() {
    Lista2* l = NULL;

    l = l2circ_insere(l, 10);
    l = l2circ_insere(l, 20);
    l = l2circ_insere(l, 30);

    printf("Lista circular duplamente encadeada em ordem reversa: ");
    l2circ_imprime_rev(l);

    l = l2circ_retira(l, 20);

    printf("Lista após remoção: ");
    l2circ_imprime_rev(l);

    return 0;
}