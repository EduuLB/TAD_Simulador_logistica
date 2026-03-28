
    #include <iostream>
    #include <stdlib.h>
    #include <string>
    #include "TAD_logs.h"

    using namespace std;
    

/*ypedef struct No{
    No *prox;
    string log;
}No;*/


pilha* criarpilhaLog(){
    pilha *p= (pilha*)malloc(sizeof(pilha));
    p=NULL;
    return p;

}
void pushLog(pilha *p,string l){
        pilha *novo=(pilha*)malloc(sizeof(pilha));
        novo->log=l;
        novo->anterior=p;
        p=novo;
        cout<<"log empilhado"<<novo->log;

    }

void popLog(pilha *p){


        if(p==NULL){cout<<"pilha vazia\n";}
        else{
        pilha *aux=p;
        p=p->anterior;
        cout<<"\nvalor do log desempilhado: \n"<<aux->log;
        free(aux);
        }


    }