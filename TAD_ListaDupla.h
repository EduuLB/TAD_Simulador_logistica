#ifndef TAD_LISTADUPLA_H
#define TAD_LISTADUPLA_H

typedef struct No{
    string nome;
    No* proximo;
    No* anterior;
}No;

typedef struct naves{
    No* tail;
    No* head;
}nave;



nave* criarNave(){
    nave *n = new nave;
    n->tail=NULL;
    n->head=NULL;
}

void InserirNave(string Nome,naven *n){
    No* no = new No;
    no->nome=Nome;
    if(n->head==NULL){

    }


}




#endif