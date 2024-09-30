#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void) {
    No* lista = NULL; // Inicializa a lista vazia

    // Inserção no início
    lista = inserir_no_inicio(lista, 10);
    lista = inserir_no_inicio(lista, 5);

    // Inserção no final
    lista = inserir_no_fim(lista, 15);
    lista = inserir_no_fim(lista, 20);

    // Exibir lista
    printf("Lista encadeada:\n");
    exibir_lista(lista);

    // Remover o primeiro elemento
    lista = remover_primeiro(lista);
    printf("Após remover o primeiro elemento:\n");
    exibir_lista(lista);

    // Liberação de memória
    liberar_lista(lista);

    return 0;
}