#include <stdio.h>

#define QTD_FUNC 3

typedef struct {
    char nome[50];
    float salario;
    int id;
    char cargo[50];
} Funcionario;

void preencherFuncionario(Funcionario *p) {
    printf("Informe o nome do funcionário: ");
    scanf(" %[^\n]", p->nome);  
    printf("Informe o salário do funcionário: ");
    scanf("%f", &p->salario);
    printf("Informe o identificador do funcionário: ");
    scanf("%d", &p->id);
    printf("Informe o cargo do funcionário: ");
    scanf(" %[^\n]", p->cargo);  
}

void imprimirFuncionario(Funcionario *p) {
    printf("Nome: %s\n", p->nome);
    printf("Salário: %.2f\n", p->salario);
    printf("Identificador: %d\n", p->id);
    printf("Cargo: %s\n", p->cargo);
}

void altSalario(Funcionario funcionarios[], int tamanho, int id, float novoSalario) {
    for (int index = 0; index < tamanho; index++) {
        if (funcionarios[index].id == id) {
            funcionarios[index].salario = novoSalario;
            printf("O salário do funcionário: %s - (ID: %d) foi alterado com sucesso para: %.2f\n", funcionarios[index].nome, id, novoSalario);
        }
    }
    printf("Funcionário ID informado não encontrado.\n");
}

void imprimirMaiorMenorSalario(Funcionario funcionarios[], int tamanho) {
    Funcionario *maiorSalario = &funcionarios[0];
    Funcionario *menorSalario = &funcionarios[0];

    for (int index = 1; index < tamanho; index++) {
        if (funcionarios[index].salario > maiorSalario->salario) {
            maiorSalario = &funcionarios[index];
        }
        if (funcionarios[index].salario < menorSalario->salario) {
            menorSalario = &funcionarios[index];
        }
    }

    printf("Funcionário com maior salário:\n");
    printf("Cargo: %s | Salário: %.2f\n", maiorSalario->cargo, maiorSalario->salario);
    printf("Funcionário com menor salário:\n");
    printf("Cargo: %s | Salário: %.2f\n", menorSalario->cargo, menorSalario->salario);
}

int main() {
    Funcionario funcionarios[QTD_FUNC];

    for (int index = 0; index < QTD_FUNC; index++) {
        printf("Preenchendo dados do funcionário %d:\n", index + 1);
        preencherFuncionario(&funcionarios[index]);
    }

    for (int index = 0; index < QTD_FUNC; index++) {
        printf("\nDados do funcionário %d:\n", index + 1);
        imprimirFuncionario(&funcionarios[index]);
    }

    int id;
    float novoSalario;
    printf("\nDigite o identificador do funcionário que o salario será alterado: ");
    scanf("%d", &id);
    printf("Digite o novo salario: ");
    scanf("%f", &novoSalario);

    altSalario(funcionarios, QTD_FUNC, id, novoSalario);

    imprimirMaiorMenorSalario(funcionarios, QTD_FUNC);

    return 0;
}