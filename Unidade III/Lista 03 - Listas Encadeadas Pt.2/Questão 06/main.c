// main.c
#include <stdio.h>
#include "listahet.h"

int main() {
    ListaHet* lista = NULL;

    lista = cria_ret(5, 3);  // Retângulo 5x3
    lista->prox = cria_tri(4, 2);  // Triângulo 4x2
    lista->prox->prox = cria_circ(2.5);  // Círculo de raio = 2.5

    float maior_area = max_area(lista);
    printf("A maior área na lista é: %.2f\n", maior_area);

    return 0;
}