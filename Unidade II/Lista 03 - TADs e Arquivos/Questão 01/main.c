#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

int main(void) {
    // Criar o arquivo vazio se não existir
    FILE *arq = fopen("alunos.txt", "w");
    if (arq != NULL) {
        fclose(arq);
    }

    // Criar um aluno
    Aluno* aluno1 = criarAluno(123, "Maria", 8.5);
    
    // Salvar aluno no arquivo
    salvarAlunoEmArquivo("alunos.txt", aluno1);
    
    // Exibir alunos cadastrados
    exibirAlunos("alunos.txt");

    // Liberar a memória alocada
    free(aluno1);

    return 0;
}

//   gcc main.c aluno.c -o main
//   ./main