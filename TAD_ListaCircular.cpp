#include <iostream>
#include "TAD_ListaCircular.h"
using namespace std;

ListaCircular* criarListaCircular(){
    ListaCircular *lista = new ListaCircular;
    lista->inicio = NULL;
    return lista;
}

void inserirCamera(ListaCircular *lista, string nome){
    NoCircular *novo = new NoCircular;
    novo->nome = nome;//pega nome e poe no nó

    // lista vazia
    if(lista->inicio == NULL){
        lista->inicio = novo;//importante, o primeiro a sair e sempre o 1 entao
        //o inicio sempre aponta para o primeiro
        novo->proximo = novo; // aponta pra si mesmo depois da volta ja que so tem ele
    }
    else{
        NoCircular *aux = lista->inicio;//no auiliar aponta para o inicio

        // vai até o último
        while(aux->proximo != lista->inicio){//vai correr ate encontrar alguem que o proximo
            //seja o inicio da fila se achar sai do llop
            
            aux = aux->proximo;//auxiliar pega o proximo da fula se enquanto for diferente do
            //inicio que e onde volta o "loop" 
        }
        // ao sair , ou encontrar um que o proximo aponta pro inicio
        aux->proximo = novo; //o auxiliar proximo aponta para o endereco do novo no e nao
        //para o inicio do circulo

        novo->proximo = lista->inicio;//o proximo do no aponta para o inicio da lista de novo
        //fechando o circulo
    }

    cout << "Camera " << nome << " inserida\n";
}

void removerCamera(ListaCircular *lista, string nome){
    if(lista->inicio == NULL){
        cout << "Lista vazia\n";
        return;
    }

    NoCircular *atual = lista->inicio;
    NoCircular *anterior = NULL;

    do {
        if(atual->nome == nome){

            // único elemento
            if(atual == lista->inicio && atual->proximo == lista->inicio){
                lista->inicio = NULL;
            }
            // removendo o primeiro
            else if(atual == lista->inicio){
                NoCircular *ultimo = lista->inicio;//cria um ponteiro de fila so pra guardar o inicio


                while(ultimo->proximo != lista->inicio){//repeticao entauqnto nao achar o prox
                    //do ultimo igual ao inicio (fechando o circulo)
                    ultimo = ultimo->proximo;//pega proximo ponteiro para percorrer ate sair do loop
                }

                lista->inicio = atual->proximo;//inicio aponta o segundo da lista
                ultimo->proximo = lista->inicio;//o proximo do ultimo aponta pro inicio agora
                //fechando o circulp
            }
            else{
                anterior->proximo = atual->proximo;//remove o que estiver no meio deixando~
                //o atual ligado a porra nenhuma skks o anterior apontando pro porximo dele
            }

            delete atual;//apagando esse nada
            cout << "Camera removida\n";
            return;
        }

        anterior = atual;// 1. O 'anterior' assume o lugar onde o 'atual' está agora.
          // 2. O 'atual' pula para a próxima porta (o endereço guardado no 'proximo').
          //peguei essa do chat msm
        atual = atual->proximo;
    } while(atual != lista->inicio);

    cout << "Camera nao encontrada\n";
}

void exibirCircular(ListaCircular *lista){
    if(lista->inicio == NULL){
        cout << "Lista vazia\n";
        return;
    }

    NoCircular *aux = lista->inicio;

    cout << "\n--- CAMERAS ---\n";

    do {
        cout << aux->nome << " -> ";
        aux = aux->proximo;
    } while(aux != lista->inicio);
}