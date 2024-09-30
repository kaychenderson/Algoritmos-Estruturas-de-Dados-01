#ifndef LISTA_CIRC_H
#define LISTA_CIRC_H

typedef struct no {
    int valor;
    struct no* prox;
} No;

No* inserir_no_inicio(No* lista, int valor);
No* inserir_no_fim(No* lista, int valor);
void exibir_lista(No* lista);

#endif