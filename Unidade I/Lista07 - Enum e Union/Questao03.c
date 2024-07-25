include <stdio.h>

typedef enum meses {
    JANEIRO = 1,
    FEVEREIRO,
    MARCO,
    ABRIL,
    MAIO,
    JUNHO,
    JULHO,
    AGOSTO,
    SETEMBRO,
    OUTUBRO,
    NOVEMBRO,
    DEZEMBRO
} Meses;

typedef struct data {
    int dia;
    Meses mes;
    int ano;
} Data;

void preenche(Data * data) {
    do {
        printf("Informe o dia (1 - 31): \n");
        scanf("%d", &data->dia);
        if (data->dia < 1 || data->dia > 31) {
            printf("Dia inválido. Tente novamente.\n");
        }
    } while (data->dia < 1 || data->dia > 31);

    printf("+-=-+-=-+-=-+-=-+-=-+-=-+\n");
    printf("|     Informe o mês:    |\n");
    printf("+-=-+-=-+-=-+-=-+-=-+-=-+\n");
    printf("|  1- Janeiro           |\n");
    printf("|  2- Fevereiro         |\n");
    printf("|  3- Março             |\n");
    printf("|  4- Abril             |\n");
    printf("|  5- Maio              |\n");
    printf("|  6- Junho             |\n");
    printf("|  7- Julho             |\n");
    printf("|  8- Agosto            |\n");
    printf("|  9- Setembro          |\n");
    printf("|  10- Outubro          |\n");
    printf("|  11- Novembro         |\n");
    printf("|  12- Dezembro         |\n");
    printf("+-=-+-=-+-=-+-=-+-=-+-=-+\n");

    do {
        scanf("%d", &data->mes);
        if (data->mes < 1 || data->mes > 12) {
            printf("Mês inválido. Tente novamente.\n");
        }
    } while (data->mes < 1 || data->mes > 12);

    printf("Informe o ano: \n");
    scanf("%d", &data->ano);
}

void imprime(Data * data) {
    printf("Dados informados: \n");
    printf("Data: %02d/%02d/%04d\n", data->dia, data->mes, data->ano);
}

int main() {
    Data data;

    preenche(&data);
    imprime(&data);

    return 0;
}