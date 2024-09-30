#include <stdio.h>
#include "lista_circ.h"

int main() {
    No* lista = NULL; 

    lista = inserir_no_inicio(lista, 10);
    lista = inserir_no_inicio(lista, 5);

    lista = inserir_no_fim(lista, 15);
    lista = inserir_no_fim(lista, 20);

    printf("Lista circular:\n");
    exibir_lista(lista);

    return 0;
}
