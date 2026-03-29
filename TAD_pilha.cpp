#include <iostream>
#include <stdlib.h>
#include <string>
#include "TAD_pilha.h"

using namespace std;

Pilha* criarPilhaLog() {
    Pilha *p = new Pilha;
    p->topo = NULL;
    return p;
}

void pushLog(Pilha *p, string l) {
    if (p == NULL) return;

    No* novo = new No;
    novo->log = l;
    novo->anterior = p->topo;

    p->topo = novo;

    cout << "Log empilhado: " << l << "\n";
}

void popLog(Pilha *p) {
    if (p == NULL || p->topo == NULL) {
        cout << "Pilha vazia\n";
        return;
    }

    No* aux = p->topo;
    p->topo = aux->anterior;

    cout << "Valor desempilhado: " << aux->log << "\n";

    delete aux;
}