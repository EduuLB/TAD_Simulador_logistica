    #include <iostream>
    #include <stdlib.h>
    #include <string>
    #ifndef FILA_H
    #define FILA_H

    typedef struct No{
        No *prox;
        int id;
    }No;

    typedef struct fila_hangar{
        No *inicio;
        No *fim;
    }fila;

    fila* criarFila(){}
    void enqueue(int id,fila *f){}
    void dequeue(){}


    #endif