#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha* p1 = pilha_cria();
    Pilha* p2 = pilha_cria();
    
    pilha_push(p1, 2.1);
    pilha_push(p1, 4.5);
    pilha_push(p1, 1.0);
    
    pilha_push(p2, 7.2);
    pilha_push(p2, 3.1);
    pilha_push(p2, 9.8);

    printf("Topo de p1: %.1f\n", topo(p1)); 

    printf("Concatenando p2 em p1...\n");
    concatena_pilhas(p1, p2); 

    while (!pilha_vazia(p1)) {
        printf("Desempilhando de p1: %.1f\n", pilha_pop(p1));
    }

    if (pilha_vazia(p2)) {
        printf("Pilha p2 está vazia.\n");
    } else {
        printf("Erro: p2 não está vazia.\n");
    }

    pilha_libera(p1);
    pilha_libera(p2);
    
    return 0;
}

// gcc main.c pilha.c -o pilha