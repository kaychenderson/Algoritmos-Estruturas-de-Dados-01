#include <stdio.h>

typedef enum genero {
    MASCULINO = 1,
    FEMININO,
    NEUTRO,
    OUTRO
} Genero;

typedef struct pessoa {
    char nome[50];
    int idade;
    Genero genero;
} Pessoa;

void preenche(Pessoa * pessoa) {
    printf("Digite o nome: ");
    scanf(" %[^\n]", pessoa->nome);

    printf("Digite a idade: ");
    scanf("%d", &pessoa->idade);

    printf("Digite o gênero: \n");
    printf("1 - MASCULINO\n2 - FEMININO\n3 - NEUTRO\n4 - OUTRO: ");
    scanf("%d", &pessoa->genero);
}

void imprime(Pessoa * pessoa) {
    printf("\nDados da Pessoa:\n");
    printf("Nome: %s\n", pessoa->nome);
    printf("Idade: %d\n", pessoa->idade);
    printf("Gênero: %s\n",
        pessoa->genero == MASCULINO ? "MASCULINO" :
        pessoa->genero == FEMININO ? "FEMININO" :
        pessoa->genero == NEUTRO ? "NEUTRO" : "OUTRO");
}

int main() {
    Pessoa pessoa;

    preenche(&pessoa);
    imprime(&pessoa);

    return 0;
}