// lista.h
#ifndef LISTA_H
#define LISTA_H

// Definição da estrutura para o nó da lista
typedef struct no {
    int valor;
    struct no* prox;
} No;

// Funções declaradas para manipulação da lista encadeada
No* inserir_no_inicio(No* lista, int valor);
No* inserir_no_fim(No* lista, int valor);
void exibir_lista(No* lista);
No* remover_primeiro(No* lista);
void liberar_lista(No* lista);

#endif