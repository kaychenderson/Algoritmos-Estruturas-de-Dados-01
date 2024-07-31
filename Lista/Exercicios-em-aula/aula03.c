#include <stdio.h>

struct aluno {
    int mat, idade;
    char nome[100];
};

void coletar(struct aluno *pp) {
    printf("Informe seus dados: \n");
    printf("Informe seu nome: \n");
    scanf("%[^\n]", pp->nome); 
    printf("Informe sua idade: \n");   
    scanf("%d", &pp->idade);
    printf("Informe sua matricula: \n"); 
    scanf("%d", &pp->mat);
}

void imprimir(struct aluno *pp) {
    printf("Os dados informados foram: \n");
    printf("Nome: %s \n", pp->nome);
    printf("Idade: %d \n", pp->idade);
    printf("Matricula: %d \n", pp->mat);
}

int main() {
    struct aluno p;
    coletar(&p);
    imprimir(&p);
    return 0;
}