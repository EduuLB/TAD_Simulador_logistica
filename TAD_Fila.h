    #include <iostream>
    #include <stdlib.h>
    #include <string>
    #ifndef TAD_FILA_H
    #define TAD_FILA_H

    struct NoFila{
        NoFila *prox;
        int id;
    };

    struct Fila {
        NoFila *inicio;
        NoFila *fim;
    };

    Fila* criarFila();
    void enqueue(Fila *f, int id);
    void dequeue(Fila *f);


    #endif