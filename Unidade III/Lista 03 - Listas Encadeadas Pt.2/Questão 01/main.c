#include <stdio.h>
#include "lista2.h"

int main() {
    Lista2* l = lst2_cria();

    l = lst2_insere(l, 10);
    l = lst2_insere(l, 20);
    l = lst2_insere(l, 30);

    printf("Lista: ");
    lst2_imprime(l);

    printf("Removendo 20...\n");
    l = lst2_retira(l, 20);
    
    printf("Lista após remoção: ");
    lst2_imprime(l);

    lst2_libera(l);
    return 0;
}