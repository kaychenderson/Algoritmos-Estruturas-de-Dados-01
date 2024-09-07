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
        printf("%d ", index->info); // Adicionando espaço para melhor formatação
    }
    printf("\n"); // Quebra de linha após a impressão da lista
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
    No* ant = NULL; // Guardar o elemento anterior
    No* index = lista; // Contador para percorrer a lista
    // Buscando o elemento a ser removido
    while(index != NULL && index->info != numero){
        ant = index;
        index = index->prox;
    }
    if(index == NULL){ // Se o número não for encontrado
        return lista;
    }
    // O elemento é o primeiro da lista
    if(ant == NULL){
        lista = lista->prox;
    } 
    // O elemento está no meio ou final da lista
    else{
        ant->prox = index->prox;
    }

    free(index);
    return lista;
}