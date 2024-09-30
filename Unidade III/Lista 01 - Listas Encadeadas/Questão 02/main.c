#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void) {
    No* lista = NULL; 

    lista = inserir_no_inicio(lista, 10);
    lista = inserir_no_inicio(lista, 5);

    lista = inserir_no_fim(lista, 15);
    lista = inserir_no_fim(lista, 20);

    printf("Lista encadeada:\n");
    exibir_lista(lista);

    int valor = 15;
    int posicao = buscar(lista, valor);
    if (posicao != -1) {
        printf("Valor %d encontrado na posição %d\n", valor, posicao);
    } else {
        printf("Valor %d não encontrado na lista\n", valor);
    }

    lista = remover_valor(lista, 15);
    printf("Após remover o valor 15:\n");
    exibir_lista(lista);

    lista = inserir_apos(lista, 10, 12);
    printf("Após inserir 12 após o valor 10:\n");
    exibir_lista(lista);

    liberar_lista(lista);

    return 0;
}