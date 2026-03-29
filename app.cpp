#include <iostream>
#include "TAD_pilha.h"

using namespace std;

int main() {
    Pilha *logs = criarPilhaLog();

    int opcao;
    string mensagem;

    do {
        cout << "\n===== CENTRAL DE LOGS =====\n";
        cout << "1 - Adicionar log\n";
        cout << "2 - Remover log\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        cin.ignore();

        switch(opcao) {
            case 1:
                cout << "Digite a mensagem do log: ";
                cin >> mensagem;
                pushLog(logs, mensagem);
                break;

            case 2:
                popLog(logs);
                break;

            case 0:
                cout << "Encerrando...\n";
                break;

            default:
                cout << "Opcao invalida!\n";
        }

    } while(opcao != 0);

    return 0;
}