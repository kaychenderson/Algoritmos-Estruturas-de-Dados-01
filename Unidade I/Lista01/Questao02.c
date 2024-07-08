// Questão 02: Consedere o trecho do código abaixo:

#include <stdio.h>
int main(void) {
    int x, *p;
    x = 100;
    p = x;
    printf("Valor de p = %p \tValor de *p = %d", p, *p);
}

/* Se tentarmos compilar o programa (não o compile ainda), você acha que o compilador nos fornece alguma mensagem? Se sim, responda:
a) Esta mensagem é de erro ou advertência?
b) Por que o compilador emite tal mensagem?
c) Compile e execute o programa. A execução foi bem sucedida?
d) Modifique o trecho de código acima, de modo que nenhuma mensagem seja emitida pelo compilador.
e) Compile e execute novamente o programa. A execução foi bem sucedida?
*/ 

/*  Respostas: 
    a) Sim.
    b) Pois, a variável p é um ponteiro, ou seja, guarda um endereço de memória. Isso não occoreu na atribuição da variável, "p = x". Isso causaria um erro no printf, onde p não guardaria um endereço.
    c) Não.
    d) 
*/ 
    #include <stdio.h>
    int main(void){
        int x, *p;
        x = 100;
        p = &x; //A variável/ponteiro p agora recebe o endereço de memória
        printf("Valor de p = %p \tValor de *p = %d", p, *p);
    }

// e) Sim.