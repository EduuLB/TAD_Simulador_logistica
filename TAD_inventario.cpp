#include <iostream>
#include <stdlib.h>
#include "TAD_inventario.h"
using namespace std;


No* _criarNo(float peso, string carga_nome) {
    No* no = (No*)calloc(1, sizeof(No));
    no->peso = peso;
    string nome = carga_nome;
    no->proximo = NULL;
    return no;
}

cargas* criarInventario(){
    cargas *inv = (cargas*)calloc(1,sizeof(cargas));
    inv->inicio=NULL;
    return inv;
}

void adicionaCarga(cargas *inv,float peso,string garga_nome){
    No * no= _criarNo(peso,garga_nome);
 
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
            free(atual); 
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    cout << "\nCarga nao encontrada.";
}