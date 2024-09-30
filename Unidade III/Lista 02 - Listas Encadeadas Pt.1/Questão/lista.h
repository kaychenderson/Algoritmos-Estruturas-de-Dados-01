#ifndef LISTA_H
#define LISTA_H

typedef struct Lista {
    int info;
    struct Lista *prox;
} Lista;

Lista* cria_lista(void);
Lista* insere_inicio(Lista* l, int valor);
int maiores(Lista* l, int n);
Lista* ultimo(Lista* l);
Lista* concatena(Lista* l1, Lista* l2);
Lista* retira_n(Lista* l, int n);
void imprime_lista(Lista* l);
void libera_lista(Lista* l);

#endif