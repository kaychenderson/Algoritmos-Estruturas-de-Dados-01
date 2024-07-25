#include <stdio.h>

typedef enum diasSemana{
	SEGUNDA = 2,
	TERCA,
	QUARTA,
	QUINTA,
	SEXTA,
	SABADO,
	DOMINGO
} DiasSemana;

typedef enum mesesAno{
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
} MesesAno;

int main(void){
	mesesAno mes;
	diasSemana dia;
	
	printf("Informe o mês do ano: (1 - 12) \n");
	scanf("%d", &mes);
	printf("Dia da Semana: (2 - 8) \n");
	scanf("%d", &dia);
	
	switch (dia){
		case SEGUNDA:
			printf(" Segunda-Feira \n");
			break;
		case TERCA:
			printf(" Terça-Feira \n");
			break;
		case QUARTA:
			printf(" Quarta-Feira \n");
			break;
		case QUINTA:
			printf(" Quinta-Feira \n");
			break;
		case SEXTA:
			printf(" Sexta-Feira \n");
			break;
		case SABADO:
			printf(" Sábado \n");
			break;
		case DOMINGO:
			printf(" Domingo \n");
			break;
		default:
			printf(" Opção Inválida! \n");
			break;
	}
	
	switch (mes){
		case JANEIRO:
			printf(" Janeiro \n");
			break;
		case FEVEREIRO:
			printf(" Fevereiro \n");
			break;
		case MARCO:
			printf(" Março \n");
			break;
		case ABRIL:
			printf(" Abril \n");
			break;
		case JUNHO:
			printf(" Julho \n");
			break;
		case JULHO:
			printf(" Julho \n");
			break;
		case AGOSTO:
			printf(" Agosto \n");
			break;
		case SETEMBRO:
			printf(" Setembro \n");
			break;
		case OUTUBRO:
			printf(" Outubro \n");
			break;
		case NOVEMBRO:
			printf(" Novembro \n");
			break;
		case DEZEMBRO:
			printf(" Dezembro \n");
			break;
		default:
			printf(" Opção Inválida! \n");
			break;
	}
	
	return 0;
}