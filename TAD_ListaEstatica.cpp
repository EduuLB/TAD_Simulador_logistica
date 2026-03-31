#include <iostream>
#include "TAD_ListaEstatica.h"
using namespace std;

void inicializarSensores(ListaSensores &lista){//trabalhamos com &para pegar um vetor que e segmenetadi
    //ou seja pega a primeira posicao
    lista.tamanho = 0;
}

void inserirSensor(ListaSensores &lista, int id){
    if(lista.tamanho < MAX){//caso o tamonho for menor que o maximo
        lista.dados[lista.tamanho].id = id;//pega  os dados na lista na posicao do tamanho
        //e adciona o id
        lista.tamanho++;//sobe o tamanho em 1 ate que fique cheia
    } else {
        cout << "Lista cheia\n";
    }
}

void removerSensor(ListaSensores &lista, int id){
    int pos = -1;

    for(int i = 0; i < lista.tamanho; i++){
        if(lista.dados[i].id == id){//fpr procura o id no indice ate achar o id
            pos = i;//posicao recebe indice e 
            break;
        }
    }

    if(pos != -1){//caso nao for vazio
        for(int i = pos; i < lista.tamanho - 1; i++){//enquanto indice do tamanho da posicao
            //for menor q o tamanho -1 indice sobe
            lista.dados[i] = lista.dados[i+1];//indice da lista sobe mais um
        }

        lista.tamanho--;//remove 1 do tamanho sensor

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