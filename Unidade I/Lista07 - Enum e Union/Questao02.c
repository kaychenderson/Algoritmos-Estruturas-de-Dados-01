/* Questão 02: Escreva um programa que implementa uma struct Produto com os campos nome, pre¸co e tipo. O
tipo deve ser armazenado como uma union que armazena um dos tipos: ALIMENTO, BEBIDA ou
ELETRONICO. O programa deve ler os dados de um produto e imprimir os dados do produto. */

#include <stdio.h>

typedef enum tipo {
    ALIMENTO = 1,
    BEBIDA,
    ELETRONICO
} Tipo;

typedef struct produto {
    char nome[30];
    float preco;
    Tipo tipo;
} Produto;

void preenche(Produto *produto) {
    printf("Digite o nome do Produto: \n");
    scanf(" %[^\n]", produto->nome);

    printf("Digite o preço do Produto: \n");
    scanf("%f", &produto->preco);

    printf("Digite o tipo do Produto: \n");
    printf("1 - ALIMENTO\n2 - BEBIDA\n3 - ELETRONICO \n");
    scanf("%d", &produto->tipo);
}

void imprime(Produto *produto) {
    printf("\nDados do Produto: \n");
    printf("Nome: %s\n", produto->nome);
    printf("Idade: %.2f\n", produto->preco);
    printf("Tipo do Produto: %s \n",
        produto->tipo == ALIMENTO ? "ALIMENTO" :
        produto->tipo == BEBIDA ? "BEBIDA" : "ELETRONICO");
}

int main() {
    Produto produto;

    preenche(&produto);
    imprime(&produto);

    return 0;
}