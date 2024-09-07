#include <stdio.h>
#include <stdlib.h>

#define MAX_TURMAS 10
#define MAX_VAGAS 3

typedef struct aluno {
    int mat;
    char nome[81];
    float notas[3];
    float media;
} Aluno;

typedef struct turma {
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
        for (int i = 0; i < 3; i++) {
            novoAluno->notas[i] = 0;
        }
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
            float soma = 0;
            for (int i = 0; i < 3; i++) {
                printf("Digite a nota %d: ", i + 1);
                scanf("%f", &(turma->alunos[index]->notas[i]));
                soma += turma->alunos[index]->notas[i];
            }
            turma->alunos[index]->media = soma / 3;
        }
    }
}

void imprimirAlunos(Turma* turma) {
    for (int index = 0; index < MAX_VAGAS; index++) {
        if (turma->alunos[index] != NULL) {
            printf("+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n");
            printf("| Matricula: %d                                  |\n", turma->alunos[index]->mat);
            printf("| Nome: %s                                       \n", turma->alunos[index]->nome);
            printf("|------------------------------------------------+\n");
            for (int i = 0; i < 3; i++) {
                printf("| Nota %d: %.2f                                  |\n", i + 1, turma->alunos[index]->notas[i]);
            }
            printf("| Media: %.2f                                    |\n", turma->alunos[index]->media);
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

/* Questão 1) Escreva um programa em C que manipula dados dos alunos da disciplina de
Algoritmos e Estruturas de Dados I da UFERSA Pau dos Ferros. Seu programa deverá utilizar os
tipos estruturados e o vetor definidos a seguir:
struct aluno {
 int mat;
 char nome[81];
 float notas[3];
 float media;
};
typedef struct aluno Aluno;
struct turma {
 char id; // caractere que identifica a turma, por exemplo, A ou B 
 int vagas; // números de vagas disponíveis para fechar a turma 
 Aluno* alunos[MAX_VAGAS];
};
typedef struct turma Turma;
Turma* turmas[MAX_TURMAS];
Deve-se levar em consideração que é ofertado um número máximo de turmas (definido pela
constante simbólica MAX_TURMAS) e um número máximo de vagas para cada turma (definido
pela constante simbólica MAX_VAGAS). Sabendo dessas informações, faça o que se pede nos
itens a seguir: 
a) Implemente uma função que cria uma turma, fornecendo-lhe um identificador.
Essa função deve ser responsável por indicar que a turma não tem alunos
matriculados, atribuindo a constante NULL a cada um dos elementos do vetor de
ponteiros.
Protótipo: Turma* cria_turma(char id);
b) Implemente uma função que recebe os dados de um aluno e o matricula em uma
das turmas, caso haja vaga disponível. Inicialize suas notas com zero.
Protótipo: void matricula_aluno(Turma* turma, int mat, char* nome);
c) Implemente uma função que lança as notas e calcula a média dos alunos de uma
determinada turma.
Protótipo: void lanca_notas(Turma* turma);
d) Implemente uma função que imprime os dados de todos os alunos de uma turma.
Protótipo: void imprime_alunos(Turma* turma);
e) Implemente uma função que imprime os dados de todas as turmas.
Protótipo: void imprime_turmas(Turma** turmas, int n);
f) Implemente uma função para procurar uma turma.
Protótipo: Turma* procura_turma(Turma** turmas, int n, char id);
OBS.: Forneça um menu de interação com o usuário, tomando como base o exemplo de
execução a seguir (o texto em negrito representa a entrada do usuário): */