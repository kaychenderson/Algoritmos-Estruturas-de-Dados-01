/* Arquivo cabeçalho para Tipos Abstrados de Dados - (TAD's) Disciplina */

#ifndef DISCIPLINA_H
#define DISCIPLINA_H

typedef struct {
    char nome[100];
    int codigo;
} Disciplina;

/* Função que aloca dinamicamente na memória uma struct Disciplina e retorna seu endereço. 
Parâmetros:
    - char* nome: Nome da disciplina.
    - int codigo: Código da disciplina.
*/
Disciplina* criarDisciplina(char nome[], int codigo);

/* Função que libera o espaço alocado dinamicamente para a estrutura Disciplina. 
Parâmetros:
    - Disciplina* disciplina: Representa a disciplina a ser excluída.
*/
void excluirDisciplina(Disciplina* disciplina);

#endif 