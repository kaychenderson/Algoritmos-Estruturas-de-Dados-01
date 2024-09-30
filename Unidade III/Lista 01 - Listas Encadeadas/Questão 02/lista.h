#ifndef LISTA_H
#define LISTA_H

typedef struct no {
    int valor;
    struct no* prox;
} No;

No* inserir_no_inicio(No* lista, int valor);
No* inserir_no_fim(No* lista, int valor);
void exibir_lista(No* lista);
No* remover_primeiro(No* lista);
int buscar(No* lista, int valor);
No* remover_valor(No* lista, int valor);
No* inserir_apos(No* lista, int valor, int novo_valor);
void liberar_lista(No* lista);

#endif
