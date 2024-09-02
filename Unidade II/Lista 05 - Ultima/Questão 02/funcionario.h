/* Arquivo cabeçalho pata Tipo Abstrato de Dados (TAD) Funcionario */

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#define MAX 100 // Definição de um valor máximo para o vetor de funcionários

// Definição da estrutura Funcionario
typedef struct funcionario Funcionario;


// Declaração das funções:

/* Função que aloca dinamicamente memória para um vetor de ponteiros para `Funcionario`.
   Retorna um ponteiro para o vetor alocado.
*/
Funcionario **aloca_funcionarios();

/* Função que libera a memória alocada para o vetor de ponteiros para `Funcionario`.
   Parâmetros:
   - Funcionario** funcionarios: Ponteiro para o vetor de funcionários.
   - int qnt: Quantidade de funcionários.
*/
void libera_funcionario(Funcionario **funcionarios, int qnt);

/* Função que busca um funcionário pelo ID.
   Parâmetros:
   - Funcionario** funcionarios: Ponteiro para o vetor de funcionários.
   - int id: ID do funcionário a ser buscado.
   - int qnt: Quantidade de funcionários.
   Retorna um ponteiro para o funcionário encontrado, ou NULL se não encontrado.
*/
Funcionario *busca_funcionario(Funcionario **funcionarios, int id, int qnt);

/* Função que adiciona um novo funcionário ao vetor de funcionários.
   Parâmetros:
   - Funcionario** funcionarios: Ponteiro para o vetor de funcionários.
   - char* nome: Nome do funcionário a ser adicionado.
   - int id: ID do funcionário a ser adicionado.
   - float salario: Salário do funcionário a ser adicionado.
   - int* qnt: Ponteiro para a quantidade de funcionários (atualizado após a adição).
   Retorna um ponteiro para o vetor de funcionários atualizado.
*/
Funcionario **adiciona_funcionario(Funcionario **funcionarios, char *nome, int id, float salario, int *qnt);

/* Função que remove um funcionário do vetor de funcionários com base no ID.
   Parâmetros:
   - Funcionario** funcionarios: Ponteiro para o vetor de funcionários.
   - int id: ID do funcionário a ser removido.
   - int* qnt: Ponteiro para a quantidade de funcionários (atualizado após a remoção).
   Retorna um ponteiro para o vetor de funcionários atualizado.
*/
Funcionario **remover_funcionario(Funcionario **funcionarios, int id, int *qnt);

/* Função que lista todos os funcionários.
   Parâmetros:
   - Funcionario** funcionarios: Ponteiro para o vetor de funcionários.
   - int qnt: Quantidade de funcionários.
*/
void listar_funcionarios(Funcionario **funcionarios, int qnt);

#endif // FUNCIONARIO_H