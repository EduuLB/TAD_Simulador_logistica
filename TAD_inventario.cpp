#include <iostream>
#include <stdlib.h>
#include "TAD_inventario.h"
using namespace std;


No* _criarNo(float peso, string carga_nome) {
    No* no = new No;
    no->peso = peso;
    no->nome = carga_nome;
    no->proximo = NULL;
    return no;
}

cargas* criarInventario(){
    cargas *inv = new cargas;
    inv->inicio=NULL;
    return inv;
}

void adicionaCarga(cargas *inv,float peso,string carga_nome){
    No * no= _criarNo(peso,carga_nome);
 
        no->proximo=inv->inicio;

        inv->inicio=no;
   
}

void removerCarga(cargas *inv, string nome) {
    No *atual = inv->inicio;
    No *anterior = NULL;

    while (atual != NULL) {
        if (atual->nome == nome) {

            if (anterior == NULL) {
                inv->inicio = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }

            cout << "\nCarga excluida: " << atual->nome;
           delete atual; 
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    cout << "\nCarga nao encontrada.";
}