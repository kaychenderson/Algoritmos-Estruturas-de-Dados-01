#include <stdio.h>
#include <stdlib.h>
#include "lista_circ.h"

No* inserir_no_inicio(No* lista, int valor) {
    No* NovoNo = (No*) malloc(sizeof(No));
    if (NovoNo == NULL) {
        exit(1);
    }
    NovoNo->valor = valor;

    if (lista == NULL) {
        NovoNo->prox = NovoNo; 
        return NovoNo;
    }

    No* atual = lista;
    while (atual->prox != lista) {
        atual = atual->prox;
    }

    NovoNo->prox = lista;
    atual->prox = NovoNo;

    return NovoNo; 
}

No* inserir_no_fim(No* lista, int valor) {
    No* NovoNo = (No*) malloc(sizeof(No));
    if (NovoNo == NULL) {
        exit(1);
    }
    NovoNo->valor = valor;

    if (lista == NULL) {
        NovoNo->prox = NovoNo; 
        return NovoNo;
    }

    No* atual = lista;
    while (atual->prox != lista) {
        atual = atual->prox;
    }

    atual->prox = NovoNo;
    NovoNo->prox = lista;

    return lista; 
}

void exibir_lista(No* lista) {
    if (lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No* atual = lista;
    do {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    } while (atual != lista);
    printf("(volta ao início)\n");
}
