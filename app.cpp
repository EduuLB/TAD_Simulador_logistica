#include <iostream>
#include "TAD_ListaEstatica.h"
#include "TAD_ListaSimples.h"
#include "TAD_ListaDupla.h"
#include "TAD_ListaCircular.h"
#include "TAD_pilha.h"
#include "TAD_fila.h"
using namespace std;

//Main ListaEstatica
/*
int main(){

    ListaSensores sensores;
    inicializarSensores(sensores);

    int opcao;
    int id;

    do{
        cout << "\n===== SETOR DE SENSORES =====\n";
        cout << "1 - Inserir sensor\n";
        cout << "2 - Remover sensor\n";
        cout << "3 - Mostrar sensores\n";
        cout << "4 - Encerrar sistema\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch(opcao){

            case 1:
                cout << "Digite o ID do sensor: ";
                cin >> id;
                inserirSensor(sensores, id);
                break;

            case 2:
                cout << "Digite o ID do sensor para remover: ";
                cin >> id;
                removerSensor(sensores, id);
                break;

            case 3:
                cout << "Sensores ativos: ";
                mostrarSensores(sensores);
                break;

            case 4:
                cout << "Encerrando sistema...\n";
                break;

            default:
                cout << "Opcao invalida!\n";
        }

    } while(opcao != 4);

    return 0;
}
*/

// Main Lista SImples
/*
int main() {
    ListaSimples *lista = criarListaSimples();

    int opcao;
    int valor;

    do {
        cout << "\n===== INVENTARIO DE CARGAS =====\n";
        cout << "1 - Inserir carga\n";
        cout << "2 - Remover carga\n";
        cout << "3 - Exibir cargas\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch(opcao) {

            case 1:
                cout << "Digite o valor da carga: ";
                cin >> valor;
                inserirCarga(lista, valor);
                break;

            case 2:
                cout << "Digite o valor a remover: ";
                cin >> valor;
                removerCarga(lista, valor);
                break;

            case 3:
                exibirCarga(lista);
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

// Main Lista Dupla
/*
int main(){
    Nave *n = criarNave();

    int opcao;
    string nome;

    do {
        cout << "\n===== HISTORICO DE NAVES =====\n";
        cout << "1 - Inserir nave\n";
        cout << "2 - Remover nave\n";
        cout << "3 - Mostrar naves\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        cin.ignore();

        switch(opcao){

            case 1:
                cout << "Digite o nome da nave: ";
                cin >> nome;
                inserirNave(nome, n);
                break;

            case 2:
                cout << "Digite o nome da nave a remover: ";
                cin >> nome;
                removerNave(n, nome);
                break;

            case 3: {
                NoDuplo *aux = n->head;
                cout << "\n--- NAVES ---\n";
                while(aux != NULL){
                    cout << aux->nome << " <-> ";
                    aux = aux->proximo;
                }
                cout << "NULL\n";
                break;
            }

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

// Main Circular
/*
int main(){
    ListaCircular *lista = criarListaCircular();

    int opcao;
    string nome;

    do{
        cout << "\n===== MONITORAMENTO (LISTA CIRCULAR) =====\n";
        cout << "1 - Inserir camera\n";
        cout << "2 - Remover camera\n";
        cout << "3 - Exibir cameras\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        cin.ignore();

        switch(opcao){

            case 1:
                cout << "Nome da camera: ";
                getline(cin, nome);
                inserirCamera(lista, nome);
                break;

            case 2:
                cout << "Nome da camera a remover: ";
                getline(cin, nome);
                removerCamera(lista, nome);
                break;

            case 3:
                exibirCircular(lista);
                break;

            case 0:
                cout << "Encerrando...\n";
                break;

            default:
                cout << "Opcao invalida\n";
        }

    }while(opcao != 0);

    return 0;
}
*/

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
