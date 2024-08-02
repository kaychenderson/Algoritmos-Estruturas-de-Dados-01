/* Q02: Crie um tipo estruturado para armazenar dados de uma pessoa. Uma estrutura deste tipo possui os
seguintes campos: nome da pessoa, numero do documento e idade.
a) Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Pessoa e
preencha seus campos com valores fornecidos pelo usuário via teclado.
b) Escreva uma funçãoque receba como parâmetro o endereço de uma estrutura do tipo Pessoa e
imprima os valores dos seus campos.
c) Implemente uma função para realizar uma atualização da idade de uma estrutura do tipo Pessoa.
d) Escreva uma função que receba como parâmetro um vetor de estruturas do tipo Pessoa e imprima
o nome da Pessoa mais velha e mais nova. */

#include <stdio.h>

#define QTD_P 3

typedef struct {
    char nome[50];
    int docnum, idade;
} Pessoa;

void preencherPessoa(Pessoa *p) {
    printf("Informe o nome da pessoa: ");
    scanf(" %[^\n]", p->nome);  
    printf("Informe a idade da pessoa: ");
    scanf("%d", &p->idade);
    printf("Informe o número do documento: ");
    scanf("%d", &p->docnum);
}

void imprimirPessoa(Pessoa *p) {
    printf("Nome: %s\n", p->nome);
    printf("Idade: %d\n", p->idade);
    printf("Número do Documento: %d\n", p->docnum);
}

void altIdade(Pessoa pessoas[], int tamanho, int docnum, int novaIdade) {
    for (int index = 0; index < tamanho; index++) {
        if (pessoas[index].docnum == docnum) {
            pessoas[index].idade = novaIdade;
            printf("A idade de: %s - (DocNum: %d) foi alterado com sucesso para: %d\n", pessoas[index].nome, docnum, novaIdade);
        }
    }
    printf("Pessoa não encontrada.\n");
}

void imprimirMaiorMenorIdade(Pessoa pessoas[], int tamanho) {
    Pessoa *maiorIdade = &pessoas[0];
    Pessoa *menorIdade = &pessoas[0];

    for (int index = 1; index < tamanho; index++) {
        if (pessoas[index].idade > maiorIdade->idade) {
            maiorIdade = &pessoas[index];
        }
        if (pessoas[index].idade < menorIdade->idade) {
            menorIdade = &pessoas[index];
        }
    }

    printf("Pessoa com maior idade:\n");
    printf("Nome: %s\n", maiorIdade->nome);
    printf("Pessoa com menor idade:\n");
    printf("Nome: %s\n", menorIdade->nome);
}

int main() {
    Pessoa pessoas[QTD_P];

    for (int index = 0; index < QTD_P; index++) {
        printf("Preenchendo dados da Pessoa %d:\n", index + 1);
        preencherPessoa(&pessoas[index]);
    }

    for (int index = 0; index < QTD_P; index++) {
        printf("\nDados da Pessoa %d:\n", index + 1);
        imprimirPessoa(&pessoas[index]);
    }

    int docnum;
    int novaIdade;
    printf("\nDigite o número do documento da pessoa que a idade será alterada: ");
    scanf("%d", &docnum);
    printf("Digite a nova Idade: ");
    scanf("%d", &novaIdade);

    altIdade(pessoas, QTD_P, docnum, novaIdade);

    imprimirMaiorMenorIdade(pessoas, QTD_P);

    return 0;
}