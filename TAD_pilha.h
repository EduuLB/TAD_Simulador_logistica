#ifndef TAD_PILHA_H
#define TAD_PILHA_H
using namespace std;


typedef struct No {
    string log;
    No* anterior;
} No;

typedef struct pilha_log{

    No* topo;

} Pilha;

Pilha* criarPilhaLog();
void pushLog(Pilha *p, string l);
void popLog(Pilha *p);

#endif