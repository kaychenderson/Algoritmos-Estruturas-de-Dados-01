#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

int main(void) {
    // Criar o arquivo vazio se não existir
    FILE *arq = fopen("estoque.txt", "w");
    if (arq != NULL) {
        fclose(arq);
    }

    // Adicionar produtos ao estoque
    Produto* produto1 = criarProduto(101, "Cadeira", 15);
    adicionarProdutoAoEstoque("estoque.txt", produto1);
    
    Produto* produto2 = criarProduto(102, "Mesa", 8);
    adicionarProdutoAoEstoque("estoque.txt", produto2);

    // Exibir estoque
    exibirEstoque("estoque.txt");

    // Atualizar a quantidade de um produto
    atualizarQuantidadeProduto("estoque.txt", 101, 20);

    // Exibir estoque após atualização
    exibirEstoque("estoque.txt");

    // Remover um produto do estoque
    removerProdutoDoEstoque("estoque.txt", 102);

    // Exibir estoque após remoção
    exibirEstoque("estoque.txt");

    // Liberar a memória alocada
    free(produto1);
    free(produto2);

    return 0;
}

//    gcc main.c produto.c -o main
//    ./main