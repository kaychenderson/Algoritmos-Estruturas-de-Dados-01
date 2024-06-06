#include <stdio.h>
#include <stdlib.h>

void funcAloc(vetor) {
    if (vetor == NULL) {
        printf("Sem memória! \n");
        exit(1);
    } else {
        printf("Alocação bem sucedida! \n");
    }
}

//Mudando o tamanho do vetor.

int main () {
    int tamanho, novoTamanho;
    printf("Digite o tamanho do vetor: \n");
    scanf("%d", tamanho);
    int * vetor = (int *) calloc(tamanho, sizeof(int));
    funcAloc(vetor);

    printf("\n Digite o novo tamanho: \n");
    scanf("%d", &novoTamanho); 
    vetor = (int*) realloc(vetor, novoTamanho * sizeof(int));
    funcAloc(vetor);

    free(vetor);
    
    return 0;
}