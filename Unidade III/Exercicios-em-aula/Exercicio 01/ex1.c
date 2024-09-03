#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int main(void){
//     char **nome_frutas = (char**) malloc (sizeof(char*));
//     if (nome_frutas == NULL){
//         exit(1);
//     }
//     for (int i = 0; i < 3; i++){
//         nome_frutas[i] = malloc(20*sizeof(char));
//     }
// }

/* Listras Encadeadas */
struct no{
    char nome_fruta[20];
    struct no *prox_fruta;
};

typedef struct no No;

                   /* Lista */
// | Morango | --> | Abacaxi | --> | Uva | --> NULL
// Morango = nova_fruta
// Abacaxi = nova_fruta->prox_fruta
// Uva = nova_fruta->prox_fruta->prox_fruta
// NULL = Final da lista

No* adicionarFruta(No* lista, char* nome_fruta){
    No* nova_fruta = (No*) malloc (sizeof(No));
    if(nova_fruta == NULL){
        exit(1);
    }
    strcpy(nova_fruta->nome_fruta = nome_fruta);
    nova_fruta->prox_fruta = lista;

    /* Conectando o ultimo elemento ao ultimo */
    No* aux = lista;
    No* ant = nova_fruta;
    while(aux != nova_fruta){
        ant = aux;
        aux = aux->prox_fruta;
    }
    ant->prox_fruta = nova_fruta;
    /* Conectando o ultimo elemento ao ultimo */

    return nova_fruta;
}

void imprimirListaFrutas(No* lista){
    No* index;
    for(index = lista; index != NULL; index = index->prox){
        printf("%s", index->nome_fruta);
    }
}

int main(void){
    No* lista = NULL; // Lista vazia.

    lista = adicionarFruta(lista, "Uva");
    lista = adicionarFruta(lista, "Abacaxi");
    lista = adicionarFruta(lista, "Morango");

    imprimirListaFrutas(lista);

    return 0;
}

// gcc main.c -o main
// ./main