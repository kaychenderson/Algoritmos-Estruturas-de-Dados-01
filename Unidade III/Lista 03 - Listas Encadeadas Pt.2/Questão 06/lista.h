#ifndef LISTA_H
#define LISTA_H

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

typedef struct lista {
    TipoFigura tipo;
    void* figura;
    struct lista* prox;
} Lista;

Lista* cria_ret(float b, float h);
Lista* cria_tri(float b, float h);
Lista* cria_circ(float r);

float ret_area(Retangulo* r);
float tri_area(Triangulo* t);
float circ_area(Circulo* c);

float area(Lista* p);

float max_area(Lista* l);

#endif