#ifndef TAD_LOGS_H
#define TAD_LOGS_H




typedef struct pilha_log{

    string log;
    pilha *anterior;

}pilha;


pilha* criarPilhaLog(){}
void pushLog(pilha *p,string l){}
void popLog(pilha *p){}




#endif