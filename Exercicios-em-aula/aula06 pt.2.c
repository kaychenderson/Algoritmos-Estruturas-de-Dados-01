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

int main(void){
	diasSemana dia;
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
	
	return 0;
}