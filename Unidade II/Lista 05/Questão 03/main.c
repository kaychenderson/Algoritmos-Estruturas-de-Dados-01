#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 1000

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int buscalinear(int* entrada, int tamanho) {
    int maior = entrada[0];
    for(int i = 1; i < tamanho; i++) {
        if(entrada[i] > maior) {
            maior = entrada[i];
        }
    }
    return maior;
}

int buscabinaria(int arr[], int maior, int tamanho) {
    qsort(arr, tamanho, sizeof(int), compare); // Ordena o array
    int inicio = 0;
    int final = tamanho - 1;

    while(inicio <= final) {
        int meio = inicio + (final - inicio) / 2;
        if(arr[meio] == maior) {
            return arr[meio];
        } else if (arr[meio] < maior) {
            inicio = meio + 1;
        } else {
            final = meio - 1;
        }
    }
    return -1;
}

int main(void) {
    int entrada[TAMANHO];
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    for(int i = 0; i < TAMANHO; i++) {
        entrada[i] = rand(); // Preenche o array com números aleatórios
    }

    // Busca linear
    clock_t tempo_inicial = clock();
    int maior = buscalinear(entrada, TAMANHO);
    double tempo_final = (double)(clock() - tempo_inicial) / CLOCKS_PER_SEC * 1000;
    printf("Maior elemento (Busca Linear): %d, Tempo execução: %.4f ms\n", maior, tempo_final);

    // Busca binária
    tempo_inicial = clock();
    int maior2 = buscabinaria(entrada, maior, TAMANHO);
    tempo_final = (double)(clock() - tempo_inicial) / CLOCKS_PER_SEC * 1000;
    printf("Maior elemento (Busca Binária): %d, Tempo execução: %.4f ms\n", maior2, tempo_final);

    return 0;
}

// gcc -c main.c
// gcc -o main.exe main.o
// ./main