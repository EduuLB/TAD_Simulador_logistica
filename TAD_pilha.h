#ifndef TAD_PILHA_H
#define TAD_PILHA_H
using namespace std;


typedef struct NoPilha {
    string log;
    NoPilha* anterior;
} NoPilha;

typedef struct pilha{

    NoPilha* topo;

} Pilha;

Pilha* criarPilhaLog();
void pushLog(Pilha *p, string l);
void popLog(Pilha *p);

#endif 