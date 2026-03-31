    #include <iostream>
    #include "TAD_Fila.h"
    using namespace std;

    Fila* criarFila(){
        Fila *f= new Fila;
        f->fim=NULL;
        f->inicio=NULL;
        return f;

    }

    void enqueue(Fila *f, int id){
        NoFila *no= new NoFila;
        no->id = id;
        no->prox=NULL;

        if (f->inicio == NULL) {
            f->inicio = no;
            f->fim = no;
        } else {
            f->fim->prox = no;//proximo do fim nao aponta mais pra nulo aponta para onde no aponta
            f->fim = no;//f depois aponta para no dizendo que esta no ultimo da fila
        }

        cout<<"\n aviao de id: "<< id <<" esta na fila\n";

    }

    void dequeue(Fila *f){
        if(f->inicio == NULL){
            cout << "O hangar esta vazio";
            return;
        }
            NoFila *noFila = f->inicio;//novo no aponta para inicio da fila
            f->inicio = f->inicio->prox;//inicio pula para o proximo da fila

            cout << "\n o aviao de id " << noFila->id << " esta saindo\n";
            delete noFila;//apaga o antigo primeiro da fila pelo endereco de memoria apontado por nofila
            
            if (f->inicio == NULL) {
                f->fim = NULL;
            }
    }