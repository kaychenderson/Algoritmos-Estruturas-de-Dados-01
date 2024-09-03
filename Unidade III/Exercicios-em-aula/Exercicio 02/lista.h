/* Arquivo cabeçalho */

/* Declaração da estrutura */
typedef struct no No;

/* Função que insere numeros inteiros em uma lista encadeada */
No* inserirInt(No* lista, int numero);

/* Função que imprime os numeros inteiros na lista */
void imprimirInt(No* lista);

/* Função para liberar memória alocada */
void liberarInt(No* lista);

/* Função que simula uma busca linear/sequencial por um numero inteiro */
No* buscarInt(int numero, No* lista);

/* Função para remover os numeros da lista */
No* removerInt(No* lista, int numero);