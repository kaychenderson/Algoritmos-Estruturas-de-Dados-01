#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arq_entrada, *arq_saida;
    char nome[100];
    float nota1, nota2, nota3, media;
    
    arq_entrada = fopen("entrada_q3.txt", "r");
    arq_saida = fopen("saida_q3.txt", "w");

    if (arq_entrada == NULL || arq_saida == NULL) {
        printf("Erro ao abrir os arquivos!\n");
        return 1;
    }

    while (fscanf(arq_entrada, "%s\t%f\t%f\t%f", nome, &nota1, &nota2, &nota3) != EOF) {
        media = (nota1 + nota2 + nota3) / 3.0;
        fprintf(arq_saida, "%s\t%.2f\t%s\n", nome, media, (media >= 7.0) ? "Aprovado" : "Reprovado");
    }

    fclose(arq_entrada);
    fclose(arq_saida);

    return 0;
}

// gcc -c main.c
// gcc -o main.exe main.o
// ./main