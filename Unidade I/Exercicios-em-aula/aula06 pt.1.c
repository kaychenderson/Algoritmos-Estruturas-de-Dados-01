#include <stdio.h>

typedef enum diasSemana{
	SEGUNDA,
	TERCA,
	QUARTA,
	QUINTA,
	SEXTA,
	SABADO,
	DOMINGO
} DiasSemana;

int main(void){
	diasSemana dia;
	dia = SEGUNDA;
	printf("Dia da Semana: %d \n", dia);
	
	return 0;
}