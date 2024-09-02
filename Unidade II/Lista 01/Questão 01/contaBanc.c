#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contaBanc.h"

struct ContaBancaria{
    char titular[50];
    int numero;
    float saldo;    
};

ContaBancaria *criarConta(char* titular, int numero, float saldo){
    ContaBancaria *conta = (ContaBancaria*)malloc(sizeof(ContaBancaria));
    if(conta==NULL){
        printf("Erro ao alocar memoria.\n");
        exit(1);
    } else {
        printf("Memoria alocada com sucesso.\n");
    }

    conta->numero = numero;
    conta->saldo = saldo;
    strcpy(conta->titular, titular);

    return conta;
}

void depositar(ContaBancaria* conta, float dinheiro){
    conta->saldo = conta->saldo + dinheiro;
    printf("Valor depositado com sucesso.\n");
    printf("Novo saldo (pos-deposito): %.2f\n", conta->saldo);
}

void sacar(ContaBancaria* conta, float valor){
    if (conta->saldo >= valor){
        conta->saldo = conta->saldo - valor;
        printf("Valor sacado com sucesso.\n");
        printf("Novo saldo (pos-saque): %.2f\n", conta->saldo);
    } else {
        printf("Valor insuficinte.\n");
    }
}

float saldo(ContaBancaria* conta){
    printf("Saldo final: %.2f", &conta->saldo);
}

void excluir(ContaBancaria* conta){
    free(conta);
}