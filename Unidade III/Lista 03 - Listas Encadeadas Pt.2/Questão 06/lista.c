#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lista.h"
#define pi 3.14159265358979323846

Lista* cria_ret(float b, float h) {
    Retangulo* r = (Retangulo*) malloc(sizeof(Retangulo));
    r->base = b;
    r->altura = h;
    
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->tipo = RETANGULO;
    novo->figura = r;
    novo->prox = NULL;
    
    return novo;
}

Lista* cria_tri(float b, float h) {
    Triangulo* t = (Triangulo*) malloc(sizeof(Triangulo));
    t->base = b;
    t->altura = h;
    
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->tipo = TRIANGULO;
    novo->figura = t;
    novo->prox = NULL;
    
    return novo;
}

Lista* cria_circ(float r) {
    Circulo* c = (Circulo*) malloc(sizeof(Circulo));
    c->raio = r;
    
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->tipo = CIRCULO;
    novo->figura = c;
    novo->prox = NULL;
    
    return novo;
}

float ret_area(Retangulo* r) {
    return r->base * r->altura;
}

float tri_area(Triangulo* t) {
    return (t->base * t->altura) / 2;
}

float circ_area(Circulo* c) {
    return pi * pow(c->raio, 2);
}

float area(Lista* p) {
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

float max_area(Lista* l) {
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