    #include <iostream>
    #include "TAD_fila.h"
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
            f->fim->prox = no;
            f->fim = no;
        }

        cout<<"\n aviao de id: "<< id <<" esta na fila\n";

    }

    void dequeue(Fila *f){
        if(f->inicio == NULL){
            cout << "O hangar esta vazio";
            return;
        }
            NoFila *noFila = f->inicio;
            f->inicio = f->inicio->prox;

            cout << "\n o aviao de id " << noFila->id << " esta saindo\n";
            delete noFila;
            
            if (f->inicio == NULL) {
                f->fim = NULL;
            }
    }