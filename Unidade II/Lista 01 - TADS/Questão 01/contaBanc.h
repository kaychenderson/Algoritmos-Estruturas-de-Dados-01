/* Arquivo cabeçalho pata Tipo Abstrato de Dados (TAD) Aluno */

/* Tipo Exportado */
typedef struct ContaBancaria ContaBancaria;

/* Função que aloca dinâmicamente na memória uma struct conta e retorna seu endereço. 
Parâmetros:
    char* titular: Nome do titular da conta.
    int* numero: Número da conta.
    float* saldo: Saldo da conta.
*/
ContaBancaria *criarConta (char* titular, float saldo, int numero);

/* Função que simula a operação de depositar. 
Parâmetros:
    ContaBancaria* conta: Representa a conta bancária.
    dinheiro: Saldo para ser adicionado na conta.
*/
void depositar(ContaBancaria* conta, float dinheiro);

/* Função que simula a operação de sacar. 
Parâmetros:
    ContaBancaria* conta: Representa a conta bancária.
    valor: Valor que será decrementado do saldo da conta.
*/
void sacar(ContaBancaria* conta, float valor);

/* Função que retorna o saldo 
Parâmetros:
    ContaBancaria* conta: Representa a conta bancária.
*/
float saldo(ContaBancaria* conta);

/* Função que libera o espaço locado dinâmicamente para a estrutura. 
Parâmetros:
    ContaBancaria* conta: Representa a conta bancária.
*/
void excluirConta(ContaBancaria* conta);