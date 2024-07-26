#include <stdio.h>
#include <stdlib.h>

int main() {

    int num;
    printf("Informe o número de pessoas que foram entrevistadas: ");
    scanf("%d", &num);

    char *sexo = (char *)malloc(num*sizeof(char));
    char *opn = (char *)malloc(num*sizeof(char));

    for (int index = 0; index < num; index++) {
        printf("Informe o sexo da pessoa - (M / F): ");
        scanf("%c", &sexo[index]);
        if (sexo[index] != 'M' && sexo[index] != 'F' && sexo[index] != 'm' && sexo[index] != 'f') {
            printf("Opção inválida. Por favor, tente novamente. \n");
            index--; 
            continue; 
        }
        printf("Informe a opinião da pessoa - (S / N): ");
        scanf("%c", &opn[index]);
        if (opn[index] != 'S' && opn[index] != 'N' && opn[index] != 's' && opn[index] != 'n') {
            printf("Opção inválida, Por favor, tente novamente. \n");
            index--; // Decrementa o índice para tentar novamente
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

    double percentFgostou;
    if (feminino > 0) {
        percentFgostou = (double)femininoS / feminino * 100;
    } else {
        percentFgostou = 0;
    }

    double percentMnaoGostou;
    if (masculino > 0) {
        percentMnaoGostou = (double)masculinoN / masculino * 100;
    } else {
        percentMnaoGostou = 0;
    }

    printf("%.2f%% das Mulheres gostaram do Produto.\n", percentFgostou);
    printf("%.2f%% dos Homens não gostaram do Produto.\n", percentMnaoGostou);
    // %.2 = Imprimirá duas casas decimais após a virgula.    |    %% = Imprimirá o "%".

    free(sexo);
    free(opn);

    return 0;
}