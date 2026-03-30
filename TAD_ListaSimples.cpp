#include <iostream>
#include "TAD_ListaSimples.h"
using namespace std;

ListaSimples* criarListaSimples(){
    ListaSimples *listaSimples = new ListaSimples;
    listaSimples->inicio = NULL;
    listaSimples->final = NULL;
    return listaSimples;
}

NoSimples* criarNoSimples(int valor){
    NoSimples *noSimples = new NoSimples;
    noSimples->valor = valor;
    noSimples->proximo = NULL;
    return noSimples;
}

void inserirCarga(ListaSimples *listaSimples, int valor){
    NoSimples *noSimples = criarNoSimples(valor);

    noSimples->proximo = listaSimples->inicio;
    listaSimples->inicio = noSimples;

    if(listaSimples->inicio == NULL){
        listaSimples->final = noSimples;
    }
}

void removerCarga(ListaSimples *listaSimples, int valor){

    NoSimples *noSimples = listaSimples->inicio;
    NoSimples *noAnterior = NULL;

    while (noSimples != NULL){
        if(noSimples->valor == valor){

            if(noAnterior == NULL){
                listaSimples->inicio = noSimples->proximo;
            } else {
                noAnterior->proximo = noSimples->proximo;
            }
            if(noSimples == listaSimples->final) {
                listaSimples->final = noAnterior;
            }
            delete noSimples;
            return;
        }
        noAnterior = noSimples;
        noSimples = noSimples->proximo;
    }
}

void exibirCarga(ListaSimples *listaSimples) {
    NoSimples *noSimples = listaSimples->inicio;

    while (noSimples != NULL){
        cout << noSimples->valor << " - ";
        noSimples = noSimples->proximo;
    }
}
