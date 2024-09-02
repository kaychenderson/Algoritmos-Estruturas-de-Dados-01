#include "funcionario.h"

struct funcionario{
    char nome[50];
    int id;
    float salario;
};

Funcionario **remover_funcionario(Funcionario **funcionario, int id, int *qnt){
    int i;
    for (i = 0; i < (*qnt); i++){
        if (funcionario[i]->id == id){
            break;
        }
    }
    free(funcionario[i]);
    for (int j = i; j < (*qnt); j++){
        funcionario[j] = funcionario[j + 1];
    }

    funcionario[(*qnt)] == NULL;
    (*qnt)--;
    return funcionario;
}

Funcionario **aloca_funcionarios(){
    Funcionario **new = (Funcionario **)malloc(sizeof(Funcionario *) * MAX);
    if (new == NULL){
        printf("ERRO");
        exit(1);
    }
    return new;
}

void libera_funcionario(Funcionario **funcionarios, int qnt){
    for (int i = 0; i < qnt; i++){
        free(funcionarios[i]);
    }
    free(funcionarios);
}

Funcionario *busca_funcionario(Funcionario **funcionarios, int id, int qnt){
    for (int i = 0; i < qnt; i++){
        if (funcionarios[i]->id == id){
            return funcionarios[i];
        }
    }
    return NULL;
}

Funcionario **adiciona_funcionario(Funcionario **funcionarios, char *nome, int id, float salario, int *qnt){
    funcionarios[(*qnt)] = (Funcionario *)malloc(sizeof(Funcionario));
    if (funcionarios[(*qnt)] == NULL){
        printf("ERRO");
        exit(1);
    }
    funcionarios[(*qnt)]->id = id;
    funcionarios[(*qnt)]->salario = salario;
    strcpy(funcionarios[(*qnt)]->nome, nome);
    (*qnt)++;
    return funcionarios;
}

void listar_funcionarios(Funcionario **funcionarios, int qnt){
    for (int i = 0; i < qnt; i++){
        printf("Nome:%s\tId:%d\tSalario:%.2f\n", funcionarios[i]->nome,
               funcionarios[i]->id, funcionarios[i]->salario);
    }
}