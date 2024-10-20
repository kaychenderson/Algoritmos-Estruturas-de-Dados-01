#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "listahet.h"

ListaHet* cria_ret(float b, float h) {
    Retangulo* r = (Retangulo*) malloc(sizeof(Retangulo));
    r->base = b;
    r->altura = h;
    
    ListaHet* novo = (ListaHet*) malloc(sizeof(ListaHet));
    novo->tipo = RETANGULO;
    novo->figura = r;
    novo->prox = NULL;
    
    return novo;
}

ListaHet* cria_tri(float b, float h) {
    Triangulo* t = (Triangulo*) malloc(sizeof(Triangulo));
    t->base = b;
    t->altura = h;
    
    ListaHet* novo = (ListaHet*) malloc(sizeof(ListaHet));
    novo->tipo = TRIANGULO;
    novo->figura = t;
    novo->prox = NULL;
    
    return novo;
}

ListaHet* cria_circ(float r) {
    Circulo* c = (Circulo*) malloc(sizeof(Circulo));
    c->raio = r;
    
    ListaHet* novo = (ListaHet*) malloc(sizeof(ListaHet));
    novo->tipo = CIRCULO;
    novo->figura = c;
    novo->prox = NULL;
    
    return novo;
}

static float ret_area(Retangulo* r) {
    return r->base * r->altura;
}

static float tri_area(Triangulo* t) {
    return (t->base * t->altura) / 2;
}

static float circ_area(Circulo* c) {
    return M_PI * pow(c->raio, 2);
}

static float area(ListaHet* p) {
    switch (p->tipo) {
        case RETANGULO:
            return ret_area((Retangulo*) p->figura);
        case TRIANGULO:
            return tri_area((Triangulo*) p->figura);
        case CIRCULO:
            return circ_area((Circulo*) p->figura);
        default:
            return 0;
    }
}

float max_area(ListaHet* l) {
    float max = 0.0;
    while (l != NULL) {
        float a = area(l);
        if (a > max) {
            max = a;
        }
        l = l->prox;
    }
    return max;
}