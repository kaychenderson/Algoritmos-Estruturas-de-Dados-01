#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha* p = pilha_cria();

    pilha_push(p, 1);
    pilha_push(p, 2);
    pilha_push(p, 3);

    printf("Desempilhando: %.2f\n", pilha_pop(p));
    printf("Desempilhando: %.2f\n", pilha_pop(p));

    if (pilha_vazia(p)) {
        printf("Pilha está vazia.\n");
    } else {
        printf("Pilha não está vazia.\n");
    }

    pilha_libera(p);

    return 0;
}

//Compilação e Execução:

// Para usar a implementação com vetor dinâmico:
// gcc main.c pilhaVetor.c -o pilha_vetor
// ./pilha_vetor

// Para usar a implementação com Lista Encadeada:
// gcc main.c pilhaLista.c -o pilha_lista
// ./pilha_lista