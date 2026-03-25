#include <iostream>
#include "ListaSimples.h"
using namespace std;

Lista criarLista(){
    Lista *lista = (ListaSimples*)calloc(1, sizeof(ListaSimples));
    lista->inicio = NULL;
    return lista;
}

No criarNo(Lista lista, int valor){
    No *no = (No*)calloc(1, sizeof(No));
    No *no = new No;
    no->valor = valor;
    no->proximo = NULL;
}

void inserirCarga(Lista lista, int valor);

void removerCarga(Lista lista, int valor);

