#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contaBanc.h"

struct ContaBancaria{
    char titular[20];
    int numero;
    float saldo;
};

ContaBancaria *criarConta (char* titular, float saldo, int numero){

    ContaBancaria *conta = (ContaBancaria*) malloc(sizeof(ContaBancaria));
    if (conta == NULL){
        printf("No memory. \n");
        exit(1);
    } else {
        printf("Conta Bancária Alocada! \n");
    }
    //Inicializar conta
    conta->numero = numero;
    conta->saldo = saldo;
    strcpy(conta->titular, titular); //Copia a string titular para conta->titular

    return conta; 
}

void depositar(ContaBancaria* conta, float dinheiro){
    conta->saldo = conta->saldo+dinheiro;
    printf("Valor depositado com sucesso.\n");
    printf("Novo Saldo: %.2f \n", conta->saldo);
}

void sacar(ContaBancaria* conta, float valor){
    if(conta->saldo >= valor){
        conta->saldo = conta->saldo - valor;
        printf("Valor sacado com sucesso. \n");
    } else {
        printf("O valor é insuficiente. \n");
    }
}

float saldo(ContaBancaria* conta){
    return conta->saldo;
}

void excluirConta(ContaBancaria* conta){
    free(conta);
}