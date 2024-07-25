#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    printf("Inforne o número de pessoas que foram entrevistadas: ");
    scanf("%d", &num);

    char *sexo = (char *)malloc(num * sizeof(char));
    char *opn = (char *)malloc(num * sizeof(char));

    for (int index = 0; index < num; index++) {
        printf("Informe o sexo da pessoa - (M / F): ");
        scanf(" %c", &sexo[index]);
        printf("Informe a opinião da pessoa - (S / N): ");
        scanf(" %c", &opn[index]);
    }

    int feminino = 0, masculino = 0, femininoS = 0, masculinoN = 0;
    for (int index = 0; index < num; index++){
        if (sexo[index] == 'F'){
            feminino++;
            if (opn[index] == 'S'){
                femininoS++;
            }
        } else if (sexo[index] == 'M'){
            masculino++;
            if (opn[index] == 'N'){
                masculinoN++;
            }
        }
    }

    double percentFgostou;
    if (feminino > 0){
        percentFgostou = (double)femininoS / feminino*100;
    } else {
        percentFgostou = 0;
    }

    double percentMnaoGostou;
    if (masculino > 0){
        percentMnaoGostou = (double)masculinoN / masculino*100;
    } else {
        percentMnaoGostou = 0;
    }

    printf("%.2f%% das Mulheres gostaram do Produto. \n", percentFgostou);
    printf("%.2f%% dos Homens não gostaram do Produto. \n", percentMnaoGostou);
    // %.2 = Imprimirá duas casas decimais após a virgula.    |    %% = Imprimirá o "%".
    free(sexo);
    free(opn);

    return 0;
}