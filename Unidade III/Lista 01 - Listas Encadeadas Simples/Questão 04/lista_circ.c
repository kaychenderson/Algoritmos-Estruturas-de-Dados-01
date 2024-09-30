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

No* buscar(No* lista, int valor) {
    if (lista == NULL) return NULL;

    No* atual = lista;
    do {
        if (atual->valor == valor) {
            return atual; 
        }
        atual = atual->prox;
    } while (atual != lista);

    return NULL; 
}

No* remover_valor(No* lista, int valor) {
    if (lista == NULL) return NULL;

    No* atual = lista;
    No* anterior = NULL;

    if (lista->valor == valor) {
        return remover_primeiro(lista);
    }

    do {
        anterior = atual;
        atual = atual->prox;

        if (atual->valor == valor) {
            anterior->prox = atual->prox;
            free(atual);
            return lista;
        }
    } while (atual != lista);

    return lista; 
}

No* remover_primeiro(No* lista) {
    if (lista == NULL) return NULL;

    No* atual = lista;

    if (atual->prox == lista) {
        free(lista);
        return NULL;
    }

    No* ultimo = lista;
    while (ultimo->prox != lista) {
        ultimo = ultimo->prox;
    }

    No* remover = lista;
    lista = lista->prox;
    ultimo->prox = lista;

    free(remover);
    return lista;
}

No* remover_ultimo(No* lista) {
    if (lista == NULL) return NULL;

    No* atual = lista;
    No* anterior = NULL;

    if (atual->prox == lista) {
        free(lista);
        return NULL;
    }

    while (atual->prox != lista) {
        anterior = atual;
        atual = atual->prox;
    }

    anterior->prox = lista; 
    free(atual);

    return lista;
}
