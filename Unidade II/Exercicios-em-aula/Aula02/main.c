#include <stdio.h>
#include "str.h"

int main(void){

    char str[101], str1[51], str2[51];

    printf("Informe uma sequência de caracteres: \n");
    scanf(" %50[^\n]", str1);
    printf("Informe outra sequencia de caracteres: \n");
    scanf(" %50[^\n]", str2);

    copia(str, str2);
    concatena(str, str2);

    printf("Comprimento da concatenação: %d \n", comprimento(str));

    return 0;
}

//gcc -c aluno.c
//gcc -c main.c
//gcc -o main.exe aluno.o main.o
//gcc main.c -o main
//./main