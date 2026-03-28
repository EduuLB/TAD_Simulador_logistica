#include <iostream>
#include <stdlib.h>
#include <string.h>
#ifndef INVENTARIO_H
#define INVENTARIO_H

typedef struct No{

    float peso;
    int id;
    No *proximo;

}No;
typedef struct Lista{

    No *inicio;
    
}cargas;

No* _criarNo(float peso,String carga_nome) {
    
}

cargas* criarInventario(){
}

void adicionaCarga(){}


#endif