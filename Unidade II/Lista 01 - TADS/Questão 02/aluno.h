#include "disciplina.h"

typedef struct {
    char nome[100];
    int matricula;
    Disciplina* disciplinas[10];
    int num_disciplinas;
} Aluno;

// Função que cria um aluno
Aluno* criarAluno(char nome[], int matricula);

// Função que matricula um aluno em uma disciplina
void matricularAlunoDisciplina(Aluno* aluno, Disciplina* disciplina);

// Função que exclui um aluno
void excluirAluno(Aluno* aluno);