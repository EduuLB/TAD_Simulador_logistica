#include <iostream>
// #include "TAD_pilha.h"
#include "TAD_fila.h"
using namespace std;
//Main Pilha
/*
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
*/

//Main Fila
/*
int main(){

    Fila *hangar = criarFila();

    int opcao;
    int id;

    do{
        cout << "\n===== CONTROLE DO HANGAR =====\n";
        cout << "1 - Entrada de aviao (enqueue)\n";
        cout << "2 - Saida de aviao (dequeue)\n";
        cout << "0 - Encerrar sistema\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch(opcao){

            case 1:
                cout << "Digite o ID do aviao: ";
                cin >> id;
                enqueue(hangar, id);
                break;

            case 2:
                dequeue(hangar);
                break;

            case 0:
                cout << "Encerrando sistema...\n";
                break;

            default:
                cout << "Opcao invalida!\n";
        }

    } while(opcao != 0);

    return 0;
}
*/

