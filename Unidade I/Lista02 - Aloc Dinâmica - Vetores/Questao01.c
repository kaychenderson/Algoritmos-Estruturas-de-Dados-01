/* Questão 1) Uma empresa fez uma pesquisa para saber se as pessoas gostaram ou não de um
novo produto. Um número N de pessoas de ambos os sexos foi entrevistado, e o questionário
consistia em apenas duas perguntas: (i) o sexo do entrevistado (M/F) e (ii) sua opinião sobre o
produto (gostou/não gostou). Escreva um programa em C que:
a) leia as respostas contidas no questionário e armazene-as em dois arrays vinculados,
um deles contendo a resposta para a primeira pergunta e o outro contendo a resposta
para a segunda pergunta.
b) determine a porcentagem de pessoas do sexo feminino que responderam que
gostaram do produto.
c) determine a porcentagem de pessoas do sexo masculino que responderam que não
gostaram do produto */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int num;
    printf("Informe o número de pessoas que foram entrevistadas: ");
    scanf("%d", &num);

    char *sexo = (char *)malloc(num * sizeof(char));
    char *opn = (char *)malloc(num * sizeof(char));

    for (int index = 0; index < num; index++) {
        printf("Informe o sexo da pessoa - (M / F): ");
        scanf(" %c", &sexo[index]); 
        if (sexo[index] != 'M' && sexo[index] != 'F' && sexo[index] != 'm' && sexo[index] != 'f') {
            printf("Opção inválida. Por favor, tente novamente. \n");
            index--; 
            continue; 
        }
        printf("Informe a opinião da pessoa - (S / N): ");
        scanf(" %c", &opn[index]); 
        if (opn[index] != 'S' && opn[index] != 'N' && opn[index] != 's' && opn[index] != 'n') {
            printf("Opção inválida. Por favor, tente novamente. \n");
            index--; 
        }
    }

    int feminino = 0, masculino = 0, femininoS = 0, masculinoN = 0;
    for (int index = 0; index < num; index++) {
        if (sexo[index] == 'F' || sexo[index] == 'f') {
            feminino++;
            if (opn[index] == 'S' || opn[index] == 's') {
                femininoS++;
            }
        } else if (sexo[index] == 'M' || sexo[index] == 'm') {
            masculino++;
            if (opn[index] == 'N' || opn[index] == 'n') {
                masculinoN++;
            }
        }
    }

    float percentFgostou;
    if (feminino > 0) {
        percentFgostou = (float)femininoS / feminino * 100;
    } else {
        percentFgostou = 0;
    }

    float percentMnaoGostou;
    if (masculino > 0) {
        percentMnaoGostou = (float)masculinoN / masculino * 100;
    } else {
        percentMnaoGostou = 0;
    }

    printf("%.2f%% das Mulheres gostaram do Produto.\n", percentFgostou);
    printf("%.2f%% dos Homens não gostaram do Produto.\n", percentMnaoGostou);

    free(sexo);
    free(opn);

    return 0;
}