/* QUESTÃO O1: Escreva um programa em C que solicite ao usuário o tamanho de um vetor e, em seguida, 
aloque dinamicamente memória para armazenar esse vetor. Depois disso, peça ao usuário que insira 
os elementos do vetor e, por fim, imprima os elementos na ordem inversa. */

#include <stdio.h>
#include <stdlib.h>

void preencheVetor (int size, int *vator){
    printf("Digite os elementos do vetor: \n");
    for(int count = 0; count < size; count++){
        scanf("%d", &vetor[count]);
    }
}

void imprimeVetor (int size, int *vetor){
    printf("Vetor inverso: \n");
    for(int count = size-1; count >= 0; count--){
        printf("%d \t", vetor[count]);
    }
}

int * alocaVetor(int sieze){
    int * vetor = (int *) malloc(size*sizeof(int));

    if (vetor == NULL){
        printf("No memory!");
    } else {
        printf("Vetor Alocado com sucesso!");
    }

    return vetor;
}

int main(void){

    int size;

    printf("Informe o tamanho do vetor: \t");
    scanf("%d", &size);

    alocaVetor(size);

    preencheVetor(size, vetor);

    imprimeVetor(size, vator);

    free(vetor);
    return 0;
}