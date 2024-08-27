#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contaBanc.h"

int main (void){
    
    ContaBancaria *conta = criarConta ("Maria", 1000.00, 23455);
    depositar(conta, 2500.00);
    sacar(conta, 3000.00);
    float saldo(ContaBancaria* conta);
    void excluirConta(ContaBancaria* conta);

    return 0;
}