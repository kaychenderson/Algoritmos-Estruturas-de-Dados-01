#ifndef LISTA_CIRC_H
#define LISTA_CIRC_H

// Definição da estrutura do nó
typedef struct no {
    int valor;
    struct no* prox;
} No;

// Funções declaradas
No* inserir_no_inicio(No* lista, int valor);
No* inserir_no_fim(No* lista, int valor);
void exibir_lista(No* lista);
No* buscar(No* lista, int valor);
No* remover_valor(No* lista, int valor);
No* remover_primeiro(No* lista);
No* remover_ultimo(No* lista);

#endif
