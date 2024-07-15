#include <stdio.h>
#include <stdlib.h>

int main() {
    int qtdPessoas, count;
    char **nomes; 
    int *idades; 

    printf("Digite o número de pessoas que deseja armazenar: ");
    scanf("%d", &qtdPessoas);
    if (qtdPessoas <= 0 || qtdPessoas > 100) {
        printf("Número de pessoas inválido. Digite um número entre 1 e 100.\n");
    }

    while (qtdPessoas <= 0 || qtdPessoas > 100) {
        printf("Digite o número de pessoas que deseja armazenar: ");
        scanf("%d", &qtdPessoas);
        if (qtdPessoas <= 0 || qtdPessoas > 100) {
            printf("Número de pessoas inválido. Digite um número entre 1 e 100.\n");
        }
    }

    nomes = (char **)malloc(qtdPessoas*sizeof(char *));
    if (nomes == NULL) {
        printf("Falha na alocação de memória para nomes.\n");
        return 1;
    }

    idades = (int *)malloc(qtdPessoas*sizeof(int));
    if (idades == NULL) {
        printf("Falha na alocação de memória para idades.\n");
        free(nomes); 
        return 1;
    }

    for (count = 0; count < qtdPessoas; count++) {
        printf("\n Pessoa N-%d:\n", count+1);

        //100 : a quantidade definida como máxima de chars nos nomes
        nomes[count] = (char *)malloc(100*sizeof(char)); 

        if (nomes[count] == NULL) {
            printf("Falha na alocação de memória para nome.\n");
            free(nomes); 
            free(idades); 
            return 1;
        }

        printf("Digite o nome completo: ");
        scanf(" %[^\n]", nomes[count]); // Lerá o nome completo com os espaços

        printf("Digite a idade: ");
        scanf("%d", &idades[count]);
    }

    printf("\n Nomes armazenados: \n");
    for (count = 0; count < qtdPessoas; count++) {
        printf("%s \n", nomes[count]); 
    }

    for (count = 0; count < qtdPessoas; count++) {
        free(nomes[count]);
    }
    free(nomes);
    free(idades);

    return 0;
}