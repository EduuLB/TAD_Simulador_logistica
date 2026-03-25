#ifndef TAD_LISTASIMPLES_H
#define TAD_LISTASIMPLES_H

typedef struct {
    int valor;
    No *proximo;
} No;

typedef struct {
    No *inicio;
    No *final;
} Lista;

Lista criarLista();
No criarNo(Lista lista, int valor);
void inserirCarga(Lista lista, int valor);
void removerCarga(Lista lista, int valor);

#endif