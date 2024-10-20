#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contaBanc.h"

int main(void){

    ContaBancaria *conta = criarConta ("Maria", 123, 3000.00);

    depositar(conta, 2000.00);

    sacar(conta, 2500.00);

    saldo(conta);

    excluir(conta);

    return 0;
}

// gcc main.c contaBanc.c-o main
// ./main