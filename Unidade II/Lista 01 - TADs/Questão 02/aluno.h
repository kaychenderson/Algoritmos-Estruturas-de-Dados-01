/* Arquivo cabeçalho pata Tipo Abstrato de Dados (TAD) Aluno */

#include "disciplina.h"

typedef struct {
    char nome[100];
    int matricula;
    Disciplina* disciplinas[10];
    int num_disciplinas;
} Aluno;

/* Função que aloca dinamicamente na memória uma struct Aluno e retorna seu endereço. 
Parâmetros:
    - char* nome: Nome do aluno.
    - int matricula: Número de matrícula do aluno.
*/
Aluno* criarAluno(char nome[], int matricula);

/* Função que matricula um aluno em uma disciplina. 
Parâmetros:
    - Aluno* aluno: Representa o aluno a ser matriculado.
    - Disciplina* disciplina: Representa a disciplina em que o aluno será matriculado.
*/
void matricularAlunoDisciplina(Aluno* aluno, Disciplina* disciplina);

/* Função que libera o espaço alocado dinamicamente para a estrutura Aluno. 
Parâmetros:
    - Aluno* aluno: Representa o aluno a ser excluído.
*/
void excluirAluno(Aluno* aluno);