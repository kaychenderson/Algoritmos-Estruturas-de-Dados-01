#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arq_entrada, *arq_saida;
    int vetor[10], i, maior, menor;
    float media, soma = 0;

    arq_entrada = fopen("entrada_q2.txt", "r");
    arq_saida = fopen("saida_q2.txt", "w");

    if (arq_entrada == NULL || arq_saida == NULL) {
        printf("Erro ao abrir os arquivos!\n");
        return 1;
    }

    for (i = 0; i < 10; i++) {
        fscanf(arq_entrada, "%d", &vetor[i]);
        soma += vetor[i];

        if (i == 0) {
            maior = menor = vetor[i];
        } else {
            if (vetor[i] > maior) maior = vetor[i];
            if (vetor[i] < menor) menor = vetor[i];
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