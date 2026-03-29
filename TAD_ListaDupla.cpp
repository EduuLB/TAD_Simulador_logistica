#include <iostream>
#include <stdlib.h>
#include "TAD_ListaDupla.h"
using namespace std;

nave* criarNave(){
    nave *n = new nave;
    n->tail=NULL;
    n->head=NULL;
}

void InserirNave(string Nome,nave *n){
    No* no = new No;
    no->nome=Nome;
    if(n->head==NULL){
        no->anterior=NULL;
        n->head=no;
        n->tail=no;
        
    }else{
        no->anterior=n->tail;
        n->tail->proximo=no;
        n->tail=no;
    }
cout<<"\nnave "<<no->nome<<" inserida \n";

}
void removerNave(nave *n, string nomeBusca) {
    No* atual = n->head;

    while (atual != NULL) {
        if (atual->nome == nomeBusca) {
            // Se for o primeiro (head)
            if (atual == n->head) {
                n->head = atual->proximo;
                if (n->head != NULL) n->head->anterior = NULL;
            } 
            // Se for o último (tail)
            else if (atual == n->tail) {
                n->tail = atual->anterior;
                if (n->tail != NULL) n->tail->proximo = NULL;
            }
            // Se estiver no meio
            else {
                atual->anterior->proximo = atual->proximo;
                atual->proximo->anterior = atual->anterior;
            }

            delete atual;
            cout << "Registro da nave " << nomeBusca << " removido." << endl;
            return;
        }
        atual = atual->proximo;
    }
    cout << "Nave nao encontrada no historico." << endl;
}
