#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

typedef struct No {
    string log;
    struct No* anterior;
} No;

typedef struct pilha {
    No* topo;
} pilha;

pilha* criarpilhaLog() {
    pilha *p = new pilha;
    if (p != NULL) {
        p->topo = NULL; 
    }
    return p;
}

void pushLog(pilha *p, string l) {
    if (p == NULL) return;

    No* novo = new No;
    if (novo != NULL) {
        novo->log = l;
        novo->anterior = p->topo; // O novo aponta para o antigo topo
        p->topo = novo;           // O topo da pilha agora é o novo nó
        cout << "Log empilhado: " << l << "\n";
    }
}

void popLog(pilha *p) {
    if (p == NULL || p->topo == NULL) {
        cout << "Pilha vazia\n";
    } else {
        No* aux = p->topo;
        p->topo = p->topo->anterior;
        cout << "Valor desempilhado: " << aux->log << "\n";
        delete aux; 
    }
}