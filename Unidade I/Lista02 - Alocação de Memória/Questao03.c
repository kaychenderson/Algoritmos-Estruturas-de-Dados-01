/* QUESTÃO 03: Crie um programa em C que leia um número inteiro positivo n do usuário e aloque 
dinamicamente memória para armazenar uma matriz quadrada de ordem n. Preencha essa matriz com números
aleatórios entre 1 e 100, e em seguida, exiba a matriz resultante. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num;
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &num);

    while (num < 0) {
        printf("Digite um numero inteiro positivo: ");
        scanf("%d", &num);
        if (num <= 0) {
            printf("Ops, o número informado é invalido. Tente novamente.\n");
        }
    } 

    int ** matriz = (int **) malloc(num*sizeof(int *));
    for (int count = 0; count < num; count++) {
        matriz[count] = (int *) malloc(num*sizeof(int));
        if(matriz[count] == NULL){exit(1);}
    }

    srand(time(NULL)); //Gerador de números aleatórios

    for (int line = 0; line < num; line++) {
        for (int column = 0; column < num; column++) {
            matriz[line][column] = rand()%100+1;
        }
    }

    printf("\n Matriz gerada: \n");
    for (int line = 0; line < num; line++) {
        for (int column = 0; column < num; column++) {
            printf("%d ", matriz[line][column]);
        }
        printf("\n");
    }

    for (int count = 0; count < num; count++) {
        free(matriz[count]);
    }
    free(matriz);

    return 0;
}
