#include <iostream>
#include <stdlib.h>
#include "TAD_ListaDupla.h"
using namespace std;

nave* criarNave(){
    nave *n = new nave;
    n->tail=NULL;
    n->head=NULL;
    return n;
}

void InserirNave(string Nome,nave *n){
    No* no = new No;
    no->nome=Nome;
    no->proximo=NULL;

    if(n->head==NULL){
        no->anterior=NULL;
        n->head=no;
        n->tail=no;
        
    }else{
        no->anterior=n->tail;//o anterior do novo no aponta para onde tail apontava
        n->tail->proximo=no;// o proxiimo dotail aponta para  novo no
        n->tail=no;//tail aponta para onde no apontava
    }
cout<<"\nnave "<<no->nome<<" inserida \n";

}
void removerNave(nave *n, string nomeBusca) {
    No* atual = n->head;

    while (atual != NULL) {
        if (atual->nome == nomeBusca) {
            if (atual == n->head) {
                n->head = atual->proximo;
                if (n->head != NULL) n->head->anterior = NULL;
                else n->tail=NULL;
            } 
            else if (atual == n->tail) {
                n->tail = atual->anterior;
                if (n->tail != NULL) n->tail->proximo = NULL;
            }
        
            else {
                atual->anterior->proximo = atual->proximo;//no atual pegar ponteiro do proximo do anterior e passa pro proximo do atual
                atual->proximo->anterior = atual->anterior;//o anterior do proximo vira o anterior no atual em vez do atual
            }

            delete atual;
            cout << "nave " << nomeBusca << " removido.\n";
            return;
        }
        atual = atual->proximo;
    }
    cout << "Nave nao encontrada no historico." << endl;
}
