typedef struct produto Produto;

// Função para criar um produto
Produto* criarProduto(int codigo, char descricao[], int quantidade);

// Função para adicionar um produto ao estoque
void adicionarProdutoAoEstoque(char nome_arquivo[], Produto* produto);

// Função para remover um produto do estoque
void removerProdutoDoEstoque(char nome_arquivo[], int codigo);

// Função para atualizar a quantidade em estoque de um produto
void atualizarQuantidadeProduto(char nome_arquivo[], int codigo, int nova_quantidade);

// Função para exibir todos os produtos no estoque
void exibirEstoque(char nome_arquivo[]);