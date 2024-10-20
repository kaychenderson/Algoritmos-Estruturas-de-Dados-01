// listahet.h
#ifndef LISTAHET_H
#define LISTAHET_H

typedef enum { 
    RETANGULO, 
    TRIANGULO, 
    CIRCULO 
} TipoFigura;

typedef struct {
    float base;
    float altura;
} Retangulo;

typedef struct {
    float base;
    float altura;
} Triangulo;

typedef struct {
    float raio;
} Circulo;

typedef struct listahet {
    TipoFigura tipo;
    void* figura;
    struct listahet* prox;
} ListaHet;

ListaHet* cria_ret(float b, float h);
ListaHet* cria_tri(float b, float h);
ListaHet* cria_circ(float r);

static float ret_area(Retangulo* r);
static float tri_area(Triangulo* t);
static float circ_area(Circulo* c);

static float area(ListaHet* p);

float max_area(ListaHet* l);

#endif