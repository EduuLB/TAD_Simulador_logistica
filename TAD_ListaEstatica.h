#ifndef TAD_LISTAESTATICA_H
#define TAD_LISTAESTATICA_H

#define MAX 5

struct Sensor {
    int id;
};

struct ListaSensores {
    Sensor dados[MAX];
    int tamanho;
};

void inicializarSensores(ListaSensores &lista);
void inserirSensor(ListaSensores &lista, int id);
void removerSensor(ListaSensores &lista, int id);
void mostrarSensores(ListaSensores &lista);

#endif