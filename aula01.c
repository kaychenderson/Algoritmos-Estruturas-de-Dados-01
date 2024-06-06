#include <stdio.h>
#include <stdlib.h> 

float * criaVetor (int tamanho) {
    float * vetor = (float*) malloc(tamanho * sizeof(float));
    if (vetor == NULL) {
        printf("Sem memória! \n");
        exit(1);
    } else {
        printf("Alocação bem sucedida! \n");
    }
    return vetor;
}

void lerVetor (float *vetor, int tamanho) {
    for (int index = 0; index < 5; index++) {
        printf("Escreva os números: \n");
        scanf("%f", &vetor[index]);
    }
}

void imprimeVetor (float *vetor, int tamanho) {
    for (int index = 0; index < 5; index++) {
        printf("%f \t", vetor[index]);
    }
}

int main () {
    float *vetor = criaVetor(5);
    lerVetor(vetor, 5);
    imprimeVetor(vetor, 5);
    free(vetor);
    return 0;
}