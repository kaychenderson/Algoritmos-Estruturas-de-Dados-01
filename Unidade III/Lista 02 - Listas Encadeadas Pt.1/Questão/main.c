#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    Lista* lista1 = cria_lista();
    Lista* lista2 = cria_lista();

    lista1 = insere_inicio(lista1, 2.1);
    lista1 = insere_inicio(lista1, 4.5);
    lista1 = insere_inicio(lista1, 1.0);

    lista2 = insere_inicio(lista2, 7.2);
    lista2 = insere_inicio(lista2, 9.8);

    printf("Lista 1: ");
    imprime_lista(lista1);

    printf("Lista 2: ");
    imprime_lista(lista2);

    int n = 25;
    int num_maiores = maiores(lista1, n);
    printf("Número de elementos maiores que %d: %d\n", n, num_maiores);

    Lista* ult = ultimo(lista1);
    if (ult != NULL) {
        printf("Último elemento da lista 1: %d\n", ult->info);
    }

    Lista* lista_concatenada = concatena(lista1, lista2);
    printf("Lista concatenada: ");
    imprime_lista(lista_concatenada);

    int valor_para_remover = 30;
    lista_concatenada = retira_n(lista_concatenada, valor_para_remover);
    printf("Lista após remover %d: ", valor_para_remover);
    imprime_lista(lista_concatenada);

    libera_lista(lista_concatenada);

    return 0;
}
