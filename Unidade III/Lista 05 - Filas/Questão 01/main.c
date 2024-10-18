#include <stdio.h>
#include "fila.h"

int main() {
    Fila* f = fila_cria();

    fila_insere(f, 1.5);
    fila_insere(f, 2.3);
    fila_insere(f, 3.7);

    printf("Fila: ");
    fila_imprime(f);

    printf("Removendo elemento: %.2f\n", fila_retira(f));
    
    printf("Fila após remoção: ");
    fila_imprime(f);

    fila_libera(f);
    return 0;
}