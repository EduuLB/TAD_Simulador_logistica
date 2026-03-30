#ifndef TAD_LISTADUPLA_H
#define TAD_LISTADUPLA_H

#include <string>
using namespace std;

typedef struct NoDuplo{
    string nome;
    NoDuplo* proximo;
    NoDuplo* anterior;
} NoDuplo;

typedef struct Nave{
    NoDuplo* head;
    NoDuplo* tail;
} Nave;

Nave* criarNave();
void inserirNave(string nome, Nave *n);
void removerNave(Nave *n, string nome);

#endif