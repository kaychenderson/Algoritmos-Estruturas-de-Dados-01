#include <stdio.h>
#include <stdlib.h>
#include "aluno.h" 

int main(void){
    Aluno * aluno = aloca_aluno();
    preenche(aluno); //Preenche
    imprime(aluno); //Imprime
    free(aluno); //Libera Memória
    return 0;
} 