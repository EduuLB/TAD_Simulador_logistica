#include <iostream>
#include "TAD_ListaSimples.h"
using namespace std;

ListaSimples* criarListaSimples(){
    //quando cria o tail e heado aponta pra nulo
    ListaSimples *listaSimples = new ListaSimples;
    listaSimples->inicio = NULL;
    listaSimples->final = NULL;
    return listaSimples;//retorna um poonteiro p lista
}

NoSimples* criarNoSimples(int valor){
    NoSimples *noSimples = new NoSimples;
    noSimples->valor = valor;//poe o valor no no criado
    noSimples->proximo = NULL;//e diz que o proximo liga ao nulo ja que vai ser o ultimo
    return noSimples;
}

void inserirCarga(ListaSimples *listaSimples, int valor){
    NoSimples *noSimples = criarNoSimples(valor);//cria o no com o valir

    noSimples->proximo = listaSimples->inicio;//o final proximo do no aponta para onde o
    //inicio da lista aponta
    listaSimples->inicio = noSimples;
    //inicio da lista agora aponta para no

    if(listaSimples->inicio == NULL){
        listaSimples->final = noSimples;
    }
}

void removerCarga(ListaSimples *listaSimples, int valor){

    NoSimples *noSimples = listaSimples->inicio;
    NoSimples *noAnterior = NULL;

    while (noSimples != NULL){
        if(noSimples->valor == valor){//caso achar o valor a remover 

            if(noAnterior == NULL){//caso o no anterior seja nulo
                listaSimples->inicio = noSimples->proximo;//inicio aponta
                //para o prroximo do no simples
            } else {
                noAnterior->proximo = noSimples->proximo;
                //caso nao seja nulo o proximo do anterior aponta pro prox do no simples
                //deixando no simpes a esmo

            }
            if(noSimples == listaSimples->final) {//caso o no for igual ao final da lista
                listaSimples->final = noAnterior;//o final vai apontar para o anterior
            }
            delete noSimples;//limpa a memoria a ser apagada que ja esta fora do no
            return;
        }
        noAnterior = noSimples;// no anterior copia posicao do no 
        noSimples = noSimples->proximo;//no simples pula pro proximo deixando o anterior 
        //anterior ainda ce acredita?
    }
}

void exibirCarga(ListaSimples *listaSimples) {
    NoSimples *noSimples = listaSimples->inicio;

    while (noSimples != NULL){
        cout << noSimples->valor << " - ";
        noSimples = noSimples->proximo;
    }
}
