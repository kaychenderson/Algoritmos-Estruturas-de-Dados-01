#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ESTUDANTES 100
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int idade;
    float nota1, nota2, nota3;
    float media;
} Estudante;

void calcularMedia(Estudante* estudante) {
    estudante->media = (estudante->nota1 + estudante->nota2 + estudante->nota3) / 3;
}

void ordenarPorMedia(Estudante estudantes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (estudantes[j].media < estudantes[j + 1].media) {
                Estudante temp = estudantes[j];
                estudantes[j] = estudantes[j + 1];
                estudantes[j + 1] = temp;
            }
        }
    }
}

int main() {
    Estudante estudantes[MAX_ESTUDANTES];
    int n = 0;
    FILE *arq_entrada = fopen("dados.txt", "r");
    FILE *arq_saida = fopen("resultado.txt", "w");

    if (arq_entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    while (fscanf(arq_entrada, "%[^,],%d,%f,%f,%f\n", estudantes[n].nome, &estudantes[n].idade,
                  &estudantes[n].nota1, &estudantes[n].nota2, &estudantes[n].nota3) != EOF) {
        calcularMedia(&estudantes[n]);
        n++;
    }
    
    fclose(arq_entrada);

    ordenarPorMedia(estudantes, n);

    printf("Nome\t\tMédia\n");
    for (int i = 0; i < n; i++) {
        printf("%-10s\t%.2f\n", estudantes[i].nome, estudantes[i].media);
        fprintf(arq_saida, "%-10s\t%.2f\n", estudantes[i].nome, estudantes[i].media);
    }

    fclose(arq_saida);

    return 0;
}

// gcc -c main.c
// gcc -o main.exe main.o
// ./main