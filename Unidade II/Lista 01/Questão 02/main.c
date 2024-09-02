#include <stdio.h>
#include "aluno.h"
#include "disciplina.h"

int main() {
    // Criando disciplinas
    Disciplina* d1 = criarDisciplina("Alg. e Est. de Dados", 101);
    Disciplina* d2 = criarDisciplina("Calculo", 102);

    // Criando aluno
    Aluno* a1 = criarAluno("João Silva", 12345);

    // Matriculando aluno nas disciplinas
    matricularAlunoDisciplina(a1, d1);
    matricularAlunoDisciplina(a1, d2);

    // Exibindo informações do aluno
    printf("Aluno: %s\n", a1->nome);
    printf("Matrícula: %d\n", a1->matricula);
    printf("Disciplinas matriculadas:\n");
    for (int index = 0; index < a1->num_disciplinas; index++) {
        printf("  %s (Código: %d)\n", a1->disciplinas[index]->nome, a1->disciplinas[index]->codigo);
    }

    // Excluindo disciplinas e aluno
    excluirDisciplina(d1);
    excluirDisciplina(d2);
    excluirAluno(a1);

    return 0;
}

// gcc main.c aluno.c disciplina.c -o main
// ./main