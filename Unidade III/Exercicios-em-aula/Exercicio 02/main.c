#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void){

    No* lista == NULL; // Lista vazia

    // Inserindo numeros na lista
    lista = inserirInt(lista, 2);
    lista = inserirInt(lista, 4);
    lista = inserirInt(lista, 8);

    // Imprimindo a lista
    imprimirInt(lista);

    No* lista = buscarInt(2, lista);

    No* lista = removerInt(lista, 4);

    liberarInt(lista);

    return 0;
}