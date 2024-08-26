#include <stdio.h>
#include "aluno.h"
#include "disciplina.h"

int main() {
    // Criando disciplinas
    Disciplina* d1 = cria_disciplina("Alg. e Est. de Dados", 101);
    Disciplina* d2 = cria_disciplina("Calculo", 102);

    // Criando aluno
    Aluno* a1 = cria_aluno("João Silva", 12345);

    // Matriculando aluno nas disciplinas
    matricula_disciplina(a1, d1);
    matricula_disciplina(a1, d2);

    // Exibindo informações do aluno
    printf("Aluno: %s\n", a1->nome);
    printf("Matrícula: %d\n", a1->matricula);
    printf("Disciplinas matriculadas:\n");
    for (int i = 0; i < a1->num_disciplinas; i++) {
        printf("  %s (Código: %d)\n", a1->disciplinas[i]->nome, a1->disciplinas[i]->codigo);
    }

    // Excluindo disciplinas e aluno
    exclui_disciplina(d1);
    exclui_disciplina(d2);
    exclui_aluno(a1);

    return 0;
}