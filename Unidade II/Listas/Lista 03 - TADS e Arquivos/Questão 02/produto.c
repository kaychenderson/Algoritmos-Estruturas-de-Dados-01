#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

struct produto {
    int codigo;
    char descricao[100];
    int quantidade;
};

Produto* criarProduto(int codigo, char descricao[], int quantidade) {
    Produto* produto = (Produto*) malloc(sizeof(Produto));
    if (produto == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    produto->codigo = codigo;
    strcpy(produto->descricao, descricao);
    produto->quantidade = quantidade;
    return produto;
}

void adicionarProdutoAoEstoque(char nome_arquivo[], Produto* produto) {
    FILE *arq = fopen(nome_arquivo, "a"); // Modo de append para adicionar produtos
    if (arq == NULL) {
        printf("Não foi possível abrir o arquivo!\n");
        exit(1);
    }
    fprintf(arq, "%d\t%s\t%d\n", produto->codigo, produto->descricao, produto->quantidade);
    fclose(arq);
}

void removerProdutoDoEstoque(char nome_arquivo[], int codigo) {
    FILE *arq = fopen(nome_arquivo, "r");
    FILE *temp = fopen("temp.txt", "w"); // Arquivo temporário
    if (arq == NULL || temp == NULL) {
        printf("Não foi possível abrir o arquivo!\n");
        exit(1);
    }

    Produto produto;
    int encontrado = 0;

    while (fscanf(arq, "%d\t%s\t%d", &produto.codigo, produto.descricao, &produto.quantidade) == 3) {
        if (produto.codigo == codigo) {
            encontrado = 1; // Marca como encontrado
        } else {
            fprintf(temp, "%d\t%s\t%d\n", produto.codigo, produto.descricao, produto.quantidade); // Copia para o arquivo temporário
        }
    }

    fclose(arq);
    fclose(temp);

    if (encontrado) {
        remove(nome_arquivo); // Remove o arquivo original
        rename("temp.txt", nome_arquivo); // Renomeia o temporário
        printf("Produto com código %d removido do estoque.\n", codigo);
    } else {
        printf("Produto com código %d não encontrado no estoque.\n", codigo);
        remove("temp.txt"); // Remove o arquivo temporário, caso não seja encontrado
    }
}

void atualizarQuantidadeProduto(char nome_arquivo[], int codigo, int nova_quantidade) {
    FILE *arq = fopen(nome_arquivo, "r");
    FILE *temp = fopen("temp.txt", "w"); // Arquivo temporário
    if (arq == NULL || temp == NULL) {
        printf("Não foi possível abrir o arquivo!\n");
        exit(1);
    }

    Produto produto;
    int encontrado = 0;

    while (fscanf(arq, "%d\t%s\t%d", &produto.codigo, produto.descricao, &produto.quantidade) == 3) {
        if (produto.codigo == codigo) {
            produto.quantidade = nova_quantidade; 
            encontrado = 1;
        }
        fprintf(temp, "%d\t%s\t%d\n", produto.codigo, produto.descricao, produto.quantidade); 
    }

    fclose(arq);
    fclose(temp);

    if (encontrado) {
        remove(nome_arquivo); // Remove o arquivo original
        rename("temp.txt", nome_arquivo); // Renomeia o temporário
        printf("Quantidade do produto com código %d atualizada para %d.\n", codigo, nova_quantidade);
    } else {
        printf("Produto com código %d não encontrado no estoque.\n", codigo);
        remove("temp.txt"); // Remove o arquivo temporário se não foi encontrado
    }
}

void exibirEstoque(char nome_arquivo[]) {
    FILE *arq = fopen(nome_arquivo, "r");
    if (arq == NULL) {
        printf("Não foi possível abrir o arquivo!\n");
        exit(1);
    }

    Produto produto;
    printf("Produtos no estoque:\n");
    while (fscanf(arq, "%d\t%s\t%d", &produto.codigo, produto.descricao, &produto.quantidade) == 3) {
        printf("Código: %d, Descrição: %s, Quantidade: %d\n", produto.codigo, produto.descricao, produto.quantidade);
    }

    fclose(arq);
}
