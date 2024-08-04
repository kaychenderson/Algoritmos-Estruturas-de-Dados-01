/* Arquivo cabeçalho para tipo abstrato de dados (TAD) Aluno */

/* Tipo Expostado */
typedef struct aluno Aluno;

/* Função que aloca dinâmicamente uma struct aluno na memória */
Aluno * aloca_aluno(void);

/* Função para preencher o struct Aluno. A função recebe o endereço para aluno */
void preenche(Aluno *aluno);

/* Função para imprimir o struct Aluno. A função recebe o endereço para aluno */
void imprime(Aluno *aluno);