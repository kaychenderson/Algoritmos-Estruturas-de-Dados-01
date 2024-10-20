/* Arquivo cabeçalho pata Tipo Abstrato de Dados (TAD) Produto */

/* Estrutura que representa um produto */
typedef struct produto Produto;

/* Função que aloca dinamicamente na memória uma struct Produto e retorna seu endereço.
Parâmetros:
    - int codigo: Código do produto.
    - char* descricao: Descrição do produto.
    - int quantidade: Quantidade do produto em estoque.
*/
Produto* criarProduto(int codigo, char descricao[], int quantidade);

/* Função que adiciona um produto ao estoque, salvando as informações em um arquivo.
Parâmetros:
    - char* nome_arquivo: Nome do arquivo onde o produto será adicionado.
    - Produto* produto: Ponteiro para a estrutura Produto que será adicionada.
*/
void adicionarProdutoAoEstoque(char nome_arquivo[], Produto* produto);

/* Função que remove um produto do estoque, baseado no código do produto.
Parâmetros:
    - char* nome_arquivo: Nome do arquivo onde o produto será removido.
    - int codigo: Código do produto a ser removido.
*/
void removerProdutoDoEstoque(char nome_arquivo[], int codigo);

/* Função que atualiza a quantidade de um produto em estoque.
Parâmetros:
    - char* nome_arquivo: Nome do arquivo onde o produto será atualizado.
    - int codigo: Código do produto cuja quantidade será atualizada.
    - int nova_quantidade: Novo valor da quantidade em estoque.
*/
void atualizarQuantidadeProduto(char nome_arquivo[], int codigo, int nova_quantidade);

/* Função que exibe todos os produtos presentes no estoque.
Parâmetros:
    - char* nome_arquivo: Nome do arquivo de onde os produtos serão exibidos.
*/
void exibirEstoque(char nome_arquivo[]);