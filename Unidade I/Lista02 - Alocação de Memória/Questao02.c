/* QUESTÃO 02: Implemente um programa em C que solicite ao usuário o número de linhas e colunas de uma 
matriz e, em seguida, aloque dinamicamente memória para armazenar essa matriz. Peça ao usuário que 
insira os elementos da matriz e, por fim, imprima a matriz na forma original e transposta. */

#include <stdio.h>
#include <stdlib.h>

int main(void){

    int line, lines, column, columns, count;

    printf("Informe a quantidade de LINHAS e COLUNAS da matriz, respectivamente. \n");
    scanf("%d %d", &lines, &columns);

    int ** matriz = (int **) malloc(lines*sizeof(int *));
    for(count = 0; count < lines; count++){
        matriz[count] = (int *) malloc(columns*sizeof(int));
        if(matriz[count] == NULL){exit(1);}
    }

    printf("Informe os elementos: \n");
    for(line = 0; line < lines; line++){
        printf("\n");
        for(column = 0; column < columns; column++){
            printf("%d \t", matriz[line][column]);
        }
    }

    printf("\n\n A transposta: \n");
    for(line = 0; line < lines; line++){
        printf("\n");
        for(column = 0; column < columns; column++){
            printf("%d \t", matriz[column][line]);
        }
    }

    for(line = 0; line < lines; line++){
        free(matriz[line]);
    }

    free(matriz);

    return 0;
}