#ifndef LISTA2_H
#define LISTA2_H

/* TAD: lista de inteiros */
typedef struct lista2 Lista2;

Lista2* lst2_cria(void);
void lst2_libera(Lista2* l);
Lista2* lst2_insere(Lista2* l, int v);
Lista2* lst2_retira(Lista2* l, int v);
int lst2_vazia(Lista2* l);
Lista2* lst2_busca(Lista2* l, int v);
void lst2_imprime(Lista2* l);

#endif
