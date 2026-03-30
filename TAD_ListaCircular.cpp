#include <iostream>
#include "TAD_ListaCircular.h"
using namespace std;

ListaCircular* criarListaCircular(){
    ListaCircular *lista = new ListaCircular;
    lista->inicio = NULL;
    return lista;
}

void inserirCamera(ListaCircular *lista, string nome){
    NoCircular *novo = new NoCircular;
    novo->nome = nome;

    // lista vazia
    if(lista->inicio == NULL){
        lista->inicio = novo;
        novo->proximo = novo; // aponta pra si mesmo
    }
    else{
        NoCircular *aux = lista->inicio;

        // vai até o último
        while(aux->proximo != lista->inicio){
            aux = aux->proximo;
        }

        aux->proximo = novo;
        novo->proximo = lista->inicio;
    }

    cout << "Camera " << nome << " inserida\n";
}

void removerCamera(ListaCircular *lista, string nome){
    if(lista->inicio == NULL){
        cout << "Lista vazia\n";
        return;
    }

    NoCircular *atual = lista->inicio;
    NoCircular *anterior = NULL;

    do {
        if(atual->nome == nome){

            // único elemento
            if(atual == lista->inicio && atual->proximo == lista->inicio){
                lista->inicio = NULL;
            }
            // removendo o primeiro
            else if(atual == lista->inicio){
                NoCircular *ultimo = lista->inicio;

                while(ultimo->proximo != lista->inicio){
                    ultimo = ultimo->proximo;
                }

                lista->inicio = atual->proximo;
                ultimo->proximo = lista->inicio;
            }
            else{
                anterior->proximo = atual->proximo;
            }

            delete atual;
            cout << "Camera removida\n";
            return;
        }

        anterior = atual;
        atual = atual->proximo;

    } while(atual != lista->inicio);

    cout << "Camera nao encontrada\n";
}

void exibirCircular(ListaCircular *lista){
    if(lista->inicio == NULL){
        cout << "Lista vazia\n";
        return;
    }

    NoCircular *aux = lista->inicio;

    cout << "\n--- CAMERAS ---\n";

    do {
        cout << aux->nome << " -> ";
        aux = aux->proximo;
    } while(aux != lista->inicio);
}