// lista.c
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Função para inserir no início da lista
No* inserir_no_inicio(No* lista, int valor) {
    No* NovoNo = (No*) malloc(sizeof(No));
    if (NovoNo == NULL) {
        exit(1);
    }
    NovoNo->valor = valor;
    NovoNo->prox = lista;
    
    return NovoNo;
}

// Função para inserir no final da lista
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

// Função para exibir a lista
void exibir_lista(No* lista) {
    No* atual = lista;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Função para remover o primeiro elemento da lista
No* remover_primeiro(No* lista) {
    if (lista == NULL) {
        return NULL;
    }
    No* remover = lista;
    lista = lista->prox;
    free(remover);
    return lista;
}

// Função para liberar toda a memória da lista
void liberar_lista(No* lista) {
    No* atual = lista;
    while (atual != NULL) {
        No* remover = atual;
        atual = atual->prox;
        free(remover);
    }
}