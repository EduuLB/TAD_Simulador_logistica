    #include <iostream>
    #include <stdlib.h>
    #include <string>
    #include "TAD_fila.h"
    using namespace std;

fila* criarFila(){
    fila *f=(fila*)malloc(sizeof(fila));
    f->fim=NULL;
    f->inicio=NULL;
    return f;

}
void enqueue(fila *f, int ID){
    No *no=(No*)malloc(sizeof(No));
    no->id=ID;
    no->prox=NULL;
    if(f->inicio==NULL){
        f->inicio=no;
    }else{
        f->fim->prox=no;
    }
    f->fim=no;
    cout<<"\n aviao de id: "<<ID<<" esta na fila\n";

}

void dequeue(fila *f){
    No *no ;


    if(f->inicio==NULL){
        string erro= "a hangar esta vazio";
        cout<<erro;
    }
    else{
        
        no=f->inicio;
        f->inicio=f->inicio->prox;
        cout<<"\n o aviao de id %d esta saindo\n",no->id;
        delete(no);
       if (f->inicio == NULL) {
            f->fim = NULL;
        }


    }


}