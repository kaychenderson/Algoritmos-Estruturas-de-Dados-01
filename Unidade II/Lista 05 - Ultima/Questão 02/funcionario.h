#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#define MAX 100 // DefiniÃ§Ã£o de um valor mÃ¡ximo para o vetor de funcionÃ¡rios

// DefiniÃ§Ã£o da estrutura Funcionario
typedef struct funcionario Funcionario;

// DeclaraÃ§Ã£o das funÃ§Ãµes
Funcionario **aloca_funcionarios();
void libera_funcionario(Funcionario **funcionarios, int qnt);
Funcionario *busca_funcionario(Funcionario **funcionarios, int id, int qnt);
Funcionario **adiciona_funcionario(Funcionario **funcionarios, char *nome, int id, float salario, int *qnt);
Funcionario **remover_funcionario(Funcionario **funcionarios, int id, int *qnt);
void listar_funcionarios(Funcionario **funcionarios, int qnt);

#endif // FUNCIONARIO_H