#include <stdio.h>
#include <stdlib.h>

int main() {

    int numQuest;
    printf("Digite o número de questões da prova: ");
    scanf("%d", &numQuest);

    char *gabarito = (char *)malloc(numQuest*sizeof(char));
    printf("Digite o gabarito da prova: ");
    for (int index = 0; index < numQuest; index++) {
        scanf(" %c", &gabarito[index]);
    }

    char respostas[10][numQuest];

    for (int index = 0; index < 10; index++) {
        printf("Digite as respostas do aluno %d: ", index + 1);
        for (int count = 0; count < numQuest; count++) {
            scanf(" %c", &respostas[index][count]);
        }
    }

    float notas[10];
    int aprovados = 0;
    for (int index = 0; index < 10; index++) {

        int acertos = 0;
        for (int count = 0; count < numQuest; count++) {
            if (respostas[index][count] == gabarito[count]) {
                acertos++;
            }
        }

        notas[index] = (float)acertos*10 / numQuest;
        printf("+------------------------+\n");
        printf("| Nota do aluno %d: %.2f |\n", index + 1, notas[index]);
        printf("+------------------------+\n");
        if (notas[index] >= 6) {
            aprovados++;
        }

    }

    float percentApv = (float)aprovados / 10*100;

    printf("A porcentagem de aprovação foi: %.2f%% \n", percentApv);

    free(gabarito);

    return 0;
}