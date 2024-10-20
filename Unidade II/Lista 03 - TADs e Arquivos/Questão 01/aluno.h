/* Arquivo cabeçalho para Tipos Abstrados de Dados - (TAD) Aluno*/

/* Estrutura que representa um aluno */
typedef struct aluno Aluno;

/* Função que aloca dinamicamente na memória uma struct Aluno e retorna seu endereço.
Parâmetros:
    - int mat: Número de matrícula do aluno.
    - char* nome: Nome do aluno.
    - float media: Média do aluno.
*/
Aluno* criarAluno(int mat, char nome[], float media);

/* Função que salva os dados de um aluno em um arquivo.
Parâmetros:
    - char* nome_arquivo: Nome do arquivo onde o aluno será salvo.
    - Aluno* aluno: Ponteiro para a estrutura Aluno que será salva.
*/
void salvarAlunoEmArquivo(char nome_arquivo[], Aluno* aluno);

/* Função que exibe todos os alunos cadastrados em um arquivo.
Parâmetros:
    - char* nome_arquivo: Nome do arquivo de onde os alunos serão exibidos.
*/
void exibirAlunos(char nome_arquivo[]);