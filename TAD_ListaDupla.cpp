#include <iostream>
#include "TAD_ListaDupla.h"
using namespace std;

Nave* criarNave(){
    Nave *n = new Nave;
    n->head = NULL;
    n->tail = NULL;
    return n;
}

void inserirNave(string nome, Nave *n){
    NoDuplo* no = new NoDuplo;
    no->nome = nome;
    no->proximo = NULL;

    if(n->head == NULL){
        no->anterior = NULL;
        n->head = no;
        n->tail = no;
    } else {
        no->anterior = n->tail;
        n->tail->proximo = no;
        n->tail = no;
    }

    cout << "\nNave " << no->nome << " inserida\n";
}

void removerNave(Nave *n, string nomeBusca){
    NoDuplo* atual = n->head;

    while(atual != NULL){
        if(atual->nome == nomeBusca){

            if(atual == n->head){
                n->head = atual->proximo;
                if(n->head != NULL)
                    n->head->anterior = NULL;
                else
                    n->tail = NULL;
            }
            else if(atual == n->tail){
                n->tail = atual->anterior;
                n->tail->proximo = NULL;
            }
            else{
                atual->anterior->proximo = atual->proximo;
                atual->proximo->anterior = atual->anterior;
            }

            delete atual;
            cout << "Nave " << nomeBusca << " removida\n";
            return;
        }

        atual = atual->proximo;
    }

    cout << "Nave nao encontrada\n";
}