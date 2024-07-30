/* Questão 1) A Nlogônia é um país tropical, com muitas belezas naturais internacionalmente
famosas; dentre elas, encontram-se as belas praias que compõem o arquipélago do país, que
todo verão recebem milhões de turistas estrangeiros.
O Ministério do Turismo da Nlogônia está preparando o país para a chegada dos turistas, mas,
para fazer seu planejamento, precisa saber a extensão da costa nlogônica. Para isso, ele gerou
um mapa que divide o território nacional em vários quadrados, que podem ser ocupados por
água ou por terra; considera-se que um quadrado é parte da costa nlogônica se ele é um
quadrado ocupado por terra que tem um lado em comum com um quadrado ocupado por
água.
Na figura abaixo, (a) mostra um trecho do mapa gerado e (b) mostra os quadrados do trecho
dado que são costa.
Como a Nlogônia é um país muito grande, o ministro do turismo pediu que você escrevesse um
programa que, dado o mapa da Nlogônia, determina a extensão da costa nlogônica.
Entrada
A primeira linha da entrada contém dois inteiros M e N indicando, respectivamente, o número
de linhas e o número de colunas do mapa. Cada uma das M linhas seguintes contém N
caracteres: um caractere ‘.’ indica que aquele quadrado do território é ocupado por água; um
caractere ‘#’ indica que aquele quadrado do território é ocupado por terra.
Considere que todo o espaço fora da área do mapa é ocupado por água.
Saída
Seu programa deve imprimir uma única linha contendo um único inteiro, indicando quantos
quadrados do território fazem parte da costa da Nlogônia.
Restrições:
# 1 ≤ M, N ≤ 1000. */

#include <stdio.h>
#include <stdlib.h>

int main() {

    do {
        printf("Informe o número de linhas e colunas do mapa (1 ≤ linhas, colunas ≤ 1000): ");
        scanf("%d %d", &linhas, &colunas);
        if (linhas < 1 || linhas > 1000 || colunas < 1 || colunas > 1000) {
            printf("Valores inválidos! Por favor, tente novamente. \n");
        }
    } while (linhas < 1 || linhas > 1000 || colunas < 1 || colunas > 1000);

    char **mapa = (char **)malloc(linhas * sizeof(char *));
    for (int i = 0; i < linhas; i++) {
        mapa[i] = (char *)malloc((colunas + 1) * sizeof(char)); // colunas+1: para incluir o caractere '\0', que serve pra indentificarmos o fim de uma string
    }

    printf("Digite o mapa:\n");
    for (int i = 0; i < linhas; i++) {
        scanf("%s", mapa[i]);
    }

    int costa = 0;
    int dx[] = {0, 0, -1, 1}; 
    int dy[] = {-1, 1, 0, 0};

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (mapa[i][j] == '#') {
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];  //verificando se (ni, nj) está dentro dos limites do mapa e se é um ponto da costa.
                    int nj = j + dy[k];
                    if (ni < 0 || ni >= linhas || nj < 0 || nj >= colunas || mapa[ni][nj] == '.') {
                        costa++;
                        break;
                    }
                }
            }
        }
    }

    printf("Extensão territorial da costa: %d quadradinhos \n", costa);

    for (int i = 0; i < linhas; i++) {
        free(mapa[i]);
    }
    free(mapa);

    return 0;
}
