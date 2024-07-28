#include <stdio.h>
#include <stdlib.h>

#define MAX_TURMAS 10
#define MAX_VAGAS 3

typedef struct aluno{
    int mat;
    char nome[81];
    float nota1;
    float nota2;
    float nota3;
    float media;
} Aluno;

typedef struct turma{
    char id; 
    int vagas;
    Aluno* alunos[MAX_VAGAS];
} Turma;

Turma* turmas[MAX_TURMAS];

Turma* criarTurma(char id) {
    Turma* novaTurma = (Turma*)malloc(sizeof(Turma));
    novaTurma->id = id;
    novaTurma->vagas = MAX_VAGAS;
    for (int index = 0; index < MAX_VAGAS; index++) {
        novaTurma->alunos[index] = NULL;
    }
    return novaTurma;
}

void matricularAluno(Turma* turma, int mat, char* nome) {
    if (turma->vagas > 0) {
        Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));
        novoAluno->mat = mat;
        int index;
        for (index = 0; nome[index] != '\0'; index++) {
            novoAluno->nome[index] = nome[index];
        }
        novoAluno->nome[index] = '\0'; 
        novoAluno->nota1 = 0;
        novoAluno->nota2 = 0;
        novoAluno->nota3 = 0;
        novoAluno->media = 0;
        
        for (index = 0; index < MAX_VAGAS; index++) {
            if (turma->alunos[index] == NULL) {
                turma->alunos[index] = novoAluno;
                turma->vagas--;
                break;
            }
        }
    } else {
        printf("Nao ha vagas disponiveis na turma %c\n", turma->id);
    }
}

void lancarNotas(Turma* turma) {
    for (int index = 0; index < MAX_VAGAS; index++) {
        if (turma->alunos[index] != NULL) {
            printf("Matricula: %d Aluno: %s\n", turma->alunos[index]->mat, turma->alunos[index]->nome);
            printf("Digite a nota 1: ");
            scanf("%f", &(turma->alunos[index]->nota1));
            printf("Digite a nota 2: ");
            scanf("%f", &(turma->alunos[index]->nota2));
            printf("Digite a nota 3: ");
            scanf("%f", &(turma->alunos[index]->nota3));
            turma->alunos[index]->media = (turma->alunos[index]->nota1 + turma->alunos[index]->nota2 + turma->alunos[index]->nota3) / 3;
        }
    }
}

void imprimirAlunos(Turma* turma) {
    for (int index = 0; index < MAX_VAGAS; index++) {
        if (turma->alunos[index] != NULL) {
            printf("+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n");
            printf("| Matricula: %d                                    |\n", turma->alunos[index]->mat);
            printf("| Nome: %s                                        \n", turma->alunos[index]->nome);
            printf("|------------------------------------------------+\n");
            printf("| Nota 1: %.2f                                    |\n", turma->alunos[index]->nota1);
            printf("| Nota 2: %.2f                                    |\n", turma->alunos[index]->nota2);
            printf("| Nota 3: %.2f                                    |\n", turma->alunos[index]->nota3);
            printf("| Media: %.2f                                     |\n", turma->alunos[index]->media);
            printf("+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n");
        }
    }
}

void imprimirTurmas(Turma** turmas, int tam) {
    for (int index = 0; index < tam; index++) {
        if (turmas[index] != NULL) {
            printf("Turma %c - %d vagas disponiveis\n", turmas[index]->id, turmas[index]->vagas);
        }
    }
}

Turma* procurarTurma(Turma** turmas, int tam, char id) {
    for (int index = 0; index < tam; index++) {
        if (turmas[index] != NULL && turmas[index]->id == id) {
            return turmas[index];
        }
    }
    return NULL;
}

int main() {
    int opcao, numTurmas = 0;
    char id, nome[81];
    int mat;
    Turma* turma;

    printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\n");
    printf("Este programa gerencia as turmas ofertadas, fornecendo as\n");
    printf("funcionalidades de matricula, lancamento de notas e listagem de alunos.\n");
    printf("Autor: Ada Lovelace Versao: 1.0\n\n");

    do {
        printf("+-=-=-=-=-=-=-=-=-=-=-=-=-+\n");
        printf("|          MENU:          |\n");
        printf("+-=-=-=-=-=-=-=-=-=-=-=-=-+\n");
        printf("|  1 - Criar turma        |\n");
        printf("|  2 - Listar turmas      |\n");
        printf("|  3 - Matricular aluno   |\n");
        printf("|  4 - Lancar notas       |\n");
        printf("|  5 - Listar alunos      |\n");
        printf("|  6 - Sair               |\n");
        printf("+-=-=-=-=-=-=-=-=-=-=-=-=-+\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (numTurmas < MAX_TURMAS) {
                    printf("Criando nova turma...\n");
                    printf("Digite um id: ");
                    scanf(" %c", &id);
                    turmas[numTurmas] = criarTurma(id);
                    numTurmas++;
                    printf("Turma - %c criada com sucesso!\n", id);
                } else {
                    printf("Numero maximo de turmas atingido!\n");
                }
                break;
            case 2:
                printf("Listando turmas...\n");
                imprimirTurmas(turmas, numTurmas);
                break;
            case 3:
                printf("Matriculando aluno...\n");
                printf("Digite o id da turma: ");
                scanf(" %c", &id);
                turma = procurarTurma(turmas, numTurmas, id);
                if (turma != NULL) {
                    printf("Digite a matricula: ");
                    scanf("%d", &mat);
                    getchar(); 
                    printf("Digite o nome: ");
                    scanf(" %[^\n]", nome);
                    matricularAluno(turma, mat, nome);
                    printf("Aluno matriculado com sucesso!\n");
                } else {
                    printf("Turma inexistente!\n");
                }
                break;
            case 4:
                printf("Lancando notas...\n");
                printf("Digite o id da turma: ");
                scanf(" %c", &id);
                turma = procurarTurma(turmas, numTurmas, id);
                if (turma != NULL) {
                    lancarNotas(turma);
                } else {
                    printf("Turma inexistente!\n");
                }
                break;
            case 5:
                printf("Listando alunos...\n");
                printf("Digite o id da turma: ");
                scanf(" %c", &id);
                turma = procurarTurma(turmas, numTurmas, id);
                if (turma != NULL) {
                    imprimirAlunos(turma);
                } else {
                    printf("Turma inexistente!\n");
                }
                break;
            case 6:
                printf("Obrigado por usar este programa!\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 6);

    // Liberando memória alocada
    for (int i = 0; i < numTurmas; i++) {
        for (int j = 0; j < MAX_VAGAS; j++) {
            if (turmas[i]->alunos[j] != NULL) {
                free(turmas[i]->alunos[j]);
            }
        }
        free(turmas[i]);
    }

    return 0;
}