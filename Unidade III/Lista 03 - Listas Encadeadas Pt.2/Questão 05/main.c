#include <stdio.h>
#include "lista.h"

int main() {
    ListaFunc* lista = NULL;

    lista = insere_funcionario(lista, cria_funcionario('A', 101, "Joao Silva", 3000.00));
    lista = insere_funcionario(lista, cria_funcionario('B', 102, "Maria Souza", 2500.00));
    lista = insere_funcionario(lista, cria_funcionario('A', 103, "Carlos Pereira", 4000.00));
    lista = insere_funcionario(lista, cria_funcionario('C', 104, "Ana Oliveira", 3500.00));

    printf("Funcionários cadastrados:\n");
    exibe_funcionarios(lista);

    float total_folha = lstfunc_folha_pagto(lista, 'A');
    printf("Total da folha de pagamento do departamento A: %.2f\n", total_folha);

    return 0;
}
