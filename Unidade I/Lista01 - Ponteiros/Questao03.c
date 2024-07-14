//Questão 03: Qual será a saída exibida pelo programa a seguir:

#include <stdio.h>
int main(void) {
    int a, b, c, d;
    int *p1;
    int *p2 = &a;
    int *p3 = &c;
    p1 = p2;
    *p2 = 10;
    b = 20;
    int **pp;
    pp = &p1;
    *p3 = **pp;
    int *p4 = &d;
    *p4 = b + (*p1)++;
    printf("%d\t%d\t%d\t%d\n", a, b, c, d);

    return 0;
}

/* Observe que, se int *p é uma variável do tipo ponteiro para inteiro, então int **pp é uma 
variável do tipo ponteiro para ponteiro de inteiro, isto é, uma varável que poderá armazenar o 
endereço de um ponteiro do tipo int. */

// Explicando linha por linha...

#include <stdio.h>
int main(void) {
    int a, b, c, d; //A variaveis (a, b, c, d) são declaradas
    int *p1; // O ponteiro p1 é declarado
    int *p2 = &a; //O ponteiro p2 recebe o endereço de a.
    int *p3 = &c; //O ponteiro p3 recebe o endereço de c.
    p1 = p2; // p1 receberá o endereço da variável que p2 aponta, ou seja, o &a.
    *p2 = 10; // O conteudo da variável que p2 aponta será 10, ou seja, "a = 10".
    b = 20; // "b = 20".
    int **pp; // Declaração de pp
    pp = &p1; // pp = &p1 = &a. Portanto, **pp=10
    *p3 = **pp; // O conteúdo da variável que p3 aponta, no caso, c. Será igual a **pp, que é 10. Logo, "c = 10".
    int *p4 = &d; //O ponteiro p4 recebe o endereço de d.
    *p4 = b + (*p1)++; /* O conteudo da variável que o p4 aponta, no caso d, será: 
                            d = b + (*p1)++ = 20 + 10++ = 30. Logo, "d = 30"
                            
                            E o (*p1)++, aumenta +1 no seu valor. Pois, sua adição só ocorrerá depois da soma em *p4.
                            Portanto, a = 10+1, "a = 11" 
    */ 
    printf("%d\t%d\t%d\t%d\n", a, b, c, d); 

    // Desse modo, será impresso: 11 20 10 30

    return 0;
}