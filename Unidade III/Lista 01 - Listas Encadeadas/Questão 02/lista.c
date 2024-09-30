#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* inserir_no_inicio(No* lista, int valor) {
    No* NovoNo = (No*) malloc(sizeof(No));
    if (NovoNo == NULL) {
        exit(1);
    }
    NovoNo->valor = valor;
    NovoNo->prox = lista;
    
    return NovoNo;
}

No* inserir_no_fim(No* lista, int valor) {
    No* NovoNo = (No*) malloc(sizeof(No));
    if (NovoNo == NULL) {
        exit(1);
    }
    NovoNo->valor = valor;
    NovoNo->prox = NULL;

    if (lista == NULL) {
        return NovoNo;
    }

    No* atual = lista;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = NovoNo;

    return lista;
}

void exibir_lista(No* lista) {
    No* atual = lista;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

No* remover_primeiro(No* lista) {
    if (lista == NULL) {
        return NULL;
    }
    No* remover = lista;
    lista = lista->prox;
    free(remover);
    return lista;
}

int buscar(No* lista, int valor) {
    No* atual = lista;
    int posicao = 0;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return posicao; 
        }
        atual = atual->prox;
        posicao++;
    }
    return -1; 
}

No* remover_valor(No* lista, int valor) {
    if (lista == NULL) {
        return NULL;
    }

    if (lista->valor == valor) {
        No* remover = lista;
        lista = lista->prox;
        free(remover);
        return lista;
    }

    No* atual = lista;
    while (atual->prox != NULL && atual->prox->valor != valor) {
        atual = atual->prox;
    }

    if (atual->prox != NULL) {
        No* remover = atual->prox;
        atual->prox = remover->prox;
        free(remover);
    }

    return lista;
}

No* inserir_apos(No* lista, int valor, int novo_valor) {
    No* atual = lista;

    while (atual != NULL && atual->valor != valor) {
        atual = atual->prox;
    }

    if (atual != NULL) {
        No* NovoNo = (No*) malloc(sizeof(No));
        if (NovoNo == NULL) {
            exit(1);
        }
        NovoNo->valor = novo_valor;
        NovoNo->prox = atual->prox;
        atual->prox = NovoNo;
    }

    return lista;
}

void liberar_lista(No* lista) {
    No* atual = lista;
    while (atual != NULL) {
        No* remover = atual;
        atual = atual->prox;
        free(remover);
    }
}
