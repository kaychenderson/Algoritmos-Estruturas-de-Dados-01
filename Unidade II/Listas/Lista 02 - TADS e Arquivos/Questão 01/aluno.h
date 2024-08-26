typedef struct aluno Aluno;

// Função para criar um aluno
Aluno* criarAluno(int mat, char nome[], float media);

// Função para salvar um aluno em um arquivo
void salvarAlunoEmArquivo(char nome_arquivo[], Aluno* aluno);

// Função para exibir todos os alunos cadastrados em um arquivo
void exibirAlunos(char nome_arquivo[]);



//   gcc main.c aluno.c -o main
//   ./main