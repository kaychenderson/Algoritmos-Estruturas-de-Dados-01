#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/* Lista Encadeada para manipular numeros inteiros. */

struct no{
    int info;
    struct no* prox;
};

No* inserirInt(No* lista, int numero){
    No* novoElemento = (No*) malloc (sizeof(No));
    if(novoElemento == NULL){
        exit(1);
    }
    novoElemento->info = numero;
    novoElemento->prox = lista;

    return novoElemento;
}

void imprimirInt(No* lista){
    No* index;
    for(index = lista; index != NULL; index=index->prox){
        printf("%d", index->info);
    }
}

void liberarInt(No* lista){
    No* index = lista;
    No* aux;
    while(index != NULL){
        aux = index->prox;
        free(index);
        index = aux;
    }
}

No* buscarInt(int numero, No* lista){
    No* index;
    for(index = lista; index != NULL; index = index->prox){
        if(index->info == numero){
            printf("Valor encontrado!\n");
            return index;
        }
    }
    printf("Valor não encontrado.\n");
    return NULL;
}

No* removerInt(No* lista, int numero){
    No* ant; // Guardar o elemento anterior
    No* index = lista; // Contador para percorrer a lista
    // Buscando o elemento a ser removido
    while(index->info != NULL){
        if(index == NULL){
            return lista;
        }
        ant = index;
        index = index->prox;
    }
    // O elemento é o primeiro da lista
    if(ant == NULL){
        lista = lista->prox;
    } 
    // O elemento está no meio ou final da lista
    else{
        ant->prox = index->prox;
    }

    free(index)
    return lista;
}