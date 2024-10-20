#ifndef LISTA_H
#define LISTA_H

typedef struct funcionario Funcionario;

typedef struct lista_func ListaFunc;

float lstfunc_folha_pagto(ListaFunc* l, char depto);

ListaFunc* cria_no(Funcionario f);

ListaFunc* insere_funcionario(ListaFunc* l, Funcionario f);

Funcionario cria_funcionario(char depto, int mat, char nome[], float salario);

void exibe_funcionarios(ListaFunc* l);

#endif