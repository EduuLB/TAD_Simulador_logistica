#ifndef TAD_LISTASIMPLES_H
#define TAD_LISTASIMPLES_H

struct NoSimples{
    int valor;
    NoSimples *proximo;
};

struct ListaSimples{
    NoSimples *inicio;
    NoSimples *final;
};

ListaSimples* criarListaSimples();
NoSimples* criarNoSimples(int valor);
void inserirCarga(ListaSimples *listaSimples, int valor);
void removerCarga(ListaSimples *listaSimples, int valor);
void exibirCarga(ListaSimples *listaSimples);
#endif