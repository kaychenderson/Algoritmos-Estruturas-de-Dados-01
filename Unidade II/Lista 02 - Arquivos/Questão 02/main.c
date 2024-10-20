#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arq_entrada, *arq_saida;
    int vetor[10], index, maior, menor;
    float media, soma = 0;

    arq_entrada = fopen("entrada_q2.txt", "r");
    arq_saida = fopen("saida_q2.txt", "w");

    if (arq_entrada == NULL || arq_saida == NULL) {
        printf("Erro ao abrir os arquivos!\n");
        exit(1);
    }

    for (index = 0; index < 10; index++) {
        fscanf(arq_entrada, "%d", &vetor[index]);
        soma = soma + vetor[index];

        if (index == 0) {
            maior = menor = vetor[index];
        } else {
            if (vetor[index] > maior) maior = vetor[index];
            if (vetor[index] < menor) menor = vetor[index];
        }
    }

    media = soma / 10;

    fprintf(arq_saida, "Menor: %d\nMaior: %d\nMédia: %.2f\n", menor, maior, media);

    fclose(arq_entrada);
    fclose(arq_saida);

    return 0;
}

// gcc -c main.c
// gcc -o main.exe main.o
// ./main