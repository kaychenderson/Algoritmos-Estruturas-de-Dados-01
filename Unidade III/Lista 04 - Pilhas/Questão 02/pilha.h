#ifndef PILHA_H
#define PILHA_H

typedef struct pilha Pilha;

Pilha* pilha_cria(void);
void pilha_push(Pilha* p, float v);
float pilha_pop(Pilha* p);
int pilha_vazia(Pilha* p);
void pilha_libera(Pilha* p);

float topo(Pilha* p);
void concatena_pilhas(Pilha* p1, Pilha* p2);

#endif