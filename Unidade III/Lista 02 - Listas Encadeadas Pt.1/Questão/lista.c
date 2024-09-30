#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* cria_lista(void) {
    return NULL;
}

Lista* insere_inicio(Lista* l, int valor) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = l;
    return novo;
}

int maiores(Lista* l, int n) {
    int count = 0;
    while (l != NULL) {
        if (l->info > n) {
            count++;
        }
        l = l->prox;
    }
    return count;
}

Lista* ultimo(Lista* l) {
    if (l == NULL) return NULL;
    while (l->prox != NULL) {
        l = l->prox;
    }
    return l;
}

Lista* concatena(Lista* l1, Lista* l2) {
    if (l1 == NULL) return l2;
    Lista* u = ultimo(l1);
    u->prox = l2;
    return l1;
}

Lista* retira_n(Lista* l, int n) {
    Lista* anterior = NULL;
    Lista* p = l;

    while (p != NULL) {
        if (p->info == n) {
            if (anterior == NULL) {
                l = p->prox;  
            } else {
                anterior->prox = p->prox;
            }
            Lista* t = p;
            p = p->prox;
            free(t);  
        } else {
            anterior = p;
            p = p->prox;
        }
    }
    return l;
}

void imprime_lista(Lista* l) {
    Lista* p;
    for (p = l; p != NULL; p = p->prox) {
        printf("%d -> ", p->info);
    }
    printf("NULL\n");
}

void libera_lista(Lista* l) {
    Lista* p = l;
    while (p != NULL) {
        Lista* t = p->prox;
        free(p);
        p = t;
    }
}
