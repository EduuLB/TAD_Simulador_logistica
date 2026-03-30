#ifndef TAD_LISTACIRCULAR_H
#define TAD_LISTACIRCULAR_H

#include <string>
using namespace std;

typedef struct NoCircular{
    string nome;
    NoCircular* proximo;
} NoCircular;

typedef struct ListaCircular{
    NoCircular* inicio;
} ListaCircular;

ListaCircular* criarListaCircular();
void inserirCamera(ListaCircular *lista, string nome);
void removerCamera(ListaCircular *lista, string nome);
void exibirCircular(ListaCircular *lista);

#endif