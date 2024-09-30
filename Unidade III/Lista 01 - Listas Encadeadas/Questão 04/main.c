#include <stdio.h>
#include "lista_circular.h"

int main() {
    No* lista = NULL; 

    lista = inserir_no_inicio(lista, 10);
    lista = inserir_no_inicio(lista, 5);

    lista = inserir_no_fim(lista, 15);
    lista = inserir_no_fim(lista, 20);

    printf("Lista circular inicial:\n");
    exibir_lista(lista);

    No* encontrado = buscar(lista, 15);
    if (encontrado) {
        printf("Valor 15 encontrado na lista.\n");
    } else {
        printf("Valor 15 não encontrado.\n");
    }

    lista = remover_valor(lista, 15);
    printf("Após remover o valor 15:\n");
    exibir_lista(lista);

    lista = remover_primeiro(lista);
    printf("Após remover o primeiro nó:\n");
    exibir_lista(lista);

    lista = remover_ultimo(lista);
    printf("Após remover o último nó:\n");
    exibir_lista(lista);

    return 0;
}
