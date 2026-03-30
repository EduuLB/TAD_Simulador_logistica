#include <iostream>
#include "TAD_ListaEstatica.h"
using namespace std;

void inicializarSensores(ListaSensores &lista){
    lista.tamanho = 0;
}

void inserirSensor(ListaSensores &lista, int id){
    if(lista.tamanho < MAX){
        lista.dados[lista.tamanho].id = id;
        lista.tamanho++;
    } else {
        cout << "Lista cheia\n";
    }
}

void removerSensor(ListaSensores &lista, int id){
    int pos = -1;

    for(int i = 0; i < lista.tamanho; i++){
        if(lista.dados[i].id == id){
            pos = i;
            break;
        }
    }

    if(pos != -1){
        for(int i = pos; i < lista.tamanho - 1; i++){
            lista.dados[i] = lista.dados[i+1];
        }

        lista.tamanho--;

        cout << "Sensor removido com sucesso\n";
    } else {
        cout << "Sensor nao encontrado\n";
    }
}

void mostrarSensores(ListaSensores &lista){
    for(int i = 0; i < lista.tamanho; i++){
        cout << lista.dados[i].id << " ";
    }
    cout << endl;
}